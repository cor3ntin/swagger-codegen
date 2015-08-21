#ifndef AK_SWAGGER_StoreApi_H_
#define AK_SWAGGER_StoreApi_H_

#include <QHash>
#include "Order.h"
#include <QString>
#include <type_traits>
#include "AbstractRequest.h"
#include "ApiInvoker.h"
#include "SwaggerUtils.h"

class QNetworkReply;

namespace swagger {

namespace StoreApi {

namespace responses {

    class getInventoryRequest;
    class placeOrderRequest;
    class getOrderByIdRequest;
    class deleteOrderRequest;
}

namespace operations {
//Requires authentification with scheme api_key (apiKey)
Sender<responses::getInventoryRequest> getInventory(AbstractApiInvoker* invoker);

Sender<responses::placeOrderRequest> placeOrder(AbstractApiInvoker* invoker,
                boost::optional<Order> body = {} );

Sender<responses::getOrderByIdRequest> getOrderById(AbstractApiInvoker* invoker,
                const QString& orderId);

Sender<responses::deleteOrderRequest> deleteOrder(AbstractApiInvoker* invoker,
                const QString& orderId);

}


namespace responses {
namespace getInventoryRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<QHash<QString, qint32>> {
        enum { code = 200 };
        using isDefault = std::integral_constant<bool, 200 == 0>;
        using isSuccess = std::integral_constant<bool, (200 >= 200 && 200 < 400)>;
    };
    
    namespace details {
        template <typename... Args> struct Count;
        template <>
        struct Count<> {
            using success  = std::integral_constant<int, 0>;
            using failure  = std::integral_constant<int, 0>;
        };

        template <typename A1>
        struct Count<A1> {
            using success  = typename std::integral_constant<int, ((ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
            using failure  = typename std::integral_constant<int, ((!ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
        };

        template <typename A1, typename A2, typename... Args>
        struct Count<A1, A2, Args...> {
            using success  = std::integral_constant<int, Count<Args...>::success::value
                + Count<A1>::success::value + Count<A2>::success::value  >;
            using failure  = typename std::integral_constant<int, Count<Args...>::failure::value
                + Count<A1>::failure::value + Count<A2>::failure::value  >;
        };
        template <typename... Args>
        struct Arities {
            enum  {
                total = sizeof...(Args),
                success = Count<Args...>::success::value,
                error = Count<Args...>::failure::value,
            };
            using hasDefault = std::integral_constant<bool, total != success+error>;

        };
    }
    using Arities = details::Arities<QHash<QString, qint32>>;
}
namespace placeOrderRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<Order> {
        enum { code = 200 };
        using isDefault = std::integral_constant<bool, 200 == 0>;
        using isSuccess = std::integral_constant<bool, (200 >= 200 && 200 < 400)>;
    };
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 400 };
        using isDefault = std::integral_constant<bool, 400 == 0>;
        using isSuccess = std::integral_constant<bool, (400 >= 200 && 400 < 400)>;
    };
    
    namespace details {
        template <typename... Args> struct Count;
        template <>
        struct Count<> {
            using success  = std::integral_constant<int, 0>;
            using failure  = std::integral_constant<int, 0>;
        };

        template <typename A1>
        struct Count<A1> {
            using success  = typename std::integral_constant<int, ((ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
            using failure  = typename std::integral_constant<int, ((!ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
        };

        template <typename A1, typename A2, typename... Args>
        struct Count<A1, A2, Args...> {
            using success  = std::integral_constant<int, Count<Args...>::success::value
                + Count<A1>::success::value + Count<A2>::success::value  >;
            using failure  = typename std::integral_constant<int, Count<Args...>::failure::value
                + Count<A1>::failure::value + Count<A2>::failure::value  >;
        };
        template <typename... Args>
        struct Arities {
            enum  {
                total = sizeof...(Args),
                success = Count<Args...>::success::value,
                error = Count<Args...>::failure::value,
            };
            using hasDefault = std::integral_constant<bool, total != success+error>;

        };
    }
    using Arities = details::Arities<Order,void>;
}
namespace getOrderByIdRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 404 };
        using isDefault = std::integral_constant<bool, 404 == 0>;
        using isSuccess = std::integral_constant<bool, (404 >= 200 && 404 < 400)>;
    };
    
    
    template  <>
    struct ResponseInfo<Order> {
        enum { code = 200 };
        using isDefault = std::integral_constant<bool, 200 == 0>;
        using isSuccess = std::integral_constant<bool, (200 >= 200 && 200 < 400)>;
    };
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 400 };
        using isDefault = std::integral_constant<bool, 400 == 0>;
        using isSuccess = std::integral_constant<bool, (400 >= 200 && 400 < 400)>;
    };
    
    namespace details {
        template <typename... Args> struct Count;
        template <>
        struct Count<> {
            using success  = std::integral_constant<int, 0>;
            using failure  = std::integral_constant<int, 0>;
        };

