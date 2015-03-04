#include "StoreApi.h"

#include <QUrlQuery>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "SwaggerUtils.h"

namespace swagger {

namespace StoreApi {

namespace responses {

getInventoryResponse::getInventoryResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

getInventoryResponse* getInventoryResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


getInventoryResponse* getInventoryResponse::on(const std::function<void(QHash<QString, qint32>)> & callback) {
    m_200_fun = callback;
    return this;
}

bool getInventoryResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 200  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 200:{  //QHash<QString, qint32>
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for QHash<QString, qint32> - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<QHash<QString, qint32>>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QHash<QString, qint32>");
                return false;
            }
            m_200_fun(*value);
            
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

placeOrderResponse::placeOrderResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

placeOrderResponse* placeOrderResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


placeOrderResponse* placeOrderResponse::on(const std::function<void(Order)> & callback) {
    m_200_fun = callback;
    return this;
}

bool placeOrderResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 200:{  //Order
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for Order - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<Order>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize Order");
                return false;
            }
            m_200_fun(*value);
            
        }
        case 400:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

getOrderByIdResponse::getOrderByIdResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

getOrderByIdResponse* getOrderByIdResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


getOrderByIdResponse* getOrderByIdResponse::on(const std::function<void(Order)> & callback) {
    m_200_fun = callback;
    return this;
}

bool getOrderByIdResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 3> knownStatus{{ 404, 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 404:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        case 200:{  //Order
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for Order - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<Order>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize Order");
                return false;
            }
            m_200_fun(*value);
            
        }
        case 400:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

deleteOrderResponse::deleteOrderResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

deleteOrderResponse* deleteOrderResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool deleteOrderResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 404, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 404:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        case 400:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

} //namespace responses

using namespace responses;


getInventoryResponse* getInventory (AbstractApiInvoker* invoker) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/store/inventory")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new getInventoryResponse(reply, invoker);

}

placeOrderResponse* placeOrder (AbstractApiInvoker* invoker,
        Optional<Order> body) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/store/order")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "StoreApi::placeOrder", "Order body is not url encodable");
        }
        else {
            auto jsonValue = swagger::serialize(bodyVar);
            if(jsonValue.isArray())
                http_body = QJsonDocument(jsonValue.toArray()).toJson(QJsonDocument::Compact);
            else if(jsonValue.isObject())
                http_body = QJsonDocument(jsonValue.toObject()).toJson(QJsonDocument::Compact);
        }
    }
    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new placeOrderResponse(reply, invoker);

}

getOrderByIdResponse* getOrderById (AbstractApiInvoker* invoker,
        const QString& orderId) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/store/order/{orderId}")).replace(QLatin1String("{format}"),"json");
    path.replace("{orderId}", to_query_value(orderId));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new getOrderByIdResponse(reply, invoker);

}

deleteOrderResponse* deleteOrder (AbstractApiInvoker* invoker,
        const QString& orderId) {

    QByteArray http_method = QByteArrayLiteral("DELETE");
    QByteArray http_body;

    QString path = QString(QLatin1String("/store/order/{orderId}")).replace(QLatin1String("{format}"),"json");
    path.replace("{orderId}", to_query_value(orderId));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new deleteOrderResponse(reply, invoker);

}

} //namespace StoreApi




} /* namespace Swagger */