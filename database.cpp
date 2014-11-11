#include"database.h"

#include <QVariant>
#include <iostream>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent): QObject(parent){
    db = QSqlDatabase();
}

DatabaseManager::~DatabaseManager(){
    std::cout << "destructor of database\n";
}

bool DatabaseManager::openDB(){
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");//driver sqlite

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("hao.db");//("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);
    #else
    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    db.setDatabaseName("E:\\projet\\cours_c\\QT_project\\test.db");
    #endif

    // Open databasee
    bool ouvrir = db.open();
    if( !ouvrir )
    {
      qDebug() << db.lastError();
      qFatal( "Failed to connect." );
    }

    qDebug( "Connected!" );
    return ouvrir;
}

bool DatabaseManager::openDB(QDir basepath,QString fileName)
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");//driver sqlite

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("hao.db");//("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);
    #else
    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    db.setDatabaseName(basepath.path()+fileName);
    #endif

    // Open databasee
    bool ouvrir = db.open();
    if( !ouvrir )
    {
      qDebug() << db.lastError();
      qFatal( "Failed to connect." );
    }

    qDebug( "Connected!" );
    return ouvrir;

}


bool DatabaseManager::createLibraryTable(){
    // Create table "library"
    bool ret = false;
    QSqlQuery query;
    if (db.isOpen())
        {
        ret = query.exec("CREATE TABLE IF NOT EXISTS library"
                  "(author varchar(20), "
                  "title varchar(20), "
                  "isbn integer primary key, "
                  "year integer)");

        }
    if( !ret )
      qDebug() << query.lastError();
    else
      qDebug() << "Table created!";
    return ret;
}

int DatabaseManager::insertRecord(QString author, QString title, int isbn, int year){
    int newId = -1;
    bool ret = false;

    if (db.isOpen()){
        //http://www.sqlite.org/autoinc.html
        // NULL = is the keyword for the autoincrement to generate next value

        QSqlQuery query;
        ret = query.exec(QString("INSERT INTO library VALUES('%1','%2','%3',%4)")
        .arg(author).arg(title).arg(isbn).arg(year));

        // Get database given autoincrement value
        if (ret){
            // http://www.sqlite.org/c3ref/last_insert_rowid.html
            newId = query.lastInsertId().toInt();
            qDebug( "Inserted!" );
        }else
            qDebug() << query.lastError();

    }
    return newId;
}



int DatabaseManager::saveBook(BookObject *theBook){

   // if(BookObjec) is the right table
    insertRecord(theBook->indexAttributeValue(0).toString(),theBook->indexAttributeValue(1).toString(),theBook->indexAttributeValue(2).toInt(),theBook->indexAttributeValue(3).toInt());
    return 1;
}


QSqlError DatabaseManager::lastError(){
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}

void DatabaseManager::deleteDB(){
    // Close database
    db.close();

    /*#ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("hao.db");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
    #else

    // Remove created database binary file
    return QFile::remove("my.db.sqlite");
    #endif*/
}
