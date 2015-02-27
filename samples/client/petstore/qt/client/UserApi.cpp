#include "UserApi.h"

#include <QUrlQuery>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "SwaggerUtils.h"

namespace swagger {

namespace UserApi {

namespace responses {

createUserResponse::createUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

createUserResponse* createUserResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool createUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

createUsersWithArrayInputResponse::createUsersWithArrayInputResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

createUsersWithArrayInputResponse* createUsersWithArrayInputResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool createUsersWithArrayInputResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

createUsersWithListInputResponse::createUsersWithListInputResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

createUsersWithListInputResponse* createUsersWithListInputResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool createUsersWithListInputResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

loginUserResponse::loginUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

loginUserResponse* loginUserResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


loginUserResponse* loginUserResponse::on(const std::function<void(QString)> & callback) {
    m_200_fun = callback;
    return this;
}

bool loginUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 200:{  //QString
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for QString - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<QString>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QString");
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

logoutUserResponse::logoutUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

logoutUserResponse* logoutUserResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool logoutUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

getUserByNameResponse::getUserByNameResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

getUserByNameResponse* getUserByNameResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


getUserByNameResponse* getUserByNameResponse::on(const std::function<void(User)> & callback) {
    m_200_fun = callback;
    return this;
}

bool getUserByNameResponse::processResponse(int status, const QJsonValue & data) {
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
        case 200:{  //User
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for User - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<User>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize User");
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

updateUserResponse::updateUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

updateUserResponse* updateUserResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool updateUserResponse::processResponse(int status, const QJsonValue & data) {
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

deleteUserResponse::deleteUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

deleteUserResponse* deleteUserResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool deleteUserResponse::processResponse(int status, const QJsonValue & data) {
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


createUserResponse* createUser (AbstractApiInvoker* invoker,
        Optional<User> body) {

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new createUserResponse(reply, invoker);

}

createUsersWithArrayInputResponse* createUsersWithArrayInput (AbstractApiInvoker* invoker,
        Optional<QVector<User>> body) {

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new createUsersWithArrayInputResponse(reply, invoker);

}

createUsersWithListInputResponse* createUsersWithListInput (AbstractApiInvoker* invoker,
        Optional<QVector<User>> body) {

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new createUsersWithListInputResponse(reply, invoker);

}

loginUserResponse* loginUser (AbstractApiInvoker* invoker,
        Optional<QString> username,
        Optional<QString> password) {

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new loginUserResponse(reply, invoker);

}

logoutUserResponse* logoutUser (AbstractApiInvoker* invoker) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/user/logout")).replace(QLatin1String("{format}"),"json");

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
    return new logoutUserResponse(reply, invoker);

}

getUserByNameResponse* getUserByName (AbstractApiInvoker* invoker,
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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new getUserByNameResponse(reply, invoker);

}

updateUserResponse* updateUser (AbstractApiInvoker* invoker,
        const QString& username,
        Optional<User> body) {

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new updateUserResponse(reply, invoker);

}

deleteUserResponse* deleteUser (AbstractApiInvoker* invoker,
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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new deleteUserResponse(reply, invoker);

}

} //namespace UserApi




} /* namespace Swagger */
