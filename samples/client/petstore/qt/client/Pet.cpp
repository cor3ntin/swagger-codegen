#include "Pet.h"
#include <QJsonObject>

#include "SwaggerUtils.h"

namespace swagger {

Pet::Pet()
    : m_name{}
    , m_photoUrls{}
    , m_id{}
    , m_category{}
    , m_tags{}
    , m_status{}  {
}

Pet::Pet(const QString& name,
        const QStringList& photoUrls,
        qint64 id,
        const Category& category,
        const QVector<Tag>& tags,
        const QString& status) {

    setName(name);
    setPhotoUrls(photoUrls);
    setId(id);
    setCategory(category);
    setTags(tags);
    setStatus(status);
}


QString Pet::getName() const {
    return m_name;
}

void  Pet::setName(const QString & name) {
    m_name = name;
}

QStringList Pet::getPhotoUrls() const {
    return m_photoUrls;
}

void  Pet::setPhotoUrls(const QStringList & photoUrls) {
    m_photoUrls = photoUrls;
}

qint64 Pet::getId() const {
    return m_id;
}

void  Pet::setId( qint64  id) {
    m_id = id;
}

Category Pet::getCategory() const {
    return m_category;
}

void  Pet::setCategory(const Category & category) {
    m_category = category;
}

QVector<Tag> Pet::getTags() const {
    return m_tags;
}

void  Pet::setTags(const QVector<Tag> & tags) {
    m_tags = tags;
}

QString Pet::getStatus() const {
    return m_status;
}

void  Pet::setStatus(const QString & status) {
    m_status = status;
}



QJsonObject Pet::serialize() const {
    QJsonObject json;

    json.insert("name", swagger::serialize(m_name));
    json.insert("photoUrls", swagger::serialize(m_photoUrls));
    json.insert("id", swagger::serialize(m_id));
    json.insert("category", swagger::serialize(m_category));
    json.insert("tags", swagger::serialize(m_tags));
    json.insert("status", swagger::serialize(m_status));
    
    return json;
}

Optional<Pet> Pet::unserialize(const QJsonObject & json) {
    auto it = json.end();
    Pet obj;
    if((it = json.find("name")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(!v) return {};
        obj.setName(*v);
    }
    else return {};
    if((it = json.find("photoUrls")) != std::end(json)) {
        auto v = swagger::unserialize<QStringList>(*it);
        if(!v) return {};
        obj.setPhotoUrls(*v);
    }
    else return {};
    if((it = json.find("id")) != std::end(json)) {
        auto v = swagger::unserialize<qint64>(*it);
        if(v) obj.setId(*v);
    }
    if((it = json.find("category")) != std::end(json)) {
        auto v = swagger::unserialize<Category>(*it);
        if(v) obj.setCategory(*v);
    }
    if((it = json.find("tags")) != std::end(json)) {
        auto v = swagger::unserialize<QVector<Tag>>(*it);
        if(v) obj.setTags(*v);
    }
    if((it = json.find("status")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setStatus(*v);
    }
    return obj;
}

} /* namespace Swagger */

