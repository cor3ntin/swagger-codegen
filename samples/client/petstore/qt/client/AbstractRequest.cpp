#include "AbstractResponse.h"
#include "ApiInvoker.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

namespace swagger {

AbstractRequest::AbstractRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes)
    : m_reply(nullptr)
    , m_error(NoError)
    , m_params(params)
    , m_invoker(invoker)
    , m_authSchemes(authSchemes)
    , m_autoDelete(true) {

        connect(m_invoker, &QObject::destroyed, this, &QObject::deleteLater);

}

void AbstractRequest::send() {
    if(m_reply && !m_reply->isFinished())
        return;
    auto result = m_invoker->invoke(m_params, m_authSchemes);
    if(result.reply) {
        if(m_reply)
            m_reply->deleteLater();
        m_reply = result.reply;
        connect(m_reply, &QNetworkReply::finished, this, &AbstractRequest::onReplyFinished);
        m_error = NoError;
    }
    else if(result.error == AbstractApiInvoker::InvokeResult::AuthSchemeNotReady) {
        connect(m_invoker, &AbstractApiInvoker::authSchemesConfigurationChanged,
            this, &AbstractRequest::send);
    }
    else {
        m_error = AuthSchemeUnavailable;
        Q_EMIT failed(m_error);
    }
}

AbstractRequest::~AbstractRequest() {
    if(m_reply)
        m_reply->deleteLater();
}

quint16 AbstractRequest::status() const {
    if(!isFinished())
        return 0;
    return m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
}

quint32 AbstractRequest::duration() const {
    if(!isFinished())
        return 0;
    return m_reply->rawHeader("x-duration").toInt(); //returns 0 if fail
}

bool AbstractRequest::hasHeader(const QByteArray & key) const {
    return m_reply ? m_reply->hasRawHeader(key) : false;
        return false;
}

QByteArray AbstractRequest::header(const QByteArray & key) const {
    return m_reply ? m_reply->rawHeader(key) : QByteArray();
}

bool AbstractRequest::isFinished() const {
    return m_reply && m_reply->isFinished();
}

bool AbstractRequest::success() const {
    auto s = status();
    return m_reply && m_reply->error() == QNetworkReply::NoError
    && s >= 200 && s< 300;
}

AbstractRequest::Error AbstractRequest::error() const {
    return m_error;
}

void AbstractRequest::setAutoDetete(bool b) {
    m_autoDelete = b;
}

void AbstractRequest::onReplyFinished() {
    QJsonDocument doc;
    if( m_reply->error() != 0 && (m_reply->error() < 200
        || m_reply->error() == QNetworkReply::ContentReSendError || m_reply->error() >= 300))

        m_error = NetworkError;

    if(m_error == NoError) {
        QByteArray result = m_reply->readAll().simplified();
        if(result == "null")
            result.clear();
        QJsonParseError error;
        doc = QJsonDocument::fromJson(result, &error);
        if(error.error != QJsonParseError::NoError) {
            qWarning() << error.errorString();
            m_error = InvalidResponse;
        }

        QJsonValue v;
        if(doc.isObject())
            v = doc.object();
        else if(doc.isArray())
            v = doc.array();


        m_error = processResponse(status(), v);
    }
    if(m_error != NoError) {
        Q_EMIT failed(m_error);
    }

    if(m_autoDelete)
        connect(this, &AbstractRequest::done, this, &QObject::deleteLater);

    Q_EMIT done();
}

}

