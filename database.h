#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QSqlQuery>
#include "bookobject.h"
#include <QDir>
class DatabaseManager : public QObject
    {
    public:
        explicit DatabaseManager(QObject *parent = 0);
        ~DatabaseManager();

    public:
        bool openDB();
        bool openDB(QDir,QString);
        bool createLibraryTable();
        int insertRecord(QString , QString , int , int);
        void deleteDB();
        int saveBook(BookObject *);
        QSqlError lastError();

    private:
        QSqlDatabase db;
    };

#endif // DATABASE_H
