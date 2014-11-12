#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "bookObject.h"
#include "database.h"
#include "filepathdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    int ligne, colonne;
    BookObject *bookTemp;
    DatabaseManager *targetDatabase;
    FilePathDialog *fDialog;
    QString curFileName;
    QDir curPath;


    BookObject * readLineinTable(int);


private slots:
    void nouveau();
    void fermer();
    void sauvegarder();
//    void setFilePath(QDir,QString);
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void on_pushButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_pushButton_2_clicked();

};

#endif // MAINWINDOW_H
