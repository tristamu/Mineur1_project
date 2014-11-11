#include "bookObject.h"

#include <iostream>
using namespace std;

BookObject::BookObject(QString aName,int anId):PersistentObject(aName,anId)
{

}



BookObject::BookObject(void):PersistentObject(){
   // id =-1;
}

void BookObject::InitialTableAttributes(QString *table, int tablelength){

    PersistentAttribute* tmp;
    int i;
    QString attributename;
    QVariant empty="";
    for(i=0;i<tablelength;i++)
    {
        attributename = table[i];
        tmp= new PersistentAttribute(attributename, empty);
        attributes->append(tmp);

    }


}


