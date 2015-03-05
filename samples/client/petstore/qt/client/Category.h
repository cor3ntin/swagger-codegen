#ifndef AK_SWAGGER_Category_H_
#define AK_SWAGGER_Category_H_

#include "SwaggerUtils.h"
#include <QStringList> //fixme

class QJsonObject;

#include <QString>


namespace swagger {

class Category {
    
public:
    

    
    Category(const qint64 & id = {},
        const QString & name = {});

    
    qint64 id() const;
    void setId(const qint64 & id);


    QString name() const;
    void setName(const QString & name);


    QJsonObject serialize() const;
    static boost::optional<Category> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    QString m_name;
};


SWAGGER_DECLARE_MODEL(Category);

}

Q_DECLARE_METATYPE(swagger::Category);

#endif
