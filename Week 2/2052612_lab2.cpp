#include <iostream>
#include<iomanip>
#include <string>
#include <climits>
#define SIZE 100
using namespace std;

// Author: Mai Huu Nghia

string* name = new string[SIZE];
int* point = new int[SIZE];

void add()
{
    string input;
    int score;
    int count = 0;
    cout << "Please enter the student\'s name: ";
    cin.ignore();
    getline(cin, input);
    cout << "Please enter the student\'s point (from 0 - 10): ";
    cin >> score;
    while (cin.fail()|| score < 0 || score > 10) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s record\n----------------------------\nStudent\'s record: ";
        cin >> score;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (name[i].compare("null") == 0)
        {
            name[i] = input;
            point[i] = score;
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
    cout << "\nStudents managment list:\n";
    cout << left << setw(30) << "Name list" << left << setw(30) << "Record list" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (name[i].compare("null") != 0)
        {
            count++;
            cout <<  i + 1 << ". " << left << setw(30) << name[i] << left << setw(30) << point[i] << endl;
        }
    }
    if (count == 0)
        cout << "----------------------------\nThe list is empty.";
}

void dabezt()
{
    int top = -1;
    for (int i = 0; i < SIZE; i++)
    {
        if (name[i].compare("null") != 0)
        {
            if(top < point[i])
            {
                top = point[i];
            }
        }
    }

    cout << endl;
    cout << left << setw(30) << "The best student(s)" << left << setw(30) << "Student(s)\'s record" << endl;
    cout << "================================================" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (point[i] == top && name[i].compare("null") != 0)
        {
            cout << "1. " << left << setw(30)  << name[i] << left << setw(30) << point[i] << endl;
        }
    }
    if (top == -1)
        cout << "\nThe list is empty.\n";
}

int main()
{
    int option, ex = 0;
    for (int i = 0; i < SIZE; i++) { name[i] = "null"; }
    while (1)
    {
        cout << "\n----------------------------\nPlease select your desire option (1-4):\n";
        cout << "1. Add student record\n2. Display all student record\n3. The best student(s)\'s record\n4. Exit\n";
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
            display();
            break;
        case 3:
            dabezt();
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
