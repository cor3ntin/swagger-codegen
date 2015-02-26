#include "AbstractResponse.h"
#include "ApiInvoker.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

namespace swagger {

AbstractResponse::AbstractResponse(QNetworkReply* reply, AbstractApiInvoker* invoker)
    : m_reply(reply)
    , m_invoker(invoker) {

    Q_ASSERT(m_reply);
    connect(m_reply, &QNetworkReply::finished, this, &AbstractResponse::onReplyFinished);
    m_reply->setParent(this);
}

AbstractResponse::~AbstractResponse() {
    m_reply->deleteLater();
}

quint16 AbstractResponse::status() const {
    if(!isFinished())
        return 0;
    return m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
}

quint32 AbstractResponse::duration() const {
    if(!isFinished())
        return 0;
    return m_reply->rawHeader("x-duration").toInt(); //returns 0 if fail
}

bool AbstractResponse::isFinished() const {
    return m_reply->isFinished();
}

bool AbstractResponse::success() const {
    auto s = status();
    return m_reply->error() == QNetworkReply::NoError
        && s >= 200 && s< 300;
}

AbstractResponse* AbstractResponse::onEmptyResponse(std::function<void(int)> fun) {
    m_empty_response_function = fun;
    return this;
}

void AbstractResponse::onReplyFinished() {
    bool hasError = false;
    QJsonDocument doc;
    if(m_reply->error() != QNetworkReply::NoError)
        hasError = true;
    else {
        QByteArray result = m_reply->readAll();
        QJsonParseError error;
        doc = QJsonDocument::fromJson(result, &error);
        if(error.error != QJsonParseError::NoError) {
            qWarning() << error.errorString();
            hasError = true;
        }
    }
    QJsonValue v;
    if(doc.isObject())
        v = doc.object();
    else if(doc.isArray())
        v = doc.array();

    if(!hasError && !v.isNull() && !v.isUndefined()) {
        bool handled = processResponse(status(), v);
        if(!handled) {
            //TODO
        }
    }
    else {
        m_invoker->onError(this);
    }
    if(!parent())
        deleteLater();
}

}

