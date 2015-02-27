#ifndef _SWAGGER_API_INVOKER_
#define _SWAGGER_API_INVOKER_

#include <QObject>
#include <QUrlQuery>

class QHttpMultiPart;
class QNetworkReply;
class QNetworkAccessManager;
class QNetworkRequest;
class QIODevice;

namespace swagger {

class AbstractResponse;
class AbstractApiInvoker : public QObject {

public:
    AbstractApiInvoker(QObject* parent = nullptr);
    virtual QNetworkReply* invoke(const QString & path, const QByteArray & method,
                                  QUrlQuery queryParams, QVariantMap headerParams,
                                  QUrlQuery formParams, QHttpMultiPart* parts,
                                  const QString & contentType, const QByteArray & body, QIODevice* device = 0);

    virtual QString getBasePath();
    virtual void onError(const AbstractResponse* const response);

protected:
    virtual QNetworkReply* invoke(QNetworkRequest && request, const QByteArray & method,
                                  const QByteArray & body, QHttpMultiPart* parts, QIODevice* device = 0) = 0;

};

class ApiInvoker : public AbstractApiInvoker {
public:
    ApiInvoker(QObject* parent = nullptr);

protected:
    QNetworkReply* invoke(QNetworkRequest && request, const QByteArray & method,
                          const QByteArray & body, QHttpMultiPart* parts, QIODevice* device = 0);

private:
    QNetworkAccessManager* m_nm;
};

}

#endif
