#include "ApiInvoker.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSslError>

#include "AbstractResponse.h"
#include "SwaggerUtils.h"

namespace swagger {


AbstractApiInvoker::AbstractApiInvoker(QObject* parent)
    : QObject(parent) {
}


QString AbstractApiInvoker::getBasePath() {
    return QStringLiteral("http://petstore.swagger.io/v2");
}

template <typename First>
bool multi_xor(First f) {
    return f;
}

template <typename First, typename... Args>
bool multi_xor(First f, Args... args) {
    bool xxor = multi_xor(args...);
    return (f ? true : false) != xxor;
}

AbstractApiInvoker::RequestParams AbstractApiInvoker::prepare(const QString & path, const QByteArray & method,
                      QUrlQuery queryParams, QVariantMap headerParams,
                      QUrlQuery formParams, QHttpMultiPart* parts,
                      const QString & contentType, const QByteArray & body, QIODevice* device) {

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
        || ((method == "POST" || method == "PUT") &&
        multi_xor(formParams.isEmpty(), parts, body.isEmpty(), device))
    );

    return std::make_tuple(req, method,
                           formParams.isEmpty() ? body : formParams.toString().toUtf8(),
                           parts, device);

}

AbstractApiInvoker::InvokeResult AbstractApiInvoker::invoke(const RequestParams &params, const AuthSchemes & authSchemes) {
    InvokeResult result = invoke(std::get<0>(params),
                  authSchemes,
                  std::get<1>(params),
                  std::get<2>(params),
                  std::get<3>(params),
                  std::get<4>(params));

    if(result.reply)
        connect(result.reply, SIGNAL(sslErrors(const QList<QSslError>)), this, SLOT(onSslErrors(QList<QSslError>)));

    return result;
}

void AbstractApiInvoker::onError(const AbstractResponse* const) {

}

void AbstractApiInvoker::onSslErrors( const QList<QSslError> & errors ) {
    Q_FOREACH(const QSslError & e, errors) {
        logSwaggerError() << e.errorString() << e.error();
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
        if(reply)
            reply->ignoreSslErrors(errors);
    }
}

ApiInvoker::ApiInvoker(QObject* parent)
    : AbstractApiInvoker(parent)
    , m_nm(new QNetworkAccessManager(this)) {
}

AbstractApiInvoker::InvokeResult ApiInvoker::invoke(QNetworkRequest request, const AuthSchemes & authSchemes, const QByteArray & method,
                                  const QByteArray & body, QHttpMultiPart* parts, QIODevice* device) {

    if(!authSchemes.isEmpty())
        return {nullptr, InvokeResult::AuthSchemeUnavailable};

    if(method == "GET") {
        return m_nm->get(request);
    }
    if(method == "POST") {
        if(parts)
            return m_nm->post(request, parts);
        if(device)
            return m_nm->post(request, device);
        return m_nm->post(request, body);
    }
    if(method == "PUT") {
        if(parts)
            return m_nm->put(request, parts);
        if(device)
            return m_nm->put(request, device);
        return m_nm->put(request, body);
    }
    if(method == "DELETE") {
        return m_nm->deleteResource(request);
    }
    if(method == "OPTIONS") {
        return m_nm->sendCustomRequest(request, "OPTIONS");
    }
    return InvokeResult{nullptr};
}



}
