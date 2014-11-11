#ifndef PERSISTENTATTRIBUTE_H
#define PERSISTENTATTRIBUTE_H

#include <QVariant>
class PersistentAttribute
{
public:
    QString name;
    QVariant variable;

PersistentAttribute(QString, QVariant);
~PersistentAttribute();
};

#endif // PERSISTENTATTRIBUTE_H
