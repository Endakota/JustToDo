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

protected slots:
    void on_pushButton_clicked();

    void on_listWidget_clicked();


    void on_addTask_clicked();
    virtual void closeEvent(QCloseEvent *event);
    void ShowContextMenu(const QPoint& pos);
    void on_action_1();

    void ShowContextTask(const QPoint& pos);
    void deleteTask();
    void add2Fav();
    void add2Day();
    void doneTask();
private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
