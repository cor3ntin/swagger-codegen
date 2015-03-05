#ifndef _SWAGGER_UTILS_
#define _SWAGGER_UTILS_

#include <utility>
#include <tuple>
#include <functional>
#include <type_traits>
#include <boost/optional/optional.hpp>
#include <QHttpMultiPart>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
#include <QLoggingCategory>
#include <QMimeDatabase>
class QIODevice;

namespace swagger {

Q_DECLARE_LOGGING_CATEGORY(swagger_lc);

#define logSwaggerError(...) qCCritical(swagger_lc, __VA_ARGS__)
#define logSwaggerWarning(...) qCWarning(swagger_lc, __VA_ARGS__)
#define logSwaggerTrace(...) qCDebug(swagger_lc, __VA_ARGS__)

template <typename T>
inline QString to_query_value(const T & t) { return QVariant::fromValue<T>(t).toString(); }

template <>
inline QString to_query_value(const QString & t) { return t;}

template <typename T>
void set_form_data(QHttpMultiPart* & parts, const QString & k, T value) {
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QStringLiteral("form-data; name=\"%1\"").arg(k)));
    part.setBody(to_query_value(value).toUtf8());
    if(!parts)
        parts = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    parts->append(part);
}

template <>
inline void set_form_data<QIODevice*>(QHttpMultiPart* & parts, const QString & k, QIODevice* value) {
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant(QMimeDatabase().mimeTypeForData(value).name()));
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QStringLiteral("form-data; name=\"%1\"").arg(k)));
    part.setBodyDevice(value);
    if(!parts)
        parts = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    parts->append(part);
}

template <typename T>
struct Sender {
private:
    T* m_sender;
public:
    Sender(T* sender) : m_sender(sender) {}

    //non copiable
    Sender(const Sender<T> &) = delete;
    Sender(Sender<T> && other) {
        m_sender = other.m_sender;
        other.m_sender = 0;
    }

    Sender<T> & operator=(const Sender<T> & other) = delete;
    Sender<T> & operator=(Sender<T> && other) = delete;

    ~Sender() {
        m_sender->send();
    }

    T* operator ->() {
        return m_sender;
    }

    operator T*()  {
        return m_sender;
    }
};


template <typename T>
struct is_model : std::false_type {};

template <typename T>
struct is_enum : std::false_type {};

template <typename Container>
struct is_array : std::false_type { };
template <typename... Ts> struct is_array<QVector<Ts...> > : std::true_type { };
template <typename... Ts> struct is_array<QList<Ts...> > : std::true_type { };
template <> struct is_array<QStringList> : std::true_type { };


template <typename Container>
struct is_associative_array : std::false_type { };
template <typename Key, typename Value> struct is_associative_array<QHash<Key,Value> > : std::true_type { };
template <typename Key, typename Value> struct is_associative_array<QMap<Key,Value> > : std::true_type { };


template <typename T>
typename std::enable_if<std::is_same<T, bool>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return false;
    if(!value.isBool())
        return boost::optional<T>{};
    return value.toBool();
}

template <typename T>
typename std::enable_if<std::is_same<T, QString>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return T();
    if(!value.isString())
        return boost::optional<T>{};
    return value.toString();
}

template <typename T>
typename std::enable_if<std::is_same<T, QDateTime>::value || std::is_same<T, QDate>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return T();
    if(!value.isString())
        return boost::optional<T>{};
    auto d = T::fromString(value.toString(), Qt::ISODate);
    if(d.isValid())
        return d;
    return boost::optional<T>{};
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T, bool>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return T();
    if(!value.isDouble())
        return boost::optional<T>{};
    return static_cast<T>(value.toDouble());
}

template <typename Enum>
typename std::enable_if<swagger::is_enum<Enum>::value, boost::optional<Enum>>::type
unserialize(const QJsonValue & json) {
    using Class = typename is_enum<Enum>::class_name;
    const char* name = is_enum<Enum>::name;
    auto key = swagger::unserialize<QString>(json);
    if(!key) return {};
    int v = Class::staticMetaObject.enumerator(Class::staticMetaObject.indexOfEnumerator(name)).keyToValue(qPrintable(*key));
    if (v == -1) return {};
    return boost::optional<Enum>{static_cast<Enum>(v)};
}


template <typename T>
typename std::enable_if<swagger::is_model<T>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return T();
    if(!value.isObject())
        return boost::optional<T>{};
    return T::unserialize(value.toObject());
}

template <typename T>
typename std::enable_if<swagger::is_array<T>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return T();
    if(!value.isArray())
        return boost::optional<T>{};
    auto jsonArray = value.toArray();
    T array;
    array.reserve(jsonArray.size());
    for(auto && e : jsonArray) {
        auto v = swagger::unserialize<typename T::value_type>(e);
        if(!v)
            return boost::optional<T>{};
        array.append(*v);
    }
    return array;
}

