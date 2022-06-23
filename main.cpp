#include <iostream>
#include <vector>
#include <string>
struct list{
    std::vector <std::string> todo;
    std::vector <std::string> done;
};
int main()
{
    list all;
    list today_list;
    list favourites;

    all.todo = {};
    all.done = {};

    favourites.todo = {};
    favourites.done = {};

    today_list.todo = {"Eat","Wake up","sleep"};
    today_list.done = {};

    int command = -1;

    while(command != 0){

        if(command == 3){
            std::cout << "*Add to favourites*\n";
            std::cout << "Choose the index of task\n";
            int index = 1;
            for(auto list : today_list.todo){
                std::cout <<index<< ")" <<list << std::endl;
                index++;
            }
            std::cin >> index;
            favourites.todo.push_back(today_list.todo[index - 1]);
            today_list.todo.erase(today_list.todo.begin() + index - 1);
        }

        if(command == 2){
            std::cout << "*Add to isDone*\n";
            std::cout << "Choose the index of task\n";
            int index = 1;
            int savedInd = 0;
            for(auto list : favourites.todo){
                std::cout <<"! " << index<< ")" <<list << std::endl;
                savedInd = index;
                index++;
            }
            for(auto list : today_list.todo){
                std::cout <<index<< ")" <<list << std::endl;
                index++;
            }
            std::cin >> index;
            if(index > 0 && index < savedInd - 1){
                today_list.done.push_back(favourites.todo[index - 1]);
                favourites.todo.erase(favourites.todo.begin() + index - 1);
            }
            if(index > savedInd - 1){
                today_list.done.push_back(today_list.todo[index - savedInd - 1]);
                today_list.todo.erase(today_list.todo.begin() + index - savedInd - 1);
            }

        }

        if(command == 1){
            std::cout << "*Delete the task*\n";
            std::cout << "Choose the index of task\n";
            int index = 1;
            for(auto list : today_list.done){
                std::cout <<index<< ")" <<list << std::endl;
                index++;
            }
            std::cin >> index;

            today_list.done.erase(today_list.done.begin() + index - 1);
        }

        system("cls");

        std::cout << "today_list tasks\n";
        for(auto fav : favourites.todo){
            std::cout << "! "<<fav<<std::endl;
        }
        for(auto al : today_list.todo){
            std::cout << "* "<<al<<std::endl;
        }
        std::cout << "done tasks\n";
        for(auto al : today_list.done){
            std::cout << "* "<<al<<std::endl;
        }


        std::cout << "\nAdd to Favourites 3/Done 2/Delete 1/Break 0\n";
        std::cin >> command;
    }
    return 0;
}
