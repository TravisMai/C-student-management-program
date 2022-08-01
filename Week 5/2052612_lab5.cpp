#include <iostream>
#include<iomanip>
#include <string>
#include <climits>
#include "2052612_lab5.h"
using namespace std;

int main()
{
    University ptn;
    int option;
    while (1)
    {
        cout << "\n----------------------------\nPlease select your desire option (1-5):\n";
        cout << "1. Add student record\n2. Display all student record\n3. The best student(s)\'s record\n4. Remove a student record \n5. Exit\n";
        cout << "Your choice: ";
        cin >> option;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "----------------------------\nInvalid option !!\nPlease re-enter your option\n----------------------------\nYour choice: ";
            cin >> option;
        }
        if (option == 1){
            int uni_or_col;
            cout << "Do you want to input information for Uni Students or College Students ?\n1. Uni Students\n2. College Students\nYour choice: ";
            cin >> uni_or_col;
            while (cin.fail() || uni_or_col < 1 || uni_or_col > 2)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "----------------------------\nInvalid option !!\nPlease re-enter yours option\n----------------------------\nYour choice: ";
                cin >> uni_or_col;
            }
            ptn.addemo(uni_or_col);
            if (uni_or_col == 1){ptn.adduni();}
            if (uni_or_col == 2){ptn.addcol();}
        }
        else if (option == 2){ptn.display();}
        else if (option == 3){ptn.dabezt();}
        else if (option == 4){ptn.remove();}
        else if (option == 5){break;}
        else {cout << "----------------------------\nInvalid choice !!";}
    }
    return 0;
}