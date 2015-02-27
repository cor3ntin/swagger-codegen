#ifndef AK_SWAGGER_PetApi_H_
#define AK_SWAGGER_PetApi_H_

#include "Pet.h"
#include <QString>
#include <QIODevice>
#include "AbstractResponse.h"
#include "ApiInvoker.h"

class QNetworkReply;

namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

namespace PetApi {

namespace responses {

    class updatePetResponse;
    class addPetResponse;
    class findPetsByStatusResponse;
    class findPetsByTagsResponse;
    class getPetByIdResponse;
    class updatePetWithFormResponse;
    class deletePetResponse;
    class uploadFileResponse;
}


responses::updatePetResponse* updatePet(AbstractApiInvoker* invoker,
                Optional<Pet> body = {} );

responses::addPetResponse* addPet(AbstractApiInvoker* invoker,
                Optional<Pet> body = {} );

responses::findPetsByStatusResponse* findPetsByStatus(AbstractApiInvoker* invoker,
                Optional<QStringList> status = {} );

responses::findPetsByTagsResponse* findPetsByTags(AbstractApiInvoker* invoker,
                Optional<QStringList> tags = {} );

responses::getPetByIdResponse* getPetById(AbstractApiInvoker* invoker,
                const qint64& petId);

responses::updatePetWithFormResponse* updatePetWithForm(AbstractApiInvoker* invoker,
                const QString& petId,
                Optional<QString> name = {} ,
                Optional<QString> status = {} );

responses::deletePetResponse* deletePet(AbstractApiInvoker* invoker,
                const qint64& petId,
                Optional<QString> api_key = {} );

responses::uploadFileResponse* uploadFile(AbstractApiInvoker* invoker,
                const qint64& petId,
                Optional<QString> additionalMetadata = {} ,
                QIODevice* file = {} );



namespace responses {

class updatePetResponse : public AbstractResponse {

public:
    updatePetResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    updatePetResponse* onEmptyResponse(std::function<void(int)>);




protected:
    bool processResponse(int status, const QJsonValue & data);

private:



};

class addPetResponse : public AbstractResponse {

public:
    addPetResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    addPetResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class findPetsByStatusResponse : public AbstractResponse {

public:
    findPetsByStatusResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    findPetsByStatusResponse* onEmptyResponse(std::function<void(int)>);
    findPetsByStatusResponse* on(const std::function<void(QVector<Pet>)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:
    std::function<void(QVector<Pet>)> m_200_fun;

};

class findPetsByTagsResponse : public AbstractResponse {

public:
    findPetsByTagsResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    findPetsByTagsResponse* onEmptyResponse(std::function<void(int)>);
    findPetsByTagsResponse* on(const std::function<void(QVector<Pet>)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:
    std::function<void(QVector<Pet>)> m_200_fun;

};

class getPetByIdResponse : public AbstractResponse {

public:
    getPetByIdResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    getPetByIdResponse* onEmptyResponse(std::function<void(int)>);

    getPetByIdResponse* on(const std::function<void(Pet)> & callback);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

    std::function<void(Pet)> m_200_fun;

};

class updatePetWithFormResponse : public AbstractResponse {

public:
    updatePetWithFormResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    updatePetWithFormResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class deletePetResponse : public AbstractResponse {

public:
    deletePetResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    deletePetResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

class uploadFileResponse : public AbstractResponse {

public:
    uploadFileResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    uploadFileResponse* onEmptyResponse(std::function<void(int)>);


protected:
    bool processResponse(int status, const QJsonValue & data);

private:

};

} //namespace responses

} //namespace PetApi

} //namespace swagger

#endif /* PetApi_H_ */