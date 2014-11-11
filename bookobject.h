#ifndef BOOKOBJECT_H
#define BOOKOBJECT_H

#include "persistentObject.h"

class BookObject:public PersistentObject
{
   public:
      BookObject(QString aName,int anId);
      BookObject(void);
      void InitialTableAttributes(QString *,int);


};

#endif // BOOKOBJECT_H
