#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *today = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/today.png"),"Мой день");
    ui->listWidget->insertItem(ui->listWidget->count(), today);

    QListWidgetItem *favourites = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/star.png"),"Избранное");
    ui->listWidget->insertItem(ui->listWidget->count(), favourites);

    QListWidgetItem *all = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/list.png"),"Задачи");
    ui->listWidget->insertItem(ui->listWidget->count(), all);
    QFont newFont("Courier", 14);
    ui->listWidget->setFont(newFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QListWidgetItem *newItem = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/point'.png"),"Новый список");
    ui->listWidget->insertItem(ui->listWidget->count(), newItem);

}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    ui->lineEdit->setText(ui->listWidget->currentItem()->text());
    QFont newFont("Courier", 14);
    ui->lineEdit->setFont(newFont);
}

void MainWindow::on_pushButton_2_clicked()
{

}
