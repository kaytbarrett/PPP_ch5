/*
    This is a rework of Chapter 3 Exercise 20. Write a program that uses a vector<Name_value>,
    where Name_value is a class that holds a string and a value. 
*/

#include "std_lib_facilities.h"


class Name_value {
    public:
        string name;
        int score;

        Name_value(string s)
            :name(s), score(0) { }
        Name_value(string s, int value)
            :name(s), score(value) {}
};

int main() {

    vector<Name_value> names_values;
    string name;
    int score = 0;
    char response = 'y';

    while (response == 'y'){
        cout << "\nPlease enter a name followed by a score. Ex: Joe 17\n";
        cin >> name >> score;   

        names_values.emplace_back(name, score);

        cout << "\nDo you want to enter another name and score? (y/n)\n";
        cin >> response;
    }

    response = 'y';

    while (response == 'y'){

        cout << "Please enter a score to see all names with that score:\n";
        cin >> score;

        for(int i = 0; i < names_values.size(); i++){
            if (score == names_values[i].score){
                cout << names_values[i].name << "\n";
            }
        }

        cout << "\nDo you want to check another score? (y/n)\n";
        cin >> response;
    }

}