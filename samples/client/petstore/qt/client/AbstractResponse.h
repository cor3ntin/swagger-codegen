#ifndef _SWAGGER_RESPONSE_
#define _SWAGGER_RESPONSE_

#include <QObject>

class QNetworkReply;
class QJsonValue;

namespace swagger {

class AbstractApiInvoker;

class AbstractResponse : public QObject {
    Q_OBJECT
public:
    AbstractResponse(QNetworkReply* reply, AbstractApiInvoker* invoker);
    virtual ~AbstractResponse();
    quint16 status() const;
    quint32 duration() const;
    bool isFinished() const;
    bool success() const;
    virtual AbstractResponse* onEmptyResponse(std::function<void(int)>);

protected:
    virtual bool processResponse(int status, const QJsonValue & data) = 0;
    std::function<void(int)> m_empty_response_function;

private Q_SLOTS:
    void onReplyFinished();
private:
    QNetworkReply* m_reply;
    AbstractApiInvoker* m_invoker;
};

}


#endif