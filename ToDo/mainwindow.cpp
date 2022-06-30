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
#include <QDateTime>

#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextTask(const QPoint&)));


    QListWidgetItem *today = new QListWidgetItem(QIcon("img/today.png"),"Мой день");
    ui->listWidget->insertItem(ui->listWidget->count(), today);

    QListWidgetItem *favourites = new QListWidgetItem(QIcon("img/star.png"),"Избранное");
    ui->listWidget->insertItem(ui->listWidget->count(), favourites);

    QListWidgetItem *all = new QListWidgetItem(QIcon("img/list.png"),"Задачи");
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
        QListWidgetItem *newItem = new QListWidgetItem(QIcon("img/point'.png"),QString::fromStdString(l));
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
                QCheckBox *checkBox = new QCheckBox;
                checkBox->setText(QString::fromStdString(l.substr(1,l.size()-9)));
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,0,checkBox);
            }
        }
        Saving ads;
        vector <string> dss = ads.ReadDoneTask();
        for(string l : dss){
            if(!std::to_string(row).compare(l.substr(0,1))){
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QCheckBox *checkBox = new QCheckBox;
                checkBox->setCheckState(Qt::Checked);
                checkBox->setText(QString::fromStdString(l.substr(1,l.size()-9)));
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,0,checkBox);
            }
        }
    }
}
void MainWindow::ShowContextMenu(const QPoint& pos)
{
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Удалить список", this, SLOT(on_action_1()));
    myMenu.exec(globalPos);
}

void MainWindow::ShowContextTask(const QPoint& pos)
{
// for most widgets
    QPoint globalPos = ui->tableWidget->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Удалить задачу", this, SLOT(deleteTask()));
    if(ui->listWidget->currentItem()->text() == "Мой день" || ui->listWidget->currentItem()->text() == "Задачи"){
        myMenu.addAction("Добавить задачу в 'Избранное'", this, SLOT(add2Fav()));
    }
    if(ui->listWidget->currentItem()->text() == "Избранное" || ui->listWidget->currentItem()->text() == "Задачи"){
        myMenu.addAction("Добавить задачу в 'Мой день'", this, SLOT(add2Day()));
    }

    myMenu.exec(globalPos);
}
void MainWindow::deleteTask()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}
void MainWindow::add2Fav(){
    Saving ads;
    vector<string> v = ads.ReadTask();
    string text = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(ui->tableWidget->currentRow(),0))->text().toStdString();
    v.push_back("1" + text);
    ads.WriteTask(v);
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}
void MainWindow::add2Day(){
    Saving ads;
    vector<string> v = ads.ReadTask();
    string text = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(ui->tableWidget->currentRow(),0))->text().toStdString();
    v.push_back("0" + text);
    ads.WriteTask(v);
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void MainWindow::on_action_1()
{
    if(ui->listWidget->currentItem()->text() != "Мой день" && ui->listWidget->currentItem()->text() != "Избранное" && ui->listWidget->currentItem()->text() != "Задачи" ){
        int index = ui->listWidget->currentRow();
        Saving ads;
        vector <string> ss = ads.ReadTask();

        vector <string> ss_n;
        ss_n.push_back("");
        for(size_t i = 1; i < ss.size(); i++){
            if(ss[i][0] < std::to_string(index)[0]){
                ss_n.push_back(ss[i]);
            }else if (ss[i][0] > std::to_string(index)[0]){
                ss[i][0] = std::to_string(stoi(ss[i].substr(0,1)) - 1)[0];
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

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    Saving ads;
    int count = 0;

    std::vector<string> v;

    for(int i = 0; i < ui->listWidget->count(); i++){
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
            QListWidgetItem *newItem = new QListWidgetItem(QIcon("img/point'.png"),"Новый список (" + QString::number(index) + ")");
            ui->listWidget->insertItem(ui->listWidget->count(), newItem);
            ads.WriteSpiski("Новый список (" + std::to_string(index)+")");
            break;
        }
        count = 0;
    }
}
int step = 2;
void MainWindow::on_listWidget_clicked()
{
    Saving ads;
    vector<string> all_tasks = ads.ReadTask();
    vector<string> all_done_tasks = ads.ReadDoneTask();
    vector<string> ss,dss;
    ss.push_back("");
    dss.push_back("");
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        if(qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0))->isChecked()){
            string text = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0))->text().toStdString();
            dss.push_back(std::to_string(step) + text);

        }else{
            string text = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0))->text().toStdString();
            ss.push_back(std::to_string(step) + text);
        }
    }

    for(size_t i = 0; i < all_tasks.size(); i++){
        if(all_tasks[i].substr(0,1) != std::to_string(step)){
             ss.push_back(all_tasks[i]);
        }
    }
    for(size_t i = 0; i < all_done_tasks.size(); i++){
        if(all_done_tasks[i].substr(0,1) != std::to_string(step)){
             dss.push_back(all_done_tasks[i]);
        }
    }
    ads.WriteTask(ss);
    ads.doneTask(dss);
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
                QCheckBox *checkBox = new QCheckBox;
                checkBox->setText(QString::fromStdString(l.substr(1, l.size()-9)));
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,0,checkBox);
            }
        }
        Saving ads;
        vector <string> dss = ads.ReadDoneTask();
        for(string l : dss){
            if(!std::to_string(row).compare(l.substr(0,1))){
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QCheckBox *checkBox = new QCheckBox;
                checkBox->setCheckState(Qt::Checked);
                checkBox->setText(QString::fromStdString(l.substr(1,l.size()-9)));
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,0,checkBox);
            }
        }
    }

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels({ui->listWidget->currentItem()->text()});
    step = ui->listWidget->currentRow();
}

void MainWindow::on_addTask_clicked()
{
    if(ui->task_line->text().length() >= 3){
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        QCheckBox *checkBox = new QCheckBox;
        checkBox->setText(ui->task_line->text());
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,0,checkBox);

        //ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(ui->task_line->text() + "0"));
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

       vector<string> all_tasks = ads.ReadTask();

       vector<string> ss,dss;
       ss.push_back("");
       dss.push_back("");
       for(int i = 0; i < ui->tableWidget->rowCount(); i++){
           if(qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0))->isChecked()){
               QString text = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0))->text();
               dss.push_back(std::to_string(ui->listWidget->currentRow()) + text.toStdString());

           }else{
               QString text = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0))->text();
               ss.push_back(std::to_string(ui->listWidget->currentRow()) + text.toStdString());
           }

       }
       for(size_t i = 0; i < all_tasks.size(); i++){
           if(all_tasks[i].substr(0,1) != std::to_string(ui->listWidget->currentRow())){
                ss.push_back(all_tasks[i]);
           }
       }
       ads.doneTask(dss);
       ads.WriteTask(ss);
       event->accept();
    }
     else
        event->ignore();
     return;
}
