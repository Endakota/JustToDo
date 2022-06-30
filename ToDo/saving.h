#ifndef SAVING_H
#define SAVING_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QDateTime>
#include <QMessageBox>
using namespace std;


struct Spisok{
    string iconPath;
    string name;
    vector <string> tasks;
};
class Saving
{
    string data = QDateTime::currentDateTime().toString("ddMMyyyy").toStdString();
    public:vector<string> Read()
    {
        ifstream inFile;
        inFile.open("Spiski.csv");
        string line;
        vector<string> list_names;

        while (!inFile.eof()) {
            getline(inFile, line);
            list_names.push_back(line);
        }

        inFile.close();
        return list_names;
    }
    public:vector<string> ReadTask(){
         string line;
         vector<string> taskInFile;
         ifstream readTask;
         taskInFile.push_back("");
         readTask.open("Tasks.csv");
         while (!readTask.eof()) {
             getline(readTask, line);
             if(line.size() != 0){
                taskInFile.push_back(line);
             }

         }

         readTask.close();
         return taskInFile;
    }
    public:vector<string> ReadDoneTask(){
         string line;
         vector<string> taskInFile;
         taskInFile.push_back("");
         ifstream readTask;
         readTask.open("doneTasks.csv");
         while (!readTask.eof()) {
             getline(readTask, line);
             if(line.size() != 0){
                taskInFile.push_back(line);
             }
         }

         readTask.close();
         return taskInFile;
    }
    public: vector<string> AddTask(string path, string stroka)
    {
        string line;
        vector<string> taskInFile;
        ifstream readTask;
        readTask.open("Tasks.csv");
        while (!readTask.eof()) {
            getline(readTask, line);
            taskInFile.push_back(line);
        }

        readTask.close();

        taskInFile.push_back(path+stroka);

        return taskInFile;

    }
    public: void WriteTask(vector<string> task, string path = "Tasks.csv")
    {
        ofstream writeTask;
        writeTask.open(path);
        task.erase(task.begin());
        for (auto val: task)
        {
            if(val.size() != 0 && val.size() > 9){
                if(val.substr(val.size()-8,val.size()) == data){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Пример");
                    msgBox.setText(QString::fromStdString(val.substr(val.size()-8,val.size())));
                    msgBox.exec();
                    writeTask <<endl<< val ;
                }
            }else if(val.size() != 0 && val.size() < 9){
                writeTask <<endl<< val + data ;
            }
        }

        writeTask.close();
    }
    public: void doneTask(vector<string> task, string path = "doneTasks.csv")
    {
        ofstream writeTask;
        writeTask.open(path);
        task.erase(task.begin());
        for (auto val: task)
        {
            if(val.size() != 0 && val.size() > 9){
                if(val.substr(val.size()-8,val.size()) == data){


                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Пример");
                    msgBox.setText(QString::fromStdString(val.substr(val.size()-8,val.size())));
                    msgBox.exec();

                    writeTask <<endl<< val ;
                }
            }else if(val.size() != 0 && val.size() < 9){
                writeTask <<endl<< val + data;
            }

        }

        writeTask.close();
    }
    public:void WriteSpiskiN(vector<string> spisok)
    {
        ofstream outFile;
        outFile.open("Spiski.csv");
        for (auto val: spisok)
        {
            outFile <<endl<< val;
        }

        outFile.close();
    }

    public: void WriteSpiski(string spisok)
    {
        ofstream outFile;
        outFile.open("Spiski.csv", ios::app);
        outFile << endl << spisok;
        outFile.close();
    }

};
#endif // SAVING_H
