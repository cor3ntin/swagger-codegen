#include "Category.h"
#include <QJsonObject>


namespace swagger {







Category::Category(const qint64 & id,
        const QString & name) {

    setId(id);
    setName(name);
}


auto Category::id() const -> qint64 {
    return m_id;
}

void  Category::setId(const qint64 & id) {
    m_id = id;
}

auto Category::name() const -> QString {
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

boost::optional<Category> Category::unserialize(const QJsonObject & json) {
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

