#include "UserApi_p.h"
#include <array>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "SwaggerUtils.h"

namespace swagger {

namespace UserApi {

namespace responses {

createUserRequest::createUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error createUserRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 0:{ 
            Q_EMIT finished0();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

createUsersWithArrayInputRequest::createUsersWithArrayInputRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error createUsersWithArrayInputRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 0:{ 
            Q_EMIT finished0();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

createUsersWithListInputRequest::createUsersWithListInputRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error createUsersWithListInputRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 0:{ 
            Q_EMIT finished0();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

loginUserRequest::loginUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error loginUserRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 200:{  //QString
            auto value = swagger::unserialize<QString>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QString");
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

logoutUserRequest::logoutUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error logoutUserRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 0:{ 
            Q_EMIT finished0();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

getUserByNameRequest::getUserByNameRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error getUserByNameRequest::processResponse(int status, const QJsonValue & data) {
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
        case 200:{  //User
            auto value = swagger::unserialize<User>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize User");
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

updateUserRequest::updateUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error updateUserRequest::processResponse(int status, const QJsonValue & data) {
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

deleteUserRequest::deleteUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error deleteUserRequest::processResponse(int status, const QJsonValue & data) {
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




Sender<responses::createUserRequest> createUser (AbstractApiInvoker* invoker,
        boost::optional<User> body) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "UserApi::createUser", "User body is not url encodable");
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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new createUserRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::createUsersWithArrayInputRequest> createUsersWithArrayInput (AbstractApiInvoker* invoker,
        boost::optional<QVector<User>> body) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/createWithArray")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "UserApi::createUsersWithArrayInput", "QVector<User> body is not url encodable");
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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new createUsersWithArrayInputRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::createUsersWithListInputRequest> createUsersWithListInput (AbstractApiInvoker* invoker,
        boost::optional<QVector<User>> body) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/createWithList")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "UserApi::createUsersWithListInput", "QVector<User> body is not url encodable");
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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new createUsersWithListInputRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::loginUserRequest> loginUser (AbstractApiInvoker* invoker,
        boost::optional<QString> username,
        boost::optional<QString> password) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/login")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;
    if(username) queryParams.addQueryItem("username", to_query_value(*username));
    if(password) queryParams.addQueryItem("password", to_query_value(*password));

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new loginUserRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::logoutUserRequest> logoutUser (AbstractApiInvoker* invoker) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/logout")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new logoutUserRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::getUserByNameRequest> getUserByName (AbstractApiInvoker* invoker,
        const QString& username) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/{username}")).replace(QLatin1String("{format}"),"json");
    path.replace("{username}", to_query_value(username));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new getUserByNameRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::updateUserRequest> updateUser (AbstractApiInvoker* invoker,
        const QString& username,
        boost::optional<User> body) {

    QByteArray http_method = QByteArrayLiteral("PUT");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/{username}")).replace(QLatin1String("{format}"),"json");
    path.replace("{username}", to_query_value(username));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "UserApi::updateUser", "User body is not url encodable");
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

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new updateUserRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}



Sender<responses::deleteUserRequest> deleteUser (AbstractApiInvoker* invoker,
        const QString& username) {

    QByteArray http_method = QByteArrayLiteral("DELETE");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/{username}")).replace(QLatin1String("{format}"),"json");
    path.replace("{username}", to_query_value(username));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new deleteUserRequest(std::move(params), invoker, QStringList{  }  );
    return request;
}

}

} //namespace UserApi




} /* namespace Swagger */
