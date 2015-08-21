#ifndef AK_SWAGGER_Order_H_
#define AK_SWAGGER_Order_H_

#include "SwaggerUtils.h"
#include <QStringList> //fixme

class QJsonObject;

#include <QDateTime>
#include <QString>


namespace swagger {

class Order {
    Q_GADGET
public:
    
    enum class Status {
         placed,
         approved,
         delivered,
        
    };
    Q_ENUMS(Status);

    
    Order(const qint64 & id = {},
        const qint64 & petId = {},
        const qint32 & quantity = {},
        const QDateTime & shipDate = {},
        const Status & status = {},
        const bool & complete = {});

    
    qint64 id() const;
    void setId(const qint64 & id);


    qint64 petId() const;
    void setPetId(const qint64 & petId);


    qint32 quantity() const;
    void setQuantity(const qint32 & quantity);


    QDateTime shipDate() const;
    void setShipDate(const QDateTime & shipDate);


    Status status() const;
    void setStatus(const Status & status);


    bool complete() const;
    void setComplete(const bool & complete);


    QJsonObject serialize() const;
    static boost::optional<Order> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    qint64 m_petId;
    qint32 m_quantity;
    QDateTime m_shipDate;
    Status m_status;
    bool m_complete;
};


SWAGGER_DECLARE_MODEL(Order);

SWAGGER_DECLARE_ENUM(Order, Status);

}

Q_DECLARE_METATYPE(swagger::Order);

#endif
