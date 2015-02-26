#ifndef AK_SWAGGER_User_H_
#define AK_SWAGGER_User_H_

#include <boost/optional/optional.hpp>
#include <QStringList> //fixme

class QJsonObject;

#include <QString>


namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

class User {
public:
    User();
    User(qint64 id = {},
        const QString& username = {},
        const QString& firstName = {},
        const QString& lastName = {},
        const QString& email = {},
        const QString& password = {},
        const QString& phone = {},
        qint32 userStatus = {});

    qint64 getId() const;
    void setId( qint64  id);

    QString getUsername() const;
    void setUsername(const QString & username);

    QString getFirstName() const;
    void setFirstName(const QString & firstName);

    QString getLastName() const;
    void setLastName(const QString & lastName);

    QString getEmail() const;
    void setEmail(const QString & email);

    QString getPassword() const;
    void setPassword(const QString & password);

    QString getPhone() const;
    void setPhone(const QString & phone);

    qint32 getUserStatus() const;
    void setUserStatus( qint32  userStatus);


    QJsonObject serialize() const;
    static Optional<User> unserialize(const QJsonObject & json);

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


}

#endif
