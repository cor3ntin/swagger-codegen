#include "Tag.h"
#include <QJsonObject>

#include "SwaggerUtils.h"

namespace swagger {



Tag::Tag(qint64 id,
        const QString& name) {

    setId(id);
    setName(name);
}


qint64 Tag::getId() const {
    return m_id;
}

void  Tag::setId( qint64  id) {
    m_id = id;
}

QString Tag::getName() const {
    return m_name;
}

void  Tag::setName(const QString & name) {
    m_name = name;
}



QJsonObject Tag::serialize() const {
    QJsonObject json;

    json.insert("id", swagger::serialize(m_id));
    json.insert("name", swagger::serialize(m_name));
    
    return json;
}

Optional<Tag> Tag::unserialize(const QJsonObject & json) {
    auto it = json.end();
    Tag obj;
    if((it = json.find("id")) != std::end(json)) {
        auto v = swagger::unserialize<qint64>(*it);
        if(v) obj.setId(*v);
    }
    if((it = json.find("name")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setName(*v);
    }
    return obj;
}

} /* namespace Swagger */

