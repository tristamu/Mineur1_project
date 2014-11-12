#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QDir>
#include <QFileDialog>
#include "bookObject.h"
#include "database.h"


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
    QString curFileName;
    QDir curPath;


    BookObject * readLineinTable(int);
    void sauvegarder_second(void);

private slots:
    void nouveau();
    void fermer();
    void sauvegarder();
//    void setFilePath(QDir,QString);
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void on_pushButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_pushButton_2_clicked();

    //11 12

    void setCurFilePath();
    void openAFilePath();

};

#endif // MAINWINDOW_H
