#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <Qt>
#include <QMessageBox>
#include <vector>
#include "saving.h"
#include <iostream>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <stdlib.h>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));




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
void MainWindow::ShowContextMenu(const QPoint& pos)
{
// for most widgets
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Удалить список", this, SLOT(on_action_1()));
    myMenu.addAction("Пункт 2", this, SLOT(on_action_2()));
    myMenu.exec(globalPos);
}
void MainWindow::on_action_1()
{
    if(ui->listWidget->currentItem()->text() != "Мой день" && ui->listWidget->currentItem()->text() != "Избранное" && ui->listWidget->currentItem()->text() != "Задачи" ){
        int index = ui->listWidget->currentRow();

        Saving ads;
        vector <string> ss = ads.ReadTask();

        vector <string> ss_n;
        for(size_t i = 0; i < ss.size(); i++){
            if(ss[i].substr(0,1) != std::to_string(index)){
                /*if(ss[i].substr(0,1) > std::to_string(index)) {
                    string stroka = "";
                    stroka += std::to_string(index) + ss[i].substr(1);
                    ss[i] = stroka;
                }*/
                ss_n.push_back(ss[i]);
            }
        }
        ads.WriteTask(ss_n);

        QListWidgetItem *it = ui->listWidget->takeItem(index);
        delete it;
    }else{
        QMessageBox::warning(this, "Ошибка","Нельзя удалить данный список");
    }

}
void MainWindow::on_action_2()
{
//тело слота on_action_2
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    Saving ads;
    int count = 0;

    std::vector<string> v;

    for(size_t i = 0; i < ui->listWidget->count(); i++){
        v.push_back(ui->listWidget->item(i)->text().toStdString());
    }

    string key = "Новый список (" + std::to_string(count) + ")";

    int index = 0;
    while (true){
        key = "Новый список (" + std::to_string(index) + ")";

        if (std::find(v.begin(), v.end(), key) != v.end()) {
            count += 1;
        }
        if (count > 0){
            index++;
        }else{
            QListWidgetItem *newItem = new QListWidgetItem(QIcon("C:/Users/Endakota/Desktop/ToDo/point'.png"),"Новый список (" + QString::number(index) + ")");
            ui->listWidget->insertItem(ui->listWidget->count(), newItem);
            ads.WriteSpiski("Новый список" + std::to_string(count));
            break;
        }
        count = 0;
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
    if(ui->task_line->text().length() >= 3){
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(ui->task_line->text()));
        Saving ads;

        for(QListWidgetItem *item: ui->listWidget->selectedItems()){
            int row = ui->listWidget->row(item);
            vector<string> addedTask = ads.AddTask(std::to_string(row), ui->task_line->text().toStdString());
            ads.WriteTask(addedTask);
        }
        ui->task_line->clear();
    }else{
        QMessageBox::warning(this, "Ошибка","Длина задачи должна быть больше 3 символов");
    }

}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (QMessageBox::question(this,tr("Confirmation"),tr("Exit program?"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
       Saving ads;
       vector<string> ssn;
       for(int i = 3; i < ui->listWidget->count(); i++){
           ssn.push_back(ui->listWidget->item(i)->text().toStdString());
       }
       ads.WriteSpiskiN(ssn);
       event->accept();
    }
     else
        event->ignore();
     return;
}
