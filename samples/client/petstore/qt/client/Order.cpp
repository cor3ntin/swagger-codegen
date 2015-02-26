#include "Order.h"
#include <QJsonObject>

#include "SwaggerUtils.h"

namespace swagger {

Order::Order()
    : m_id{ 0 }
    , m_petId{ 0 }
    , m_quantity{ 0 }
    , m_shipDate{ {} }
    , m_status{ QString::null }
    , m_complete{ false }  {
}

Order::Order(qint64 id,
        qint64 petId,
        qint32 quantity,
        const QDateTime& shipDate,
        const QString& status,
        bool complete) {

    setId(id);
    setPetId(petId);
    setQuantity(quantity);
    setShipDate(shipDate);
    setStatus(status);
    setComplete(complete);
}


qint64 Order::getId() const {
    return m_id;
}

void  Order::setId( qint64  id) {
    m_id = id;
}

qint64 Order::getPetId() const {
    return m_petId;
}

void  Order::setPetId( qint64  petId) {
    m_petId = petId;
}

qint32 Order::getQuantity() const {
    return m_quantity;
}

void  Order::setQuantity( qint32  quantity) {
    m_quantity = quantity;
}

QDateTime Order::getShipDate() const {
    return m_shipDate;
}

void  Order::setShipDate(const QDateTime & shipDate) {
    m_shipDate = shipDate;
}

QString Order::getStatus() const {
    return m_status;
}

void  Order::setStatus(const QString & status) {
    m_status = status;
}

bool Order::getComplete() const {
    return m_complete;
}

void  Order::setComplete( bool  complete) {
    m_complete = complete;
}



QJsonObject Order::serialize() const {
    QJsonObject json;

    json.insert("id", swagger::serialize(m_id));
    json.insert("petId", swagger::serialize(m_petId));
    json.insert("quantity", swagger::serialize(m_quantity));
    json.insert("shipDate", swagger::serialize(m_shipDate));
    json.insert("status", swagger::serialize(m_status));
    json.insert("complete", swagger::serialize(m_complete));
    
    return json;
}

Optional<Order> Order::unserialize(const QJsonObject & json) {
    auto it = json.end();
    Order obj;
    if((it = json.find("id")) != std::end(json)) {
        auto v = swagger::unserialize<qint64>(*it);
        if(v) obj.setId(*v);
    }
    if((it = json.find("petId")) != std::end(json)) {
        auto v = swagger::unserialize<qint64>(*it);
        if(v) obj.setPetId(*v);
    }
    if((it = json.find("quantity")) != std::end(json)) {
        auto v = swagger::unserialize<qint32>(*it);
        if(v) obj.setQuantity(*v);
    }
    if((it = json.find("shipDate")) != std::end(json)) {
        auto v = swagger::unserialize<QDateTime>(*it);
        if(v) obj.setShipDate(*v);
    }
    if((it = json.find("status")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setStatus(*v);
    }
    if((it = json.find("complete")) != std::end(json)) {
        auto v = swagger::unserialize<bool>(*it);
        if(v) obj.setComplete(*v);
    }
    return obj;
}

} /* namespace Swagger */

