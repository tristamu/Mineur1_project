#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<iostream>
QString tableItems[4]={"Author","Title","ISBN","Year"};




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ligne = -1; // to add a row in a blank table
    colonne = 0;
    ui->setupUi(this);
    ui->menuBar->show();
    ui->tableWidget->hide();
    fDialog = new FilePathDialog();
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(nouveau()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(fermer()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(sauvegarder()));
    connect(ui->actionSave_as, SIGNAL(triggered()), fDialog, SLOT(open()));
    connect(fDialog, SIGNAL(accepted()), fDialog, SLOT(startsauvegarder()));
    bookTemp = new BookObject();
    bookTemp->InitialTableAttributes(tableItems,4);
    targetDatabase = new DatabaseManager();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::nouveau()
{
     statusBar()->showMessage(tr("Table created"),2000);
     ui->tableWidget->show();
     ui->tableWidget->showGrid();

}
void MainWindow::fermer(){
    statusBar()->showMessage(tr("Table closed"),2000);
    ui->tableWidget->hide();
    ui->tableWidget->showGrid();
}


BookObject * MainWindow:: readLineinTable(int lineNum)
{
    int cntCol=0;
    QTableWidgetItem *tmpItem;
    BookObject *resBook=new BookObject;
    resBook->id=-1;

    for(;cntCol<4;cntCol++)
    {
        tmpItem=ui->tableWidget->item(lineNum,cntCol);
        qDebug()<<"readLine "<<lineNum<<" col "<< cntCol <<" and the item " <<tmpItem;
        if(tmpItem != 0)
        {
           if(resBook->id==-1)
           {
               resBook->id = lineNum;
           }
           resBook->setAttribute(cntCol,tableItems[tmpItem->column()],tmpItem->text());
        }


    }
    return resBook;

}


void MainWindow::sauvegarder(){
    int count=0;
    statusBar()->showMessage(tr("Table saving"),2000);
    curFileName = fDialog->validFileName;
    curPath=fDialog->validFileDir;
    qDebug()<<"----curFileName"<<curPath.path();
    qDebug()<<"---curPath"<<curFileName;
    targetDatabase->openDB(curPath,curFileName);
    targetDatabase->createLibraryTable();


    for(;count<=ligne;count++)
    {
        std::cout<<"coming into the for"<<std::endl;
        bookTemp=readLineinTable(count);
        if(bookTemp->id!=-1)
        {
            targetDatabase->saveBook(bookTemp);
        }

    }

}

void MainWindow::on_pushButton_clicked()
{
    ligne++;
    ui->tableWidget->insertRow(ligne);
    std::cout<<"----ligne is "<<ligne;

}

void MainWindow::on_pushButton_2_clicked()
{
     ui->tableWidget->removeRow(ligne);
     if(ligne == 0) // allows to add a new row when all rows are deleted
         ligne--;
}

// update the coordinates of the cell selected
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ligne = row;
    colonne = column;
    std::cout << "row: "<< ligne << ", colonne: " << colonne << std::endl;
}


void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *curItem)
{
    QVariant enterStr = curItem->text();
    int enterIndex = curItem->column();
    QString enterItem;
    if(enterIndex<4)
        {
           enterItem = tableItems[enterIndex];

        }


    if(enterStr!=NULL)
    {

        if(bookTemp->id == -1 || bookTemp->id != curItem->row() )
        {
           bookTemp->save();
           bookTemp->InitialTableAttributes(tableItems,4);
           bookTemp->id = curItem->row();
           bookTemp->setAttribute(enterIndex,enterItem,enterStr);
           qDebug()<<"item is  "+bookTemp->indexAttribute(enterIndex)->name;
           qDebug()<<"text is  "<<bookTemp->indexAttributeValue(enterIndex);
         }

    }



}
