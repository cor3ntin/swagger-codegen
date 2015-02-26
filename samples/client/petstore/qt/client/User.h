#ifndef AK_SWAGGER_User_H_
#define AK_SWAGGER_User_H_

#include "SwaggerUtils.h"
#include <QStringList> //fixme

class QJsonObject;

#include <QString>


namespace swagger {

class User {
    
public:
    

    
    User(qint64 id = {},
        const QString& username = {},
        const QString& firstName = {},
        const QString& lastName = {},
        const QString& email = {},
        const QString& password = {},
        const QString& phone = {},
        qint32 userStatus = {});

    
    qint64 id() const;
    void setId(qint64 id);


    QString username() const;
    void setUsername(const QString& username);


    QString firstName() const;
    void setFirstName(const QString& firstName);


    QString lastName() const;
    void setLastName(const QString& lastName);


    QString email() const;
    void setEmail(const QString& email);


    QString password() const;
    void setPassword(const QString& password);


    QString phone() const;
    void setPhone(const QString& phone);


    qint32 userStatus() const;
    void setUserStatus(qint32 userStatus);


    QJsonObject serialize() const;
    static boost::optional<User> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    QString m_username;
    QString m_firstName;
    QString m_lastName;
    QString m_email;
    QString m_password;
    QString m_phone;
    qint32 m_userStatus;
};

template <>
struct is_model<User> : std::true_type {};

}
Q_DECLARE_METATYPE(swagger::User);

#endif
