#ifndef AK_SWAGGER_UserApi_H_
#define AK_SWAGGER_UserApi_H_

#include "User.h"
#include <QVector>
#include <QString>
#include "AbstractResponse.h"
#include "ApiInvoker.h"

class QNetworkReply;

namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

namespace UserApi {

namespace responses {

    class createUserResponse;
    class createUsersWithArrayInputResponse;
    class createUsersWithListInputResponse;
    class loginUserResponse;
    class logoutUserResponse;
    class getUserByNameResponse;
    class updateUserResponse;
    class deleteUserResponse;
}


responses::createUserResponse* createUser(AbstractApiInvoker* invoker,
                Optional<User> body = {} );

responses::createUsersWithArrayInputResponse* createUsersWithArrayInput(AbstractApiInvoker* invoker,
                Optional<QVector<User>> body = {} );

responses::createUsersWithListInputResponse* createUsersWithListInput(AbstractApiInvoker* invoker,
                Optional<QVector<User>> body = {} );

responses::loginUserResponse* loginUser(AbstractApiInvoker* invoker,
                Optional<QString> username = {} ,
                Optional<QString> password = {} );

responses::logoutUserResponse* logoutUser(AbstractApiInvoker* invoker);

responses::getUserByNameResponse* getUserByName(AbstractApiInvoker* invoker,
                const QString& username);

responses::updateUserResponse* updateUser(AbstractApiInvoker* invoker,
                const QString& username,
                Optional<User> body = {} );

responses::deleteUserResponse* deleteUser(AbstractApiInvoker* invoker,
                const QString& username);



namespace responses {

class createUserResponse : public AbstractResponse {

public:
    createUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    createUserResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class createUsersWithArrayInputResponse : public AbstractResponse {

public:
    createUsersWithArrayInputResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    createUsersWithArrayInputResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class createUsersWithListInputResponse : public AbstractResponse {

public:
    createUsersWithListInputResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    createUsersWithListInputResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class loginUserResponse : public AbstractResponse {

public:
    loginUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    loginUserResponse* onEmptyResponse(std::function<void(int)>);
    loginUserResponse* on(const std::function<void(QString)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:
    std::function<void(QString)> m_200_fun;

};

class logoutUserResponse : public AbstractResponse {

public:
    logoutUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    logoutUserResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class getUserByNameResponse : public AbstractResponse {

public:
    getUserByNameResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    getUserByNameResponse* onEmptyResponse(std::function<void(int)>);

    getUserByNameResponse* on(const std::function<void(User)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

    std::function<void(User)> m_200_fun;

};

class updateUserResponse : public AbstractResponse {

public:
    updateUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    updateUserResponse* onEmptyResponse(std::function<void(int)>);



protected:
    bool processResponse(int status, const QJsonValue & data);

private:


};

class deleteUserResponse : public AbstractResponse {

public:
    deleteUserResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    deleteUserResponse* onEmptyResponse(std::function<void(int)>);



protected:
    bool processResponse(int status, const QJsonValue & data);

private:


};

} //namespace responses

} //namespace UserApi

} //namespace swagger

#endif /* UserApi_H_ */