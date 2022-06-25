#ifndef SAVING_H
#define SAVING_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Saving
{
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
         readTask.open("Tasks.csv");
         while (!readTask.eof()) {
             getline(readTask, line);
             taskInFile.push_back(line);
         }

         readTask.close();
         return taskInFile;
    }
    // path - опознавательная цифра Списка, куда записывается задача(например, "1" - "Мой день"\\; stroka - сама задача
    public: vector<string> AddTask(string path, string stroka)//string path, string stroka)
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
    public: void WriteTask(vector<string> task)
    {
        ofstream writeTask;
        writeTask.open("Tasks.csv");
        task.erase(task.begin());
        for (auto val: task)
        {
            writeTask <<endl<< val;
        }

        writeTask.close();
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
