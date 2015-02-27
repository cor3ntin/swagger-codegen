#ifndef AK_SWAGGER_Category_H_
#define AK_SWAGGER_Category_H_

#include <boost/optional/optional.hpp>
#include <QStringList> //fixme

class QJsonObject;

#include <QString>


namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

class Category {
public:
    
    Category(qint64 id = {},
        const QString& name = {});

    qint64 getId() const;
    void setId( qint64  id);

    QString getName() const;
    void setName(const QString & name);


    QJsonObject serialize() const;
    static Optional<Category> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    QString m_name;
};


}

#endif
