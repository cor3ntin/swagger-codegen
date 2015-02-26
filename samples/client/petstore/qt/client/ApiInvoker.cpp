#include "ApiInvoker.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>

#include "AbstractResponse.h"
#include "SwaggerUtils.h"

namespace swagger {


AbstractApiInvoker::AbstractApiInvoker(QObject* parent)
    : QObject(parent) {
}

ApiInvoker::ApiInvoker(QObject* parent)
    : AbstractApiInvoker(parent)
    , m_nm(new QNetworkAccessManager(this)) {
}

QString AbstractApiInvoker::getBasePath() {
    return QStringLiteral("http://petstore.swagger.io/v2");
}

QNetworkReply* AbstractApiInvoker::invoke(const QString & path, const QByteArray & method,
                                  QUrlQuery queryParams, QVariantMap headerParams,
                                  QUrlQuery formParams, QHttpMultiPart* parts,
                                  const QString & contentType) {
    QUrl url;
    url.setUrl(getBasePath());
    url.setPath(url.path() + "/" + path);
    url.setQuery(queryParams);

    QNetworkRequest req(url);
    for(auto it = headerParams.cbegin(); it != headerParams.cend(); ++it) {
        req.setRawHeader(it.key().toUtf8(), it.value().toString().toUtf8());
    }

    req.setHeader(QNetworkRequest::ContentTypeHeader, contentType);

    Q_ASSERT(
        ((method == "GET"  || method == "DELETE" || method == "OPTIONS")
        && formParams.isEmpty() && !parts)
        || ((method == "POST" || method == "PUT") && formParams.isEmpty() != (parts == nullptr))
    );

    return invoke(std::move(req),
                  method,
                  formParams.isEmpty() ? QByteArray() : formParams.toString().toUtf8(),
                      parts);
}


void AbstractApiInvoker::onError(const AbstractResponse* const) {

}

QNetworkReply* ApiInvoker::invoke(QNetworkRequest && request, const QByteArray & method,
                                const QByteArray & body, QHttpMultiPart* parts) {

    if(method == "GET") {
        return m_nm->get(request);
    }
    if(method == "POST") {
        if(parts) {
            return m_nm->post(request, parts);
        }
        return m_nm->post(request, body);
    }
    if(method == "PUT") {
        if(parts) {
            return m_nm->put(request, parts);
        }
        return m_nm->put(request, body);
    }
    if(method == "DELETE") {
        return m_nm->deleteResource(request);
    }
    if(method == "OPTIONS") {
        return m_nm->sendCustomRequest(request, "OPTIONS");
    }
    return nullptr;
}

}
