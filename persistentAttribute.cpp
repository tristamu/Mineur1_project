#include "persistentAttribute.h"
#include<iostream>

 PersistentAttribute::PersistentAttribute(QString nom, QVariant var){
    name = nom;
    variable = var;

}

PersistentAttribute::~PersistentAttribute(){
    std::cout<< "destructor" << std::endl;
}
