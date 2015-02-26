#include "UserApi.h"

#include <QUrlQuery>
#include <QNetworkRequest>
#include <QHttpMultiPart>

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

createUserResponse* createUserResponse::on(const std::function<void()> & callback) {
    m_0_fun = callback;
    return this;
}

bool createUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:
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

createUsersWithArrayInputResponse* createUsersWithArrayInputResponse::on(const std::function<void()> & callback) {
    m_0_fun = callback;
    return this;
}

bool createUsersWithArrayInputResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:
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

createUsersWithListInputResponse* createUsersWithListInputResponse::on(const std::function<void()> & callback) {
    m_0_fun = callback;
    return this;
}

bool createUsersWithListInputResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:
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

loginUserResponse* loginUserResponse::on(const std::function<void()> & callback) {
    m_400_fun = callback;
    return this;
}

bool loginUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 200: //QString
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
        case 400:
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

logoutUserResponse* logoutUserResponse::on(const std::function<void()> & callback) {
    m_0_fun = callback;
    return this;
}

bool logoutUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 0  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 0:
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

getUserByNameResponse* getUserByNameResponse::on(const std::function<void()> & callback) {
    m_404_fun = callback;
    return this;
}

getUserByNameResponse* getUserByNameResponse::on(const std::function<void(User)> & callback) {
    m_200_fun = callback;
    return this;
}

getUserByNameResponse* getUserByNameResponse::on(const std::function<void()> & callback) {
    m_400_fun = callback;
    return this;
}

bool getUserByNameResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 3> knownStatus{{ 404, 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 404:
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        case 200: //User
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
        case 400:
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

updateUserResponse* updateUserResponse::on(const std::function<void()> & callback) {
    m_404_fun = callback;
    return this;
}

updateUserResponse* updateUserResponse::on(const std::function<void()> & callback) {
    m_400_fun = callback;
    return this;
}

bool updateUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 404, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 404:
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        case 400:
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

deleteUserResponse* deleteUserResponse::on(const std::function<void()> & callback) {
    m_404_fun = callback;
    return this;
}

deleteUserResponse* deleteUserResponse::on(const std::function<void()> & callback) {
    m_400_fun = callback;
    return this;
}

bool deleteUserResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 404, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 404:
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        case 400:
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


    QString path = QString(QLatin1String("/user")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("POST"), queryParams, headers, formParams, parts, contentType);
    return new createUserResponse(reply, invoker);

}

createUsersWithArrayInputResponse* createUsersWithArrayInput (AbstractApiInvoker* invoker,
        Optional<QVector<User>> body) {


    QString path = QString(QLatin1String("/user/createWithArray")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("POST"), queryParams, headers, formParams, parts, contentType);
    return new createUsersWithArrayInputResponse(reply, invoker);

}

createUsersWithListInputResponse* createUsersWithListInput (AbstractApiInvoker* invoker,
        Optional<QVector<User>> body) {


    QString path = QString(QLatin1String("/user/createWithList")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("POST"), queryParams, headers, formParams, parts, contentType);
    return new createUsersWithListInputResponse(reply, invoker);

}

loginUserResponse* loginUser (AbstractApiInvoker* invoker,
        Optional<QString> username,
        Optional<QString> password) {


    QString path = QString(QLatin1String("/user/login")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;
    if(username) queryParams.addQueryItem("username", to_query_value(*username));
    if(password) queryParams.addQueryItem("password", to_query_value(*password));

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("GET"), queryParams, headers, formParams, parts, contentType);
    return new loginUserResponse(reply, invoker);

}

logoutUserResponse* logoutUser (AbstractApiInvoker* invoker) {


    QString path = QString(QLatin1String("/user/logout")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("GET"), queryParams, headers, formParams, parts, contentType);
    return new logoutUserResponse(reply, invoker);

}

getUserByNameResponse* getUserByName (AbstractApiInvoker* invoker,
        const QString& username) {


    QString path = QString(QLatin1String("/user/{username}")).replace(QLatin1String("{format}"),"json");
    path.replaceAll("{" + "username" + "}", to_query_value(username));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("GET"), queryParams, headers, formParams, parts, contentType);
    return new getUserByNameResponse(reply, invoker);

}

updateUserResponse* updateUser (AbstractApiInvoker* invoker,
        const QString& username,
        Optional<User> body) {


    QString path = QString(QLatin1String("/user/{username}")).replace(QLatin1String("{format}"),"json");
    path.replaceAll("{" + "username" + "}", to_query_value(username));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("PUT"), queryParams, headers, formParams, parts, contentType);
    return new updateUserResponse(reply, invoker);

}

deleteUserResponse* deleteUser (AbstractApiInvoker* invoker,
        const QString& username) {


    QString path = QString(QLatin1String("/user/{username}")).replace(QLatin1String("{format}"),"json");
    path.replaceAll("{" + "username" + "}", to_query_value(username));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    QHttpMultiPart* parts = nullptr;

    auto reply = invoker->invoke(path, QByteArrayLiteral("DELETE"), queryParams, headers, formParams, parts, contentType);
    return new deleteUserResponse(reply, invoker);

}

} //namespace UserApi




} /* namespace Swagger */
