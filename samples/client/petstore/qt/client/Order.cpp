#include "Order.h"
#include <QJsonObject>
#include <QMetaEnum>

namespace swagger {


SWAGGER_REGISTER_ENUM(Order, Status);






Order::Order(const qint64 & id,
        const qint64 & petId,
        const qint32 & quantity,
        const QDateTime & shipDate,
        const Status & status,
        const bool & complete) {

    setId(id);
    setPetId(petId);
    setQuantity(quantity);
    setShipDate(shipDate);
    setStatus(status);
    setComplete(complete);
}


auto Order::id() const -> qint64 {
    return m_id;
}

void  Order::setId(const qint64 & id) {
    m_id = id;
}

auto Order::petId() const -> qint64 {
    return m_petId;
}

void  Order::setPetId(const qint64 & petId) {
    m_petId = petId;
}

auto Order::quantity() const -> qint32 {
    return m_quantity;
}

void  Order::setQuantity(const qint32 & quantity) {
    m_quantity = quantity;
}

auto Order::shipDate() const -> QDateTime {
    return m_shipDate;
}

void  Order::setShipDate(const QDateTime & shipDate) {
    m_shipDate = shipDate;
}

auto Order::status() const -> Status {
    return m_status;
}

void  Order::setStatus(const Status & status) {
    m_status = status;
}

auto Order::complete() const -> bool {
    return m_complete;
}

void  Order::setComplete(const bool & complete) {
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

boost::optional<Order> Order::unserialize(const QJsonObject & json) {
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
        auto v = swagger::unserialize<Status>(*it);
        if(v) obj.setStatus(*v);
    }
    if((it = json.find("complete")) != std::end(json)) {
        auto v = swagger::unserialize<bool>(*it);
        if(v) obj.setComplete(*v);
    }
    return obj;
}

} /* namespace Swagger */

