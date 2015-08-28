#include "PetApi_p.h"
#include <array>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "SwaggerUtils.h"

namespace swagger {

namespace PetApi {

namespace responses {

updatePetRequest::updatePetRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error updatePetRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 3> knownStatus{{ 405, 404, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 405:{ 
            Q_EMIT finished405();
            
            return NoError;
        }
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

addPetRequest::addPetRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error addPetRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 405  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 405:{ 
            Q_EMIT finished405();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

findPetsByStatusRequest::findPetsByStatusRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error findPetsByStatusRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 200:{  //QVector<Pet>
            auto value = swagger::unserialize<QVector<Pet>>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QVector<Pet>");
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

findPetsByTagsRequest::findPetsByTagsRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error findPetsByTagsRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 200:{  //QVector<Pet>
            auto value = swagger::unserialize<QVector<Pet>>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QVector<Pet>");
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

getPetByIdRequest::getPetByIdRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error getPetByIdRequest::processResponse(int status, const QJsonValue & data) {
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
        case 200:{  //Pet
            auto value = swagger::unserialize<Pet>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize Pet");
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

updatePetWithFormRequest::updatePetWithFormRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error updatePetWithFormRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 405  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 405:{ 
            Q_EMIT finished405();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

deletePetRequest::deletePetRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error deletePetRequest::processResponse(int status, const QJsonValue & data) {
    Q_UNUSED(data);

    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

   switch(callbackId) { 
        case 400:{ 
            Q_EMIT finished400();
            
            return NoError;
        }
        default:
            return AbstractRequest::UnexpectedResponseCode;
    }
    return AbstractRequest::UnknownError;
}

uploadFileRequest::uploadFileRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : AbstractRequest(std::move(params), invoker, std::move(authSchemes)) {
}

AbstractRequest::Error uploadFileRequest::processResponse(int status, const QJsonValue & data) {
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

} //namespace responses

using namespace responses;

namespace operations {




Sender<responses::updatePetRequest> updatePet (AbstractApiInvoker* invoker,
        boost::optional<Pet> body) {

    QByteArray http_method = QByteArrayLiteral("PUT");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QStringList contentTypes = {
        "application/json","application/xml"
    };
    QString contentType = !contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "PetApi::updatePet", "Pet body is not url encodable");
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
    auto request = new updatePetRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}



Sender<responses::addPetRequest> addPet (AbstractApiInvoker* invoker,
        boost::optional<Pet> body) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QStringList contentTypes = {
        "application/json","application/xml"
    };
    QString contentType = !contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");

    if(body) { 
        auto bodyVar = * body;
        if(contentType == QLatin1String("application/x-www-form-urlencoded")) {
            
            Q_ASSERT_X(false, "PetApi::addPet", "Pet body is not url encodable");
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
    auto request = new addPetRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}



Sender<responses::findPetsByStatusRequest> findPetsByStatus (AbstractApiInvoker* invoker,
        boost::optional<QStringList> status) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/findByStatus")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;
    if(status) queryParams.addQueryItem("status", to_query_value(*status));

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new findPetsByStatusRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}



Sender<responses::findPetsByTagsRequest> findPetsByTags (AbstractApiInvoker* invoker,
        boost::optional<QStringList> tags) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/findByTags")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;
    if(tags) queryParams.addQueryItem("tags", to_query_value(*tags));

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new findPetsByTagsRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}



Sender<responses::getPetByIdRequest> getPetById (AbstractApiInvoker* invoker,
        const qint64& petId) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/{petId}")).replace(QLatin1String("{format}"),"json");
    path.replace("{petId}", to_query_value(petId));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new getPetByIdRequest(std::move(params), invoker, QStringList{ "api_key","petstore_auth" }  );
    return request;
}



Sender<responses::updatePetWithFormRequest> updatePetWithForm (AbstractApiInvoker* invoker,
        const QString& petId,
        boost::optional<QString> name,
        boost::optional<QString> status) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/{petId}")).replace(QLatin1String("{format}"),"json");
    path.replace("{petId}", to_query_value(petId));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QStringList contentTypes = {
        "application/x-www-form-urlencoded"
    };
    QString contentType = !contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");


    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
            if(name)set_form_data(parts,"name", *name);
            if(status)set_form_data(parts,"status", *status);
    
    }
    else {
            if(name)formParams.addQueryItem("name", to_query_value(*name));
            if(status)formParams.addQueryItem("status", to_query_value(*status));
    
    }

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new updatePetWithFormRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}



Sender<responses::deletePetRequest> deletePet (AbstractApiInvoker* invoker,
        const qint64& petId,
        boost::optional<QString> api_key) {

    QByteArray http_method = QByteArrayLiteral("DELETE");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/{petId}")).replace(QLatin1String("{format}"),"json");
    path.replace("{petId}", to_query_value(petId));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;
    if(api_key) headers.insert("api_key", QVariant::fromValue<QString>(*api_key));

    QString contentType(QLatin1String("application/json"));


    QHttpMultiPart* parts = nullptr;

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new deletePetRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}



Sender<responses::uploadFileRequest> uploadFile (AbstractApiInvoker* invoker,
        const qint64& petId,
        boost::optional<QString> additionalMetadata,
        QIODevice* file) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/{petId}/uploadImage")).replace(QLatin1String("{format}"),"json");
    path.replace("{petId}", to_query_value(petId));

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QStringList contentTypes = {
        "multipart/form-data"
    };
    QString contentType = !contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");


    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
            if(additionalMetadata)set_form_data(parts,"additionalMetadata", *additionalMetadata);
            if(file)set_form_data(parts,"file", file);
    
    }
    else {
            if(additionalMetadata)formParams.addQueryItem("additionalMetadata", to_query_value(*additionalMetadata));
    
    
    }

    auto params = invoker->prepare(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    auto request = new uploadFileRequest(std::move(params), invoker, QStringList{ "petstore_auth" }  );
    return request;
}

}

} //namespace PetApi




} /* namespace Swagger */
