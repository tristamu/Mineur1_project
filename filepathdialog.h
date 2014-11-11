#ifndef FILEPATHDIALOG_H
#define FILEPATHDIALOG_H

#include <QDialog>
#include <QFile>
 #include <QDir>
namespace Ui {
class FilePathDialog;
}

class FilePathDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::FilePathDialog *ui;
public:
    QString validFileName;
    QDir validFileDir;

public:
    explicit FilePathDialog(QWidget *parent = 0);
    ~FilePathDialog();
   // QString* theValidFilePath();

private slots:
    void on_buttonBox_accepted();

    void getCurrentFilePath(QString str);



};

#endif // FILEPATHDIALOG_H
