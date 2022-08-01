#include <iostream>
#include <string>
#include <climits>
#define SIZE 100
using namespace std;

// Author: Mai Huu Nghia

string name[SIZE];

void add()
{
    string input;
    int count = 0;
    cout << "Please enter the student\'s name: ";
    cin.ignore();
    getline(cin, input);
    for (int i = 0; i < SIZE; i++)
    {
        if (name[i].compare("null") == 0)
        {
            name[i] = input;
            count = 1;
            break;
        }
    }
    if (count == 1) { cout << "----------------------------\nAdd successfully"; }
    else { cout << "----------------------------\nThe list is full"; }
}

void display()
{
    int count = 0;
    cout << "\nStudents List:\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (name[i].compare("null") != 0)
        {
            count++;
            cout << name[i] << endl;
        }
    }
    if (count == 0)
        cout << "----------------------------\nThe list is empty.";
}

void remove()
{
    string input;
    int count = 0;
    cout << "Enter a name to remove: ";
    cin.ignore();
    getline(cin, input);
    for (int i = 0; i < SIZE; i++)
    {
        if (name[i].compare(input) == 0)
        {
            name[i] = "null";
            count = 1;
        }
    }
    if (count == 0) { cout << "----------------------------\nCannot detect matched name!!"; }
    else { cout << "----------------------------\nRemoved successfully"; }
}

int main()
{
    int option, ex = 0;
    for (int i = 0; i < SIZE; i++) { name[i] = "null"; }
    while (1)
    {
        cout << "\n----------------------------\nPlease select your desire option (1-4):\n";
        cout << "1. Add Name\n2. Remove Name\n3. Display All Names\n4. Exit\n";
        cout << "Your choice: ";
        cin >> option;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "----------------------------\nInvalid option !!\nPlease re-enter your option\n----------------------------\nYour choice: ";
            cin >> option;
        }
        switch (option)
        {
        case 1:
            add();
            break;
        case 2:
            remove();
            break;
        case 3:
            display();
            break;
        case 4:
            ex = 1;
            break;
        default:
            cout << "----------------------------\nInvalid choice !!";
        }
        if (ex == 1) {break;}
    }
    return 0;
}
