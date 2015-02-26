#ifndef AK_SWAGGER_Tag_H_
#define AK_SWAGGER_Tag_H_

#include "SwaggerUtils.h"
#include <QStringList> //fixme

class QJsonObject;

#include <QString>


namespace swagger {

class Tag {
    
public:
    

    
    Tag(qint64 id = {},
        const QString& name = {});

    
    qint64 id() const;
    void setId(qint64 id);


    QString name() const;
    void setName(const QString& name);


    QJsonObject serialize() const;
    static boost::optional<Tag> unserialize(const QJsonObject & json);

private:
    qint64 m_id;
    QString m_name;
};

template <>
struct is_model<Tag> : std::true_type {};

}
Q_DECLARE_METATYPE(swagger::Tag);

#endif
