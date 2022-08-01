#include <iostream>
#include<iomanip>
#include <string>
#include <climits>
#include "2052612_lab4.h"
using namespace std;

int main()
{
    University ptn;
    int option;
    while (1)
    {
        cout << "\n----------------------------\nPlease select your desire option (1-4):\n";
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
        if (option == 1){ptn.addemo();}
        else if (option == 2){ptn.display();}
        else if (option == 3){ptn.dabezt();}
        else if (option == 4){ptn.remove();}
        else if (option == 5){break;}
        else {cout << "----------------------------\nInvalid choice !!";}
    }
    return 0;
}