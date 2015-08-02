#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtConcurrent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString sPath;

    sPath = "/";
    items = new QFileSystemModel(this);
    items->setRootPath(sPath);
    ui->columnView->setModel(items);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
extern QString readFile(QFile f)
{
    QTextStream in(&f);
    QString content = in.readAll();
    return content;
}
*/

void MainWindow::on_columnView_activated(const QModelIndex &index)
{
    QFile file;
    QString filePath;
    QFuture<QString> future;

    filePath = items->fileInfo(index).absoluteFilePath();
    ui->label->setText(filePath.split("/").last());

    file.setFileName(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        ui->textEdit->setText("reading...");
        /*future = QtConcurrent::run(readFile, file);
        // thread done
        future.waitForFinished();
        ui->textEdit->setText(future.result());*/
        ui->textEdit->setText(file.readAll());
        file.close();
    }else{
        ui->textEdit->setText("Could not read file.");
    }
}
