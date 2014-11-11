#include "mainwindow.h"
#include "filepathdialog.h"
#include "database.h"
#include "persistentAttribute.h"
#include "persistentObject.h"
#include <QApplication>
#include <QtSql>
#include <QObject>

#include<iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    //FilePathDialog fDialog;
   // fDialog.open();
    w.setWindowTitle("Information Table");
    w.show();
    QVariant v("hello");
    //qDebug()<<v.toString();
    //cout << v.typeName() << endl;
    DatabaseManager db;
    db.openDB();
    db.createLibraryTable();

    QString qs="hello";
    db.insertRecord(qs,qs,8,1991);
    db.insertRecord(qs,qs,9,1991);

    PersistentAttribute *attribut=new PersistentAttribute("sys",v);
    PersistentObject pObjet(qs,5);
    pObjet.addAttribute(attribut);
    cout << pObjet.save() << endl;
    db.deleteDB();
    return app.exec();
}

