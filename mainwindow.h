#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_columnView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *items;
    QString filePath;
    //QFile file;
};

#endif // MAINWINDOW_H
