#include "filepathdialog.h"
#include "ui_filepathdialog.h"
#include<QDebug>
#include <iostream>
#include <QRegExp>
QRegExp baseNameNom("(\\w).db$");//for windows  --- \ \w+ .db

FilePathDialog::FilePathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilePathDialog)
{
    ui->setupUi(this);
    validFileDir ="";
    validFileName="";

}

FilePathDialog::~FilePathDialog()
{
    delete ui;
}

void FilePathDialog::on_buttonBox_accepted()
{
    QString savepath,file;
    QDir dir;
    int pathEnd=-1;
    file = ui->pathFile->displayText();


    if(baseNameNom.lastIndexIn(file)!=-1)
    {
        pathEnd = file.lastIndexOf("\\")+1;
        savepath = file.left(pathEnd);

       qDebug()<<savepath;
       if(!dir.exists(savepath))
        {
           qDebug()<<"DO NOT EXIST!"; //alert message
        }else{
          // emit aValidFilePath(file);

           validFileDir=savepath;
           validFileName=file.right(file.length()-pathEnd);
           qDebug()<<"filePath"<<validFileDir.path();
           qDebug()<<"fileName"<<validFileName;
           accept();

        }
    }else{
        qDebug()<<"NOT valide file name!";
    }
}

void FilePathDialog::getCurrentFilePath(QString str)
{
    qDebug()<<"file path is "+str;
}


