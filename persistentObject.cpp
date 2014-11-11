#include"persistentObject.h"
#include<iostream>
#include<QDebug>
QString tItems[4]={"Author","Title","ISBN","Year"};

PersistentObject::PersistentObject(QString className,int isbn){
    attributes = new QList<PersistentAttribute *>();
    id = isbn;
    table = className;
}
PersistentObject::PersistentObject(void){
    attributes =new QList<PersistentAttribute *>();
//    attributes->at(0)->name = tItems[0];
//    attributes->at(1)->name = tItems[1];
//    attributes->at(2)->name = tItems[2];
//    attributes->at(3)->name = tItems[3];
    id = -1;
    table = "";
}


PersistentObject::~PersistentObject(){
    delete(attributes);
    std::cout << "destructor of persistantObject" << std::endl;
}
void PersistentObject::addAttribute(PersistentAttribute * attri){
    if(attributes!=NULL)
    {
        attributes->append(attri);

    }else

    std::cout << "persistentObject length is "<<attributes->length() << std::endl;
}

void PersistentObject::addAttribute(QString attriName, QString attriValue){
    //QVariant value("testValue");
    PersistentAttribute* tmp=new PersistentAttribute(attriName,attriValue);
    attributes->append(tmp);
    std::cout << "persistentObject length is "<<attributes->length() << std::endl;

}

void PersistentObject::setAttribute(int index, QString attriName, QVariant attriValue){

//   if(attributes->at(index) !=   NULL )//already existe
//   {
//        if(attriValue!=this->indexAttributeValue(index))
//        {
//            attributes->at(index)->variable = attriValue;//only change when is different
//        }
//   }else{    //not yet

//        PersistentAttribute* tmp=new PersistentAttribute(attriName,attriValue);
//        attributes->replace(index,tmp);
//    }
    PersistentAttribute* tmp=new PersistentAttribute(attriName,attriValue);
    attributes->append(tmp);
    std::cout << "-----persistentObject length is "<<attributes->length() << std::endl;

}


void PersistentObject::cleanSelf(){
    attributes->clear();
    id = -1;
    table = "";
}

int PersistentObject::save(){
    std::cout<<"id is "<<id<<std::endl;
    return id;
}


PersistentAttribute* PersistentObject::indexAttribute(int index)
{
    if(index< attributes->length() )
    {
        return (attributes->at(index));
    }else{
        return NULL;
    }
}


QVariant PersistentObject::indexAttributeValue(int index)
{
   QVariant value= attributes->at(index)->variable;
   // QVariant value ="hi";

    return value;
}
