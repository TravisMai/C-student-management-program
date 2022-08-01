#include <iostream>
#include<iomanip>
#include <string>
#include <climits>
using namespace std;

class University;

class HCMUT
{
private:
    string* data;
    int position;
    int next_index = 0;
public:
    HCMUT();
    ~HCMUT();
    friend class University;
};

class University{
    public:
        string& operator[](int index);
        void add(string new_data); 
        void addemo();
        void display();
        void dabezt();
        void remove();
        int size();
        HCMUT ptn;
};

HCMUT::HCMUT()
{
    data = new string [100];
    for (int i = 0; i < 100; i++){
        data[i] = "null";
    }
    position = 100;
    next_index = 0;
}

HCMUT::~HCMUT()
{
    delete[] data;
}

string& University::operator[](int index) {
    string* data_new;
    if (index >= ptn.position) { 
        data_new = new string[index + 10];
        for (int i = 0; i < ptn.next_index; i++){ 
            data_new[i] = ptn.data[i];
        }
        for (int j = ptn.next_index; j < index + 10; j++){
            data_new[j] = "null";
        }
        ptn.position = index + 10; 
        delete [] ptn.data;
        ptn.data = data_new;
    }
    if (index > ptn.next_index) 
        ptn.next_index = index + 2;
    return *(ptn.data + index); 
}

void University::add(string val) {
    string *lmao;
    if (ptn.next_index == ptn.position) {
        ptn.position = ptn.position + 10;
        lmao = new string[ptn.position];
        for (int i = 0; i < ptn.next_index; i++)
            lmao[i] = ptn.data[i];
        for (int j = ptn.next_index; j < ptn.position; j++)
            lmao[j] = "null";
        delete [] ptn.data;
        ptn.data = lmao;
    }
    ptn.data[ptn.next_index++] = val;
}

void University::addemo(){
    int score = -1;
    int count = 0;
    string input = "null";
    cout << "Please enter the student\'s name: ";
    cin.ignore();
    getline(cin, input);
    cout << "Please enter the student\'s point (from 0 - 10): ";
    cin >> score;
    while (cin.fail()|| score < 0 || score > 10) 
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s record\n----------------------------\nStudent\'s record: ";
        cin >> score;
    }
    string convert = "null"; 
    convert = to_string(score);
    add(input);
    add(convert);
    cout << "----------------------------\nAdd successfully"; 
}

void University::display(){
    int count = 0;
    cout << "\nStudents managment list:\n";
    cout << left << setw(30) << "Name list" << left << setw(30) << "Record list" << endl;
    for (int i = 0; i < size(); i+=2)
    {
        if (ptn.data[i].compare("null") != 0)
        {
            count++;
            cout << left << setw(30) << ptn.data[i] << left << setw(30) << ptn.data[i+1] << endl;
        }
    }
            if (count == 0){
                cout << "----------------------------\nThe list is empty.";
            }
}

void University::dabezt(){
    int top = -1;
    for (int i = 1; i < size(); i+=2)
    {
        if (ptn.data[i].compare("null") != 0)
        {
            int rush = stoi(ptn.data[i]);
            if(top < rush)
            {
                top = rush;
            }
        }
    }
    cout << endl;
    cout << left << setw(30) << "The best student(s)" << left << setw(30) << "Student(s)\'s record" << endl;
    cout << "================================================" << endl;

    for (int i = 1; i < size(); i+=2)
    {
        if (ptn.data[i].compare("null") != 0)
        {
            int rush = stoi(ptn.data[i]);
            if (rush == top)
            {
                cout << "1. " << left << setw(30)  << ptn.data[i-1] << left << setw(30) << ptn.data[i] << endl;
            }
        }
    }
    if (top == -1){cout << "\nThe list is empty.\n";}
}

void University::remove(){
    string input;
    int count = 0;
    cout << "Enter a name to remove: ";
    cin.ignore();
    getline(cin, input);
    for (int i = 0; i < size(); i++)
    {
        if (ptn.data[i].compare(input) == 0)
        {
            ptn.data[i] = "null";
            ptn.data[i+1] = "null";
            count = 1;
        }
    }
    if (count == 0) {cout << "----------------------------\nCannot detect matched name!!";}
    else {cout << "----------------------------\nRemoved successfully";}
}

int University::size() {
    return ptn.position;
}