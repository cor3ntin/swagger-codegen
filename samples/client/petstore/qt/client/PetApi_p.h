#ifndef AK_SWAGGER_PetApi_H_
#define AK_SWAGGER_PetApi_H_

#include "Pet.h"
#include <QString>
#include <QIODevice>
#include <type_traits>
#include "AbstractRequest.h"
#include "ApiInvoker.h"
#include "SwaggerUtils.h"

class QNetworkReply;

namespace swagger {

namespace PetApi {

namespace responses {

    class updatePetRequest;
    class addPetRequest;
    class findPetsByStatusRequest;
    class findPetsByTagsRequest;
    class getPetByIdRequest;
    class updatePetWithFormRequest;
    class deletePetRequest;
    class uploadFileRequest;
}

namespace operations {
//Requires authentification with scheme petstore_auth (oauth2)
responses::updatePetRequest* updatePet(AbstractApiInvoker* invoker,
                boost::optional<Pet> body = {} );

//Requires authentification with scheme petstore_auth (oauth2)
responses::addPetRequest* addPet(AbstractApiInvoker* invoker,
                boost::optional<Pet> body = {} );

//Requires authentification with scheme petstore_auth (oauth2)
responses::findPetsByStatusRequest* findPetsByStatus(AbstractApiInvoker* invoker,
                boost::optional<QStringList> status = {} );

//Requires authentification with scheme petstore_auth (oauth2)
responses::findPetsByTagsRequest* findPetsByTags(AbstractApiInvoker* invoker,
                boost::optional<QStringList> tags = {} );

//Requires authentification with scheme api_key (apiKey)
//Requires authentification with scheme petstore_auth (oauth2)
responses::getPetByIdRequest* getPetById(AbstractApiInvoker* invoker,
                const qint64& petId);

//Requires authentification with scheme petstore_auth (oauth2)
responses::updatePetWithFormRequest* updatePetWithForm(AbstractApiInvoker* invoker,
                const QString& petId,
                boost::optional<QString> name = {} ,
                boost::optional<QString> status = {} );

//Requires authentification with scheme petstore_auth (oauth2)
responses::deletePetRequest* deletePet(AbstractApiInvoker* invoker,
                const qint64& petId,
                boost::optional<QString> api_key = {} );

//Requires authentification with scheme petstore_auth (oauth2)
responses::uploadFileRequest* uploadFile(AbstractApiInvoker* invoker,
                const qint64& petId,
                boost::optional<QString> additionalMetadata = {} ,
                QIODevice* file = {} );

}


namespace responses {
namespace updatePetRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 405 };
        using isDefault = std::integral_constant<bool, 405 == 0>;
        using isSuccess = std::integral_constant<bool, (405 >= 200 && 405 < 400)>;
    };
    
    
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
    using Arities = details::Arities<void,void,void>;
}
namespace addPetRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 405 };
        using isDefault = std::integral_constant<bool, 405 == 0>;
        using isSuccess = std::integral_constant<bool, (405 >= 200 && 405 < 400)>;
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
namespace findPetsByStatusRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<QVector<Pet>> {
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
    using Arities = details::Arities<QVector<Pet>,void>;
}
namespace findPetsByTagsRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<QVector<Pet>> {
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
    using Arities = details::Arities<QVector<Pet>,void>;
}
namespace getPetByIdRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 404 };
        using isDefault = std::integral_constant<bool, 404 == 0>;
        using isSuccess = std::integral_constant<bool, (404 >= 200 && 404 < 400)>;
    };
    
    
    template  <>
    struct ResponseInfo<Pet> {
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
    using Arities = details::Arities<void,Pet,void>;
}
namespace updatePetWithFormRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
    template  <>
    struct ResponseInfo<void> {
        enum { code = 405 };
        using isDefault = std::integral_constant<bool, 405 == 0>;
        using isSuccess = std::integral_constant<bool, (405 >= 200 && 405 < 400)>;
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
namespace deletePetRequestDetails {
    template  <typename T>
    struct ResponseInfo {};
    
    
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
    using Arities = details::Arities<void>;
}
namespace uploadFileRequestDetails {
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

class updatePetRequest : public AbstractRequest {
    Q_OBJECT
public:
    updatePetRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished405();
    void finished404();
    void finished400();

public:
    SWAGGER_SMART_SLOT(updatePet,void, 405)
    SWAGGER_SMART_SLOT(updatePet,void, 404)
    SWAGGER_SMART_SLOT(updatePet,void, 400)
    template <typename... Args>
    updatePetRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    updatePetRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class addPetRequest : public AbstractRequest {
    Q_OBJECT
public:
    addPetRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished405();

public:
    SWAGGER_SMART_SLOT(addPet,void, 405)
    template <typename... Args>
    addPetRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    addPetRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class findPetsByStatusRequest : public AbstractRequest {
    Q_OBJECT
public:
    findPetsByStatusRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished200(QVector<Pet>);
    void finished400();

public:
    SWAGGER_SMART_SLOT(findPetsByStatus,QVector<Pet>, 200)
    SWAGGER_SMART_SLOT(findPetsByStatus,void, 400)
    template <typename... Args>
    findPetsByStatusRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    findPetsByStatusRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class findPetsByTagsRequest : public AbstractRequest {
    Q_OBJECT
public:
    findPetsByTagsRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished200(QVector<Pet>);
    void finished400();

public:
    SWAGGER_SMART_SLOT(findPetsByTags,QVector<Pet>, 200)
    SWAGGER_SMART_SLOT(findPetsByTags,void, 400)
    template <typename... Args>
    findPetsByTagsRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    findPetsByTagsRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class getPetByIdRequest : public AbstractRequest {
    Q_OBJECT
public:
    getPetByIdRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished404();
    void finished200(Pet);
    void finished400();

public:
    SWAGGER_SMART_SLOT(getPetById,void, 404)
    SWAGGER_SMART_SLOT(getPetById,Pet, 200)
    SWAGGER_SMART_SLOT(getPetById,void, 400)
    template <typename... Args>
    getPetByIdRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    getPetByIdRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class updatePetWithFormRequest : public AbstractRequest {
    Q_OBJECT
public:
    updatePetWithFormRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished405();

public:
    SWAGGER_SMART_SLOT(updatePetWithForm,void, 405)
    template <typename... Args>
    updatePetWithFormRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    updatePetWithFormRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class deletePetRequest : public AbstractRequest {
    Q_OBJECT
public:
    deletePetRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished400();

public:
    SWAGGER_SMART_SLOT(deletePet,void, 400)
    template <typename... Args>
    deletePetRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    deletePetRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

class uploadFileRequest : public AbstractRequest {
    Q_OBJECT
public:
    uploadFileRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);

Q_SIGNALS:
    void finished0();

public:
    SWAGGER_SMART_SLOT(uploadFile,void, 0)
    template <typename... Args>
    uploadFileRequest* then(Args... args) {
        connect(this, &AbstractRequest::done, std::forward<Args>(args)...);
        return this;
    }
    template <typename... Args>
    uploadFileRequest* onUnexpectedError(Args... args) {
        connect(this, &AbstractRequest::failed, std::forward<Args>(args)...);
        return this;
    }
protected:
    AbstractRequest::Error processResponse(int status, const QJsonValue & data);

private:
};

} //namespace responses

} //namespace PetApi

} //namespace swagger

#endif /* PetApi_H_ */