#include "Category.h"
#include <QJsonObject>

#include "SwaggerUtils.h"

namespace swagger {

Category::Category()
    : m_id{ 0 }
    , m_name{ QString::null }  {
}

Category::Category(qint64 id,
        const QString& name) {

    setId(id);
    setName(name);
}


qint64 Category::getId() const {
    return m_id;
}

void  Category::setId( qint64  id) {
    m_id = id;
}

QString Category::getName() const {
    return m_name;
}

void  Category::setName(const QString & name) {
    m_name = name;
}



QJsonObject Category::serialize() const {
    QJsonObject json;

    json.insert("id", swagger::serialize(m_id));
    json.insert("name", swagger::serialize(m_name));
    
    return json;
}

Optional<Category> Category::unserialize(const QJsonObject & json) {
    auto it = json.end();
    Category obj;
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