template <typename T>
typename std::enable_if<swagger::is_associative_array<T>::value, boost::optional<T>>::type
unserialize(const QJsonValue & value) {
    if(value.isNull())
        return T();
    if(!value.isObject())
        return boost::optional<T>{};
    auto object = value.toObject();
    T map;
    for(auto it = std::begin(object);
        it != std::end(object); it++) {
        auto k = swagger::unserialize<typename T::key_type>(it.key());
        auto v = swagger::unserialize<typename T::mapped_type>(it.value());
        if(!v || !k)
            return boost::optional<T>{};
        map.insert(*k, *v);
    }
    return map;
}

//////////////////////////////

template <typename T>
typename std::enable_if<std::is_same<T, bool>::value, QJsonValue>::type
serialize(T value) {
    return QJsonValue(value);
}

template <typename T>
typename std::enable_if<std::is_same<T, QString>::value, QJsonValue>::type
serialize(const T & value) {
    return QJsonValue(value);
}

template <typename T>
typename std::enable_if<std::is_same<T, QDateTime>::value || std::is_same<T, QDate>::value, QJsonValue>::type
serialize(const T & value) {
    return QJsonValue(value.toString(Qt::ISODate));
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T, bool>::value, QJsonValue>::type
serialize(T value) {
    return QJsonValue(static_cast<double>(value));
}

template <typename T>
typename std::enable_if<swagger::is_model<T>::value, QJsonValue>::type
serialize(const T& value) {
    return value.serialize();
}

template <typename Enum>
typename std::enable_if<swagger::is_enum<Enum>::value, QJsonValue>::type
serialize(Enum value) {
    using Class = typename is_enum<Enum>::class_name;
    const char* name = is_enum<Enum>::name;
    return swagger::serialize<QString>(Class::staticMetaObject.enumerator
     (Class::staticMetaObject.indexOfEnumerator(name)).valueToKey((static_cast<int>(value))));
}


template <typename T>
typename std::enable_if<swagger::is_array<T>::value, QJsonValue>::type
serialize(const T& value) {
    QJsonArray array;
    for(auto && e : value) {
        array.append(swagger::serialize(e));
    }
    return array;
}

template <typename T>
typename std::enable_if<swagger::is_associative_array<T>::value, QJsonValue>::type
serialize(const T& value) {
    QJsonObject object;
    for(auto it = std::begin(value);
        it != std::end(value); it++) {

        object.insert(it.key(), swagger::serialize(it.value()));
    }
    return object;
}


namespace details {
    template <typename T>
    struct function_traits
        : public function_traits<decltype(&T::operator())>
    {};



    namespace xx_impl
    {
        template <typename C, typename R, typename... A>
        struct memfn_type
        {
            typedef typename std::conditional<
                std::is_const<C>::value,
                typename std::conditional<
                    std::is_volatile<C>::value,
                    R (C::*)(A...) const volatile,
                    R (C::*)(A...) const
                >::type,
                typename std::conditional<
                    std::is_volatile<C>::value,
                    R (C::*)(A...) volatile,
                    R (C::*)(A...)
                >::type
            >::type type;
        };
    }

    template <typename ReturnType, typename... Args>
    struct function_traits<ReturnType(Args...)>
    {
        enum { arity = sizeof...(Args) };
        using FirstArg = typename std::tuple_element<0, std::tuple<Args...>>::type;
    };
    template <typename ReturnType>
    struct function_traits<ReturnType()>
    {
        enum { arity = 0 };
    };


    template <typename ReturnType, typename... Args>
    struct function_traits<ReturnType(*)(Args...)>
        : public function_traits<ReturnType(Args...)>
    {};

    template <typename ClassType, typename ReturnType, typename... Args>
    struct function_traits<ReturnType(ClassType::*)(Args...)>
        : public function_traits<ReturnType(Args...)>
    {};

    template <typename ClassType, typename ReturnType, typename... Args>
    struct function_traits<ReturnType(ClassType::*)(Args...) const>
        : public function_traits<ReturnType(Args...)>
    {};

    template <typename ClassType, typename ReturnType, typename... Args>
    struct function_traits<ReturnType(ClassType::*)(Args...) volatile>
        : public function_traits<ReturnType(Args...)>
    {};

    template <typename ClassType, typename ReturnType, typename... Args>
    struct function_traits<ReturnType(ClassType::*)(Args...) const volatile>
        : public function_traits<ReturnType(Args...)>
    {};

    template <typename FunctionType>
    struct function_traits<std::function<FunctionType>>
        : public function_traits<FunctionType>
    {};

    template <typename T>
    struct function_traits<T&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<const T&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<volatile T&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<const volatile T&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<T&&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<const T&&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<volatile T&&> : public function_traits<T> {};
    template <typename T>
    struct function_traits<const volatile T&&> : public function_traits<T> {};

    template <typename T>
    struct remove_cr {
        using type = T;
    };
    template <typename T>
    struct remove_cr<const T&> {
        using type = T;
    };


    template <int N, typename T1, typename T2>
    struct is_convertible : std::integral_constant<bool, false>
    {};
    template <typename T1, typename T2>
    struct is_convertible<1, T1,T2> : std::integral_constant<bool,
        std::is_same<T1,
            typename remove_cr<typename function_traits<T2>::FirstArg>::type
            >::value>
    {};

    template <typename T1, typename T2>
    struct is_convertible<0, T1,T2>  : std::integral_constant<bool, true>
    {};

    template <typename Func, typename P>
    struct slot_match  : std::integral_constant<bool, is_convertible<function_traits<Func>::arity, P, Func>::value>
    {};
}

}

