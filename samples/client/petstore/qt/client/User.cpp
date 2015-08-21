#include "User.h"
#include <QJsonObject>


namespace swagger {







User::User(const qint64 & id,
        const QString & username,
        const QString & firstName,
        const QString & lastName,
        const QString & email,
        const QString & password,
        const QString & phone,
        const qint32 & userStatus) {

    setId(id);
    setUsername(username);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setPassword(password);
    setPhone(phone);
    setUserStatus(userStatus);
}


auto User::id() const -> qint64 {
    return m_id;
}

void  User::setId(const qint64 & id) {
    m_id = id;
}

auto User::username() const -> QString {
    return m_username;
}

void  User::setUsername(const QString & username) {
    m_username = username;
}

auto User::firstName() const -> QString {
    return m_firstName;
}

void  User::setFirstName(const QString & firstName) {
    m_firstName = firstName;
}

auto User::lastName() const -> QString {
    return m_lastName;
}

void  User::setLastName(const QString & lastName) {
    m_lastName = lastName;
}

auto User::email() const -> QString {
    return m_email;
}

void  User::setEmail(const QString & email) {
    m_email = email;
}

auto User::password() const -> QString {
    return m_password;
}

void  User::setPassword(const QString & password) {
    m_password = password;
}

auto User::phone() const -> QString {
    return m_phone;
}

void  User::setPhone(const QString & phone) {
    m_phone = phone;
}

auto User::userStatus() const -> qint32 {
    return m_userStatus;
}

void  User::setUserStatus(const qint32 & userStatus) {
    m_userStatus = userStatus;
}



QJsonObject User::serialize() const {
    QJsonObject json;

    
    json.insert("id", swagger::serialize(m_id));
    
    json.insert("username", swagger::serialize(m_username));
    
    json.insert("firstName", swagger::serialize(m_firstName));
    
    json.insert("lastName", swagger::serialize(m_lastName));
    
    json.insert("email", swagger::serialize(m_email));
    
    json.insert("password", swagger::serialize(m_password));
    
    json.insert("phone", swagger::serialize(m_phone));
    
    json.insert("userStatus", swagger::serialize(m_userStatus));
    
    return json;
}

boost::optional<User> User::unserialize(const QJsonObject & json) {
    auto it = json.end();
    User obj;
    if((it = json.find("id")) != std::end(json)) {
        auto v = swagger::unserialize<qint64>(*it);
        if(v) obj.setId(*v);
    }
    if((it = json.find("username")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setUsername(*v);
    }
    if((it = json.find("firstName")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setFirstName(*v);
    }
    if((it = json.find("lastName")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setLastName(*v);
    }
    if((it = json.find("email")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setEmail(*v);
    }
    if((it = json.find("password")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setPassword(*v);
    }
    if((it = json.find("phone")) != std::end(json)) {
        auto v = swagger::unserialize<QString>(*it);
        if(v) obj.setPhone(*v);
    }
    if((it = json.find("userStatus")) != std::end(json)) {
        auto v = swagger::unserialize<qint32>(*it);
        if(v) obj.setUserStatus(*v);
    }
    return obj;
}

} /* namespace Swagger */

