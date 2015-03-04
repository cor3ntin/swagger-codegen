#ifndef _SWAGGER_API_INVOKER_
#define _SWAGGER_API_INVOKER_

#include <tuple>
#include <QObject>
#include <QUrlQuery>
#include <QNetworkRequest>

class QHttpMultiPart;
class QNetworkReply;
class QNetworkAccessManager;
class QIODevice;
class QSslError;

namespace swagger {

using AuthSchemes = QStringList;

class AbstractResponse;
class AbstractApiInvoker : public QObject {
    Q_OBJECT
public:
    using RequestParams = std::tuple<QNetworkRequest, QByteArray, QByteArray, QHttpMultiPart*, QIODevice*>;

    struct InvokeResult {
        QNetworkReply* reply;
        enum Error {
            NoError,
            AuthSchemeNotReady,
            AuthSchemeUnavailable
        } error = NoError;
        InvokeResult(QNetworkReply* reply, Error error = NoError)
            : reply(reply)
            , error(error)
        {}
    };


    AbstractApiInvoker(QObject* parent = nullptr);

    virtual RequestParams prepare(const QString & path, const QByteArray & method,
                      QUrlQuery queryParams, QVariantMap headerParams,
                      QUrlQuery formParams, QHttpMultiPart* parts,
                      const QString & contentType, const QByteArray & body, QIODevice* device = nullptr);

    InvokeResult invoke(const RequestParams & params, const AuthSchemes & authSchemes);


    virtual QString getBasePath();
    virtual void onError(const AbstractResponse* const response);

Q_SIGNALS:
    void authSchemesConfigurationChanged();

protected:
    virtual InvokeResult invoke(QNetworkRequest request, const AuthSchemes & authSchemes, const QByteArray & method,
                                  const QByteArray & body, QHttpMultiPart* parts, QIODevice* device = nullptr) = 0;
private Q_SLOTS:
    void onSslErrors( const QList<QSslError> & errors );

};

class ApiInvoker : public AbstractApiInvoker {
    Q_OBJECT
public:
    ApiInvoker(QObject* parent = nullptr);

protected:
    InvokeResult invoke(QNetworkRequest request, const AuthSchemes & authSchemes, const QByteArray & method,
                          const QByteArray & body, QHttpMultiPart* parts, QIODevice* device = nullptr);

private:
    QNetworkAccessManager* m_nm;
};

}

#endif