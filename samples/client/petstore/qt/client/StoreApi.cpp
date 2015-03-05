#include "StoreApi_p.h"
#include <array>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "SwaggerUtils.h"

namespace swagger {

namespace StoreApi {

namespace responses {

getInventoryRequest::getInventoryRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error getInventoryRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 200  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 200:{  //QHash<QString, qint32>
            auto value = swagger::unserialize<QHash<QString, qint32>>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QHash<QString, qint32>");
                return AbstractRequest::InvalidResponse;
            }
            Q_EMIT finished200(*value);
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

placeOrderRequest::placeOrderRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error placeOrderRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 200:{  //Order
            auto value = swagger::unserialize<Order>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize Order");
                return AbstractRequest::InvalidResponse;
            }
            Q_EMIT finished200(*value);
            
            return NoError;
        }
        case 400:{ 
            Q_EMIT finished400();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

getOrderByIdRequest::getOrderByIdRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error getOrderByIdRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 3> knownStatus{{ 404, 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 404:{ 
            Q_EMIT finished404();
            
            return NoError;
        }
        case 200:{  //Order
            auto value = swagger::unserialize<Order>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize Order");
                return AbstractRequest::InvalidResponse;
            }
            Q_EMIT finished200(*value);
            
            return NoError;
        }
        case 400:{ 
            Q_EMIT finished400();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

deleteOrderRequest::deleteOrderRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error deleteOrderRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 404, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 404:{ 
            Q_EMIT finished404();
            
            return NoError;
        }
        case 400:{ 
            Q_EMIT finished400();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

} //namespace responses

using namespace responses;

namespace operations {




Sender<responses::getInventoryRequest> getInventory (AbstractApiInvoker* invoker) {

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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new getInventoryRequest(std::move(params), invoker, QStringList{ "api_key" }  );
    return request;
}



Sender<responses::placeOrderRequest> placeOrder (AbstractApiInvoker* invoker,
        boost::optional<Order> body) {

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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new placeOrderRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::getOrderByIdRequest> getOrderById (AbstractApiInvoker* invoker,
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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new getOrderByIdRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::deleteOrderRequest> deleteOrder (AbstractApiInvoker* invoker,
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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new deleteOrderRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}

}

} //namespace StoreApi




} /* namespace Swagger */
