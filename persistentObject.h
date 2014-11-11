#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include "persistentAttribute.h"
class PersistentObject
{
protected:
    QList<PersistentAttribute *> *attributes;
    QString table;

public:
    int id;
    PersistentObject(QString,int);
    PersistentObject(void);
    ~PersistentObject();
    void addAttribute(PersistentAttribute *);
    void addAttribute(QString, QString);
    void setAttribute(int, QString, QVariant);
    void cleanSelf();
    int save();
    PersistentAttribute* indexAttribute(int);
    QVariant indexAttributeValue(int);

};

#endif // PERSISTENTOBJECT_H