        template <typename A1>
        struct Count<A1> {
            using success  = typename std::integral_constant<int, ((ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
            using failure  = typename std::integral_constant<int, ((!ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
        };

        template <typename A1, typename A2, typename... Args>
        struct Count<A1, A2, Args...> {
            using success  = std::integral_constant<int, Count<Args...>::success::value
                + Count<A1>::success::value + Count<A2>::success::value  >;
            using failure  = typename std::integral_constant<int, Count<Args...>::failure::value
                + Count<A1>::failure::value + Count<A2>::failure::value  >;
        };
        template <typename... Args>
        struct Arities {
            enum  {
                total = sizeof...(Args),
                success = Count<Args...>::success::value,
                error = Count<Args...>::failure::value,
            };
            using hasDefault = std::integral_constant<bool, total != success+error>;

        };
    }
    using Arities = details::Arities<void,Order,void>;
}
namespace deleteOrderRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 404 };
        using isDefault = std::integral_constant<bool, 404 == 0>;
        using isSuccess = std::integral_constant<bool, (404 >= 200 && 404 < 400)>;
    };
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 400 };
        using isDefault = std::integral_constant<bool, 400 == 0>;
        using isSuccess = std::integral_constant<bool, (400 >= 200 && 400 < 400)>;
    };
    
    namespace details {
        template <typename... Args> struct Count;
        template <>
        struct Count<> {
            using success  = std::integral_constant<int, 0>;
            using failure  = std::integral_constant<int, 0>;
        };

        template <typename A1>
        struct Count<A1> {
            using success  = typename std::integral_constant<int, ((ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
            using failure  = typename std::integral_constant<int, ((!ResponseInfo<A1>::isSuccess::value && !ResponseInfo<A1>::isDefault::value) ? 1 : 0)>;
        };

        template <typename A1, typename A2, typename... Args>
        struct Count<A1, A2, Args...> {
            using success  = std::integral_constant<int, Count<Args...>::success::value
                + Count<A1>::success::value + Count<A2>::success::value  >;
            using failure  = typename std::integral_constant<int, Count<Args...>::failure::value
                + Count<A1>::failure::value + Count<A2>::failure::value  >;
        };
        template <typename... Args>
        struct Arities {
            enum  {
                total = sizeof...(Args),
                success = Count<Args...>::success::value,
                error = Count<Args...>::failure::value,
            };
            using hasDefault = std::integral_constant<bool, total != success+error>;

        };
    }
    using Arities = details::Arities<void,void>;
}

class getInventoryRequest : public AbstractRequest {
    Q_OBJECT
public:
    getInventoryRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);
    getInventoryRequest* setRawHeader(const QByteArray & k, const QByteArray & v) {
        AbstractRequest::setRawHeader(k, v);
        return this;
    }

Q_SIGNALS:
    void finished200(QHash<QString, qint32>);

public:
    SWAGGER_SMART_SLOT(getInventory,QHash<QString, qint32>, 200)
    template <typename... Args>
    getInventoryRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    getInventoryRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class placeOrderRequest : public AbstractRequest {
    Q_OBJECT
public:
    placeOrderRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);
    placeOrderRequest* setRawHeader(const QByteArray & k, const QByteArray & v) {
        AbstractRequest::setRawHeader(k, v);
        return this;
    }

Q_SIGNALS:
    void finished200(Order);
    void finished400();

public:
    SWAGGER_SMART_SLOT(placeOrder,Order, 200)
    SWAGGER_SMART_SLOT(placeOrder,void, 400)
    template <typename... Args>
    placeOrderRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    placeOrderRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class getOrderByIdRequest : public AbstractRequest {
    Q_OBJECT
public:
    getOrderByIdRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);
    getOrderByIdRequest* setRawHeader(const QByteArray & k, const QByteArray & v) {
        AbstractRequest::setRawHeader(k, v);
        return this;
    }

Q_SIGNALS:
    void finished404();
    void finished200(Order);
    void finished400();

public:
    SWAGGER_SMART_SLOT(getOrderById,void, 404)
    SWAGGER_SMART_SLOT(getOrderById,Order, 200)
    SWAGGER_SMART_SLOT(getOrderById,void, 400)
    template <typename... Args>
    getOrderByIdRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    getOrderByIdRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class deleteOrderRequest : public AbstractRequest {
    Q_OBJECT
public:
    deleteOrderRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);
    deleteOrderRequest* setRawHeader(const QByteArray & k, const QByteArray & v) {
        AbstractRequest::setRawHeader(k, v);
        return this;
    }

Q_SIGNALS:
    void finished404();
    void finished400();

public:
    SWAGGER_SMART_SLOT(deleteOrder,void, 404)
    SWAGGER_SMART_SLOT(deleteOrder,void, 400)
    template <typename... Args>
    deleteOrderRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    deleteOrderRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

} //namespace responses

} //namespace StoreApi

} //namespace swagger

#endif /* StoreApi_H_ */