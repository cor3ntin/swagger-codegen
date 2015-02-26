#ifndef AK_SWAGGER_StoreApi_H_
#define AK_SWAGGER_StoreApi_H_

#include <QHash>
#include "Order.h"
#include <QString>
#include "AbstractResponse.h"
#include "ApiInvoker.h"

class QNetworkReply;

namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

namespace StoreApi {

namespace responses {

    class getInventoryResponse;
    class placeOrderResponse;
    class getOrderByIdResponse;
    class deleteOrderResponse;
}


responses::getInventoryResponse* getInventory(AbstractApiInvoker* invoker);

responses::placeOrderResponse* placeOrder(AbstractApiInvoker* invoker,
                Optional<Order> body = {} );

responses::getOrderByIdResponse* getOrderById(AbstractApiInvoker* invoker,
                const QString& orderId);

responses::deleteOrderResponse* deleteOrder(AbstractApiInvoker* invoker,
                const QString& orderId);



namespace responses {

class getInventoryResponse : public AbstractResponse {

public:
    getInventoryResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    getInventoryResponse* onEmptyResponse(std::function<void(int)>);
    getInventoryResponse* on(const std::function<void(QHash<QString, qint32>)> & callback);

protected:
    bool processResponse(int status, const QJsonValue & data);

private:
    std::function<void(QHash<QString, qint32>)> m_200_fun;
};

class placeOrderResponse : public AbstractResponse {

public:
    placeOrderResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    placeOrderResponse* onEmptyResponse(std::function<void(int)>);
    placeOrderResponse* on(const std::function<void(Order)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:
    std::function<void(Order)> m_200_fun;

};

class getOrderByIdResponse : public AbstractResponse {

public:
    getOrderByIdResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    getOrderByIdResponse* onEmptyResponse(std::function<void(int)>);

    getOrderByIdResponse* on(const std::function<void(Order)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

    std::function<void(Order)> m_200_fun;

};

class deleteOrderResponse : public AbstractResponse {

public:
    deleteOrderResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    deleteOrderResponse* onEmptyResponse(std::function<void(int)>);



protected:
    bool processResponse(int status, const QJsonValue & data);

private:


};

} //namespace responses

} //namespace StoreApi

} //namespace swagger

#endif /* StoreApi_H_ */