#define SWAGGER_SMART_SLOT(Api, Type, HttpCode)                                             \
template <typename Func>                                                                     \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && Api ## RequestDetails::Arities::success == 1                                          \
    && Api ## RequestDetails::ResponseInfo<Type>::isSuccess::value, Api ## Request*>::type   \
onSuccess(Func func) {                                                                       \
    connect(this, &Api ## Request::finished ## HttpCode, func);                              \
    return this;                                                                             \
}                                                                                            \
template <typename Obj, typename Func>                                                       \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && Api ## RequestDetails::Arities::success == 1                                          \
    && Api ## RequestDetails::ResponseInfo<Type>::isSuccess::value, Api ## Request*>::type   \
onSuccess(Obj obj, Func func) {                                                              \
    connect(this, &Api ## Request::finished ## HttpCode, obj, func);                         \
    return this;                                                                             \
}                                                                                            \
template <typename Func>                                                                     \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && (Api ## RequestDetails::Arities::error == 1                                           \
    && !Api ## RequestDetails::ResponseInfo<Type>::isSuccess::value), Api ## Request*>::type \
onError(Func func) {                                                                         \
    connect(this, &Api ## Request::finished ## HttpCode, func);                              \
    return this;                                                                             \
}                                                                                            \
template <typename Obj,typename Func>                                                        \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && (Api ## RequestDetails::Arities::error == 1                                           \
    && !Api ## RequestDetails::ResponseInfo<Type>::isSuccess::value), Api ## Request*>::type \
onError(Obj obj, Func func) {                                                                \
    connect(this, &Api ## Request::finished ## HttpCode, obj, func);                         \
    return this;                                                                             \
}                                                                                            \
template <typename Func>                                                                     \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && (Api ## RequestDetails::ResponseInfo<Type>::isDefault::value                          \
       || Api ## RequestDetails::Arities::total == 1), Api ## Request*>::type                \
onFinished(Func func) {                                                                      \
    connect(this, &Api ## Request::finished  ## HttpCode, func);                             \
    return this;                                                                             \
}                                                                                            \
template <typename Obj, typename Func>                                                       \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && (Api ## RequestDetails::ResponseInfo<Type>::isDefault::value                          \
       || Api ## RequestDetails::Arities::total == 1), Api ## Request*>::type                \
onFinished(Obj obj, Func func) {                                                             \
    connect(this, &Api ## Request::finished  ## HttpCode, obj, func);                        \
    return this;                                                                             \
}                                                                                            \
template <typename Func>                                                                     \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && !Api ## RequestDetails::ResponseInfo<Type>::isDefault::value, Api ## Request*>::type  \
on ## HttpCode (Func func) {                                                                 \
    connect(this, &Api ## Request::finished  ## HttpCode, func);                             \
    return this;                                                                             \
}                                                                                            \
template <typename Obj, typename Func>                                                       \
typename std::enable_if<details::slot_match<Func,Type>::value                                \
    && !Api ## RequestDetails::ResponseInfo<Type>::isDefault::value, Api ## Request*>::type  \
on ## HttpCode (Obj obj, Func func) {                                                        \
    connect(this, &Api ## Request::finished  ## HttpCode, obj, func);                        \
    return this;                                                                             \
}

#define SWAGGER_DECLARE_MODEL(m) template <> struct is_model<m> : std::true_type {}

#define SWAGGER_DECLARE_ENUM(o,e)\
template <>\
struct is_enum<o::e> : std::true_type {\
    static const char* const name;\
    using class_name = o;\
}

#define SWAGGER_REGISTER_ENUM(o,e) const char* const swagger::is_enum<o::e>::name = "#e";                                                                                               \





#endif