#ifndef AK_SWAGGER_Pet_H_
#define AK_SWAGGER_Pet_H_

#include <boost/optional/optional.hpp>
#include <QStringList> //fixme

class QJsonObject;

#include <QString>
#include "Category.h"
#include "Tag.h"
#include <QVector>


namespace swagger {

template <typename T>
using Optional = boost::optional<T>;

class Pet {
public:
    Pet();
    Pet(const QString& name,
        const QStringList& photoUrls,
        qint64 id = {},
        const Category& category = {},
        const QVector<Tag>& tags = {},
        const QString& status = {});

    QString getName() const;
    void setName(const QString & name);

    QStringList getPhotoUrls() const;
    void setPhotoUrls(const QStringList & photoUrls);

    qint64 getId() const;
    void setId( qint64  id);

    Category getCategory() const;
    void setCategory(const Category & category);

    QVector<Tag> getTags() const;
    void setTags(const QVector<Tag> & tags);

    QString getStatus() const;
    void setStatus(const QString & status);


    QJsonObject serialize() const;
    static Optional<Pet> unserialize(const QJsonObject & json);

private:
    QString m_name;
    QStringList m_photoUrls;
    qint64 m_id;
    Category m_category;
    QVector<Tag> m_tags;
    QString m_status;
};


}

#endif
