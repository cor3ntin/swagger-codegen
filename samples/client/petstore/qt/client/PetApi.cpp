#include "PetApi.h"

#include <QUrlQuery>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "SwaggerUtils.h"

namespace swagger {

namespace PetApi {

namespace responses {

updatePetResponse::updatePetResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

updatePetResponse* updatePetResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool updatePetResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 3> knownStatus{{ 405, 404, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 405:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
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

addPetResponse::addPetResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

addPetResponse* addPetResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool addPetResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 405  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 405:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

findPetsByStatusResponse::findPetsByStatusResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

findPetsByStatusResponse* findPetsByStatusResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


findPetsByStatusResponse* findPetsByStatusResponse::on(const std::function<void(QVector<Pet>)> & callback) {
    m_200_fun = callback;
    return this;
}

bool findPetsByStatusResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 200:{  //QVector<Pet>
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for QVector<Pet> - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<QVector<Pet>>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QVector<Pet>");
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

findPetsByTagsResponse::findPetsByTagsResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

findPetsByTagsResponse* findPetsByTagsResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


findPetsByTagsResponse* findPetsByTagsResponse::on(const std::function<void(QVector<Pet>)> & callback) {
    m_200_fun = callback;
    return this;
}

bool findPetsByTagsResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 2> knownStatus{{ 200, 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 200:{  //QVector<Pet>
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for QVector<Pet> - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<QVector<Pet>>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize QVector<Pet>");
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

getPetByIdResponse::getPetByIdResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

getPetByIdResponse* getPetByIdResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


getPetByIdResponse* getPetByIdResponse::on(const std::function<void(Pet)> & callback) {
    m_200_fun = callback;
    return this;
}

bool getPetByIdResponse::processResponse(int status, const QJsonValue & data) {
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
        case 200:{  //Pet
            if(!m_200_fun) {
                logSwaggerWarning("No callback defined for Pet - http status: %d", status);
                return true;
            }
            auto value = swagger::unserialize<Pet>(data);
            if(!value) {
                logSwaggerError("Unable to unserialize Pet");
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

updatePetWithFormResponse::updatePetWithFormResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

updatePetWithFormResponse* updatePetWithFormResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool updatePetWithFormResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 405  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
        case 405:{ 
            Q_UNUSED(data);
            if(m_empty_response_function)
                m_empty_response_function(status);
        }
        default:
            Q_ASSERT(false);
    }
    return false;
}

deletePetResponse::deletePetResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

deletePetResponse* deletePetResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool deletePetResponse::processResponse(int status, const QJsonValue & data) {
    int callbackId = status;
    static const std::array<int, 1> knownStatus{{ 400  }};
    if(std::find(std::begin(knownStatus), std::end(knownStatus), status) == std::end(knownStatus))
        callbackId = 0;

    switch(callbackId) { 
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

uploadFileResponse::uploadFileResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : AbstractResponse(reply, invoker) {
}

uploadFileResponse* uploadFileResponse::onEmptyResponse(std::function<void(int)> fun) {
    AbstractResponse::onEmptyResponse(fun);
    return this;
}


bool uploadFileResponse::processResponse(int status, const QJsonValue & data) {
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

} //namespace responses

using namespace responses;


updatePetResponse* updatePet (AbstractApiInvoker* invoker,
        Optional<Pet> body) {

    QByteArray http_method = QByteArrayLiteral("PUT");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QStringList contentTypes = {
        "application/json","application/xml"
    };
    QString contentType = contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");


    

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new updatePetResponse(reply, invoker);

}

addPetResponse* addPet (AbstractApiInvoker* invoker,
        Optional<Pet> body) {

    QByteArray http_method = QByteArrayLiteral("POST");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;

    QUrlQuery formParams;

    QVariantMap headers;

    QStringList contentTypes = {
        "application/json","application/xml"
    };
    QString contentType = contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");


    

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new addPetResponse(reply, invoker);

}

findPetsByStatusResponse* findPetsByStatus (AbstractApiInvoker* invoker,
        Optional<QStringList> status) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/findByStatus")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;
    if(status) queryParams.addQueryItem("status", to_query_value(*status));

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new findPetsByStatusResponse(reply, invoker);

}

findPetsByTagsResponse* findPetsByTags (AbstractApiInvoker* invoker,
        Optional<QStringList> tags) {

    QByteArray http_method = QByteArrayLiteral("GET");
    QByteArray http_body;

    QString path = QString(QLatin1String("/pet/findByTags")).replace(QLatin1String("{format}"),"json");

    QUrlQuery queryParams;
    if(tags) queryParams.addQueryItem("tags", to_query_value(*tags));

    QUrlQuery formParams;

    QVariantMap headers;

    QString contentType(QLatin1String("application/json"));

    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new findPetsByTagsResponse(reply, invoker);

}

getPetByIdResponse* getPetById (AbstractApiInvoker* invoker,
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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new getPetByIdResponse(reply, invoker);

}

updatePetWithFormResponse* updatePetWithForm (AbstractApiInvoker* invoker,
        const QString& petId,
        Optional<QString> name,
        Optional<QString> status) {

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
    QString contentType = contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");


    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
            if(name)set_form_data(parts,"name", *name);
            if(status)set_form_data(parts,"status", *status);
    
    }
    else {
            if(name)formParams.addQueryItem("name", to_query_value(*name));
            if(status)formParams.addQueryItem("status", to_query_value(*status));
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new updatePetWithFormResponse(reply, invoker);

}

deletePetResponse* deletePet (AbstractApiInvoker* invoker,
        const qint64& petId,
        Optional<QString> api_key) {

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
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
    
    }
    else {
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new deletePetResponse(reply, invoker);

}

uploadFileResponse* uploadFile (AbstractApiInvoker* invoker,
        const qint64& petId,
        Optional<QString> additionalMetadata,
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
    QString contentType = contentTypes.isEmpty() ? contentTypes.first() : QLatin1String("application/json");


    

    

    QHttpMultiPart* parts = nullptr;
    if(contentType.startsWith(QLatin1String("multipart/form-data"))) {
            if(additionalMetadata)set_form_data(parts,"additionalMetadata", *additionalMetadata);
            if(file)set_form_data(parts,"file", file);
    
    }
    else {
            if(additionalMetadata)formParams.addQueryItem("additionalMetadata", to_query_value(*additionalMetadata));
    
    
    }

    auto reply = invoker->invoke(path, http_method, queryParams, headers, formParams, parts, contentType, http_body );
    return new uploadFileResponse(reply, invoker);

}

} //namespace PetApi




} /* namespace Swagger */
