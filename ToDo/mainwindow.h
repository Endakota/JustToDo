#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "todoclass.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_clicked(const QModelIndex &index);


    void on_addTask_clicked();


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
