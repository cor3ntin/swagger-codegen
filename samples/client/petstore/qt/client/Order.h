#ifndef AK_SWAGGER_Order_H_
#define AK_SWAGGER_Order_H_

#include <boost/optional/optional.hpp>
#include <QStringList> //fixme

class QJsonObject;

#include <QDateTime>
#include <QString>


namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

class Order {
public:
    
    Order(qint64 id = {},
        qint64 petId = {},
        qint32 quantity = {},
        const QDateTime& shipDate = {},
        const QString& status = {},
        bool complete = {});

    qint64 getId() const;
    void setId( qint64  id);

    qint64 getPetId() const;
    void setPetId( qint64  petId);

    qint32 getQuantity() const;
    void setQuantity( qint32  quantity);

    QDateTime getShipDate() const;
    void setShipDate(const QDateTime & shipDate);

    QString getStatus() const;
    void setStatus(const QString & status);

    bool getComplete() const;
    void setComplete( bool  complete);


    QJsonObject serialize() const;
    static Optional<Order> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    qint64 m_petId;
    qint32 m_quantity;
    QDateTime m_shipDate;
    QString m_status;
    bool m_complete;
};


}

#endif
