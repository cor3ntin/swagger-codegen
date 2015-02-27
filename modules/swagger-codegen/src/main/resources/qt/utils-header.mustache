#ifndef _SWAGGER_UTILS_
#define _SWAGGER_UTILS_

#include <utility>
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
using Optional = boost::optional<T>;

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

template <typename Container>
struct is_array : std::false_type { };
template <typename... Ts> struct is_array<QVector<Ts...> > : std::true_type { };
template <> struct is_array<QStringList> : std::true_type { };


template <typename Container>
struct is_associative_array : std::false_type { };
template <typename Key, typename Value> struct is_associative_array<QHash<Key,Value> > : std::true_type { };
template <typename Key, typename Value> struct is_associative_array<QMap<Key,Value> > : std::true_type { };


template <typename T>
typename std::enable_if<std::is_same<T, bool>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isBool())
        return {};
    return value.toBool();
}

template <typename T>
typename std::enable_if<std::is_same<T, QString>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isString())
        return {};
    return value.toString();
}

template <typename T>
typename std::enable_if<std::is_same<T, QDateTime>::value || std::is_same<T, QDate>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isString())
        return {};
    auto d = T::fromString(value.toString(), Qt::ISODate);
    if(d.isValid())
        return d;
    return {};
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T, bool>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isDouble())
        return {};
    return static_cast<T>(value.toDouble());
}

template <typename T>
typename std::enable_if<std::is_same<Optional<T>, decltype(T::unserialize(QJsonObject()))>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isObject())
        return {};
    return T::unserialize(value.toObject());
}

template <typename T>
typename std::enable_if<swagger::is_array<T>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isArray())
        return {};
    auto jsonArray = value.toArray();
    T array;
    array.reserve(jsonArray.size());
    for(auto && e : jsonArray) {
        auto v = swagger::unserialize<typename T::value_type>(e);
        if(!v)
            return {};
        array.append(*v);
    }
    return array;
}

template <typename T>
typename std::enable_if<swagger::is_associative_array<T>::value, Optional<T>>::type
unserialize(const QJsonValue & value) {
    if(!value.isObject())
        return {};
    auto object = value.toObject();
    T map;
    for(auto it = std::begin(object);
        it != std::end(object); it++) {
        auto k = swagger::unserialize<typename T::key_type>(it.key());
        auto v = swagger::unserialize<typename T::mapped_type>(it.value());
        if(!v || !k)
            return {};
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
typename std::enable_if<std::is_same<QJsonObject, decltype(T().serialize())>::value, QJsonValue>::type
serialize(const T& value) {
    return value.serialize();
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

}

#endif