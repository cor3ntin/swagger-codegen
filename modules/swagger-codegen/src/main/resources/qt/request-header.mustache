#ifndef _SWAGGER_RESPONSE_
#define _SWAGGER_RESPONSE_

#include <QObject>
#include <QSslError>
#include "ApiInvoker.h"

class QNetworkReply;
class QJsonValue;

namespace swagger {

class AbstractRequest : public QObject {
    Q_OBJECT
public:
    enum Error {
        NoError,
        AuthSchemeUnavailable,
        AuthenticationFailure,
        NetworkError,
        UnexpectedResponseCode,
        InvalidResponse,
        UnknownError
    };
    Q_ENUMS(Error);

    AbstractRequest(AbstractApiInvoker::RequestParams && params, AbstractApiInvoker* invoker, QStringList && authSchemes);
    virtual ~AbstractRequest();
    quint16 status() const;
    quint32 duration() const;
    bool isFinished() const;
    bool success() const;
    Error error() const;

    bool hasHeader(const QByteArray & key) const;
    QByteArray header(const QByteArray & key) const;

    QNetworkReply* reply() const;
    void setAutoDetete(bool);

public Q_SLOTS:
    void send();

Q_SIGNALS:
    void done();
    void failed(Error error);

protected:
    virtual AbstractRequest::Error processResponse(int status, const QJsonValue & data) = 0;
    QNetworkReply* m_reply;

private Q_SLOTS:
    void onReplyFinished();

private:
    Error m_error;
    AbstractApiInvoker::RequestParams m_params;
    AbstractApiInvoker* m_invoker;
    QStringList m_authSchemes;
    bool m_autoDelete;
};

}


#endif
