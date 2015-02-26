#ifndef AK_SWAGGER_UserApi_H_
#define AK_SWAGGER_UserApi_H_

#include "User.h"
#include <QVector>
#include <QString>
#include <type_traits>
#include "AbstractRequest.h"
#include "ApiInvoker.h"
#include "SwaggerUtils.h"

class QNetworkReply;

namespace swagger {

namespace UserApi {

namespace responses {

    class createUserRequest;
    class createUsersWithArrayInputRequest;
    class createUsersWithListInputRequest;
    class loginUserRequest;
    class logoutUserRequest;
    class getUserByNameRequest;
    class updateUserRequest;
    class deleteUserRequest;
}

namespace operations {
responses::createUserRequest* createUser(AbstractApiInvoker* invoker,
                boost::optional<User> body = {} );

responses::createUsersWithArrayInputRequest* createUsersWithArrayInput(AbstractApiInvoker* invoker,
                boost::optional<QVector<User>> body = {} );

responses::createUsersWithListInputRequest* createUsersWithListInput(AbstractApiInvoker* invoker,
                boost::optional<QVector<User>> body = {} );

responses::loginUserRequest* loginUser(AbstractApiInvoker* invoker,
                boost::optional<QString> username = {} ,
                boost::optional<QString> password = {} );

responses::logoutUserRequest* logoutUser(AbstractApiInvoker* invoker);

responses::getUserByNameRequest* getUserByName(AbstractApiInvoker* invoker,
                const QString& username);

responses::updateUserRequest* updateUser(AbstractApiInvoker* invoker,
                const QString& username,
                boost::optional<User> body = {} );

responses::deleteUserRequest* deleteUser(AbstractApiInvoker* invoker,
                const QString& username);

}


namespace responses {
namespace createUserRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 0 };
        using isDefault = std::integral_constant<bool, 0 == 0>;
        using isSuccess = std::integral_constant<bool, (0 >= 200 && 0 < 400)>;
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
    using Arities = details::Arities<void>;
}
namespace createUsersWithArrayInputRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 0 };
        using isDefault = std::integral_constant<bool, 0 == 0>;
        using isSuccess = std::integral_constant<bool, (0 >= 200 && 0 < 400)>;
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
    using Arities = details::Arities<void>;
}
namespace createUsersWithListInputRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 0 };
        using isDefault = std::integral_constant<bool, 0 == 0>;
        using isSuccess = std::integral_constant<bool, (0 >= 200 && 0 < 400)>;
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
    using Arities = details::Arities<void>;
}
namespace loginUserRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<QString> {
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
    using Arities = details::Arities<QString,void>;
}
namespace logoutUserRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 0 };
        using isDefault = std::integral_constant<bool, 0 == 0>;
        using isSuccess = std::integral_constant<bool, (0 >= 200 && 0 < 400)>;
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
    using Arities = details::Arities<void>;
}
namespace getUserByNameRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 404 };
        using isDefault = std::integral_constant<bool, 404 == 0>;
        using isSuccess = std::integral_constant<bool, (404 >= 200 && 404 < 400)>;
    };
    
    
    template  <>
    struct ResponseInfo<User> {
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
    using Arities = details::Arities<void,User,void>;
}
namespace updateUserRequestDetails {
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
namespace deleteUserRequestDetails {
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

class createUserRequest : public AbstractRequest {
    Q_OBJECT
public:
    createUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished0();

public:
    SWAGGER_SMART_SLOT(createUser,void, 0)
    template <typename... Args>
    createUserRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    createUserRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class createUsersWithArrayInputRequest : public AbstractRequest {
    Q_OBJECT
public:
    createUsersWithArrayInputRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished0();

public:
    SWAGGER_SMART_SLOT(createUsersWithArrayInput,void, 0)
    template <typename... Args>
    createUsersWithArrayInputRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    createUsersWithArrayInputRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class createUsersWithListInputRequest : public AbstractRequest {
    Q_OBJECT
public:
    createUsersWithListInputRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished0();

public:
    SWAGGER_SMART_SLOT(createUsersWithListInput,void, 0)
    template <typename... Args>
    createUsersWithListInputRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    createUsersWithListInputRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class loginUserRequest : public AbstractRequest {
    Q_OBJECT
public:
    loginUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished200(QString);
    void finished400();

public:
    SWAGGER_SMART_SLOT(loginUser,QString, 200)
    SWAGGER_SMART_SLOT(loginUser,void, 400)
    template <typename... Args>
    loginUserRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    loginUserRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class logoutUserRequest : public AbstractRequest {
    Q_OBJECT
public:
    logoutUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished0();

public:
    SWAGGER_SMART_SLOT(logoutUser,void, 0)
    template <typename... Args>
    logoutUserRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    logoutUserRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class getUserByNameRequest : public AbstractRequest {
    Q_OBJECT
public:
    getUserByNameRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished404();
    void finished200(User);
    void finished400();

public:
    SWAGGER_SMART_SLOT(getUserByName,void, 404)
    SWAGGER_SMART_SLOT(getUserByName,User, 200)
    SWAGGER_SMART_SLOT(getUserByName,void, 400)
    template <typename... Args>
    getUserByNameRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    getUserByNameRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class updateUserRequest : public AbstractRequest {
    Q_OBJECT
public:
    updateUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished404();
    void finished400();

public:
    SWAGGER_SMART_SLOT(updateUser,void, 404)
    SWAGGER_SMART_SLOT(updateUser,void, 400)
    template <typename... Args>
    updateUserRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    updateUserRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class deleteUserRequest : public AbstractRequest {
    Q_OBJECT
public:
    deleteUserRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished404();
    void finished400();

public:
    SWAGGER_SMART_SLOT(deleteUser,void, 404)
    SWAGGER_SMART_SLOT(deleteUser,void, 400)
    template <typename... Args>
    deleteUserRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    deleteUserRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

} //namespace responses

} //namespace UserApi

} //namespace swagger

#endif /* UserApi_H_ */