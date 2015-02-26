#ifndef AK_SWAGGER_Category_H_
#define AK_SWAGGER_Category_H_

#include "SwaggerUtils.h"
#include <QStringList> //fixme

class QJsonObject;

#include <QString>


namespace swagger {

class Category {
    
public:
    

    
    Category(qint64 id = {},
        const QString& name = {});

    
    qint64 id() const;
    void setId(qint64 id);


    QString name() const;
    void setName(const QString& name);


    QJsonObject serialize() const;
    static boost::optional<Category> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    QString m_name;
};

template <>
struct is_model<Category> : std::true_type {};

}
Q_DECLARE_METATYPE(swagger::Category);

#endif
