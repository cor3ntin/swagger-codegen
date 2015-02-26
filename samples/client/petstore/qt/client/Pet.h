#ifndef AK_SWAGGER_Pet_H_
#define AK_SWAGGER_Pet_H_

#include "SwaggerUtils.h"
#include <QStringList> //fixme

class QJsonObject;

#include <QString>
#include "Category.h"
#include "Tag.h"
#include <QVector>


namespace swagger {

class Pet {
    Q_GADGET
public:
    
    enum class Status {
         available,
         pending,
         sold,
        
    };
    Q_ENUMS(Status);

    Pet();
    Pet(const QString& name,
        const QStringList& photoUrls,
        qint64 id = {},
        const Category& category = {},
        const QVector<Tag>& tags = {},
        Status status = {});

    
    QString name() const;
    void setName(const QString& name);


    QStringList photoUrls() const;
    void setPhotoUrls(const QStringList& photoUrls);


    qint64 id() const;
    void setId(qint64 id);


    Category category() const;
    void setCategory(const Category& category);


    QVector<Tag> tags() const;
    void setTags(const QVector<Tag>& tags);


    Status status() const;
    void setStatus(Status status);


    QJsonObject serialize() const;
    static boost::optional<Pet> unserialize(const QJsonObject & json);

private:
    QString m_name;
    QStringList m_photoUrls;
    qint64 m_id;
    Category m_category;
    QVector<Tag> m_tags;
    Status m_status;
};

template <>
struct is_model<Pet> : std::true_type {};

}
Q_DECLARE_METATYPE(swagger::Pet);

#endif
