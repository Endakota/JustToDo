#ifndef SAVING_H
#define SAVING_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct Spisok{
    string iconPath;
    string name;
    vector <string> tasks;
};
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
//    public: vector<string> Addtasks_n(string path, vector<string> tasks){
//        string line;
//        vector<string> taskInFile;
//        ifstream readTask;
//        readTask.open("Tasks.csv");
//        while (!readTask.eof()) {
//            getline(readTask, line);
//            if(path != line.substr(0,1)){
//                taskInFile.push_back(line);
//            }
//        }
//        readTask.close();
//        for(auto i : tasks){
//            taskInFile.push_back(i);
//        }
//        return taskInFile;
//    }
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
