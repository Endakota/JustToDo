#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <Qt>
#include <QMessageBox>
#include <vector>
#include "saving.h"
#include<iostream>
#include <QTableWidgetItem>

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
    QFont newFont("MS Shell Dlg 2", 8);
    ui->listWidget->setFont(newFont);
    ui->listWidget->setCurrentRow(2);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels({ui->listWidget->currentItem()->text()});

    Saving ads;
    std::vector<std::string> task_names = ads.Read();
    task_names.erase(task_names.begin());
    for(string l : task_names){
        QListWidgetItem *newItem = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/point'.png"),QString::fromStdString(l));
        ui->listWidget->insertItem(ui->listWidget->count(), newItem);
    }
    std::vector<std::string> readTask = ads.ReadTask();
    readTask.erase(readTask.begin());


    ui->tableWidget->clearContents();
    /*for(int i = 0; i < ui->tableWidget->rowCount();i++){
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1-i);
    }*/
    ui->tableWidget->setHorizontalHeaderLabels({ui->listWidget->currentItem()->text()});
    for(QListWidgetItem *item: ui->listWidget->selectedItems()){
        int row = ui->listWidget->row(item);
        for(string l : readTask){
            if(!std::to_string(row).compare(l.substr(0,1))){
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(l.substr(1))));
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int count = ui->listWidget->count()-3;
    Saving ads;
    if(count == 0){
        QListWidgetItem *newItem = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/point'.png"),"Новый список");
        ui->listWidget->insertItem(ui->listWidget->count(), newItem);

        ads.WriteSpiski("Новый список");
    }else{
        QListWidgetItem *newItem = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/point'.png"),"Новый список" + QString::number(count));
        ui->listWidget->insertItem(ui->listWidget->count(), newItem);
        ads.WriteSpiski("Новый список" + std::to_string(count));
    }
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    Saving ads;
    std::vector<std::string> readTask = ads.ReadTask();
    readTask.erase(readTask.begin());
    QFont newFont("MS Shell Dlg 2", 8);
    ui->task_line->setFont(newFont);
    ui->listWidget->currentItem()->setFlags (ui->listWidget->currentItem()->flags () | Qt::ItemIsEditable);


    ui->tableWidget->clearContents();

    ui->tableWidget->setRowCount(0);

    for(QListWidgetItem *item: ui->listWidget->selectedItems()){

        int row = ui->listWidget->row(item);
        for(string l : readTask){
            if(!std::to_string(row).compare(l.substr(0,1))){
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(l.substr(1))));
            }
        }
    }

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels({ui->listWidget->currentItem()->text()});
}

void MainWindow::on_addTask_clicked()
{
    if(ui->task_line->text().length() > 3){
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(ui->task_line->text()));
        Saving ads;

        for(QListWidgetItem *item: ui->listWidget->selectedItems()){
            int row = ui->listWidget->row(item);
            vector<string> addedTask = ads.AddTask(std::to_string(row), ui->task_line->text().toStdString());
            ads.WriteTask(addedTask);
        }

        ui->task_line->clear();

        /*List favourites, today, all, allTasks;

        today.todo = {};
        today.done = {};

        favourites.todo = {};
        favourites.done = {};

        all.todo = {};
        all.done = {};

        allTasks.todo = {};
        allTasks.done = {};

        List newList;

        if(ui->listWidget->currentItem()->text().toStdString() == "Мой день"){
            today.todo.push_back(ui->task_line->text().toStdString());
        }else if(ui->listWidget->currentItem()->text().toStdString() == "Избранное"){
            favourites.todo.push_back(ui->task_line->text().toStdString());
        }else if(ui->listWidget->currentItem()->text().toStdString() == "Задачи"){
            allTasks.todo.push_back(ui->task_line->text().toStdString());
        }*/
    }else{
        QMessageBox::warning(this, "Ошибка","Длина задачи должна быть больше 3 символов");
    }

}

