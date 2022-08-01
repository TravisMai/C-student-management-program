#include <iostream>
#include<iomanip>
#include <string>
#include <climits>
using namespace std;

class HCMUT
{
private:
    string* data;
    int position;
    int next_index = 0;
public:
    HCMUT();
    ~HCMUT();
    string& operator[](int index);
    void add(string new_data); 
    int size();
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

string& HCMUT::operator[](int index) {
    string* data_new;
    if (index >= position) { 
        data_new = new string[index + 10];
        for (int i = 0; i < next_index; i++){ 
            data_new[i] = data[i];
        }
        for (int j = next_index; j < index + 10; j++){
            data_new[j] = "null";
        }
        position = index + 10; 
        delete [] data;
        data = data_new;
    }
    if (index > next_index) 
        next_index = index + 2;
    return *(data + index); 
}

void HCMUT::add(string val) {
    string *lmao;
    if (next_index == position) {
        position = position + 10;
        lmao = new string[position];
        for (int i = 0; i < next_index; i++)
            lmao[i] = data[i];
        for (int j = next_index; j < position; j++)
            lmao[j] = "null";
        delete [] data;
        data = lmao;
    }
    data[next_index++] = val;
}

int HCMUT::size() {
    return position;
}

int main()
{
    int option;
    HCMUT cse;
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
        if (option == 1){            
            int score = -1;
            int count = 0;
            string input = "null";
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
            string convert = "null"; 
            convert = to_string(score);
            cse.add(input);
            cse.add(convert);
            cout << "----------------------------\nAdd successfully"; 
        }
        else if (option == 2){
            int count = 0;
            cout << "\nStudents managment list:\n";
            cout << left << setw(30) << "Name list" << left << setw(30) << "Record list" << endl;
            for (int i = 0; i < cse.size(); i+=2)
            {
                if (cse[i].compare("null") != 0)
                {
                    count++;
                    cout << left << setw(30) << cse[i] << left << setw(30) << cse[i+1] << endl;
                }
            }
            if (count == 0){
                cout << "----------------------------\nThe list is empty.";
            }
        }
        else if (option == 3){
            int top = -1;
            for (int i = 1; i < cse.size(); i+=2)
            {
                if (cse[i].compare("null") != 0)
                {
                    int rush = stoi(cse[i]);
                    if(top < rush)
                    {
                        top = rush;
                    }
                }
            }

            cout << endl;
            cout << left << setw(30) << "The best student(s)" << left << setw(30) << "Student(s)\'s record" << endl;
            cout << "================================================" << endl;

            for (int i = 1; i < cse.size(); i+=2)
            {
                if (cse[i].compare("null") != 0)
                {
                    int rush = stoi(cse[i]);
                    if (rush == top){
                        cout << "1. " << left << setw(30)  << cse[i-1] << left << setw(30) << cse[i] << endl;
                    }
                }
            }
            if (top == -1){
                cout << "\nThe list is empty.\n";
            }
        }
        else if (option == 4){
            string input;
            int count = 0;
            cout << "Enter a name to remove: ";
            cin.ignore();
            getline(cin, input);
            for (int i = 0; i < cse.size(); i++)
            {
                if (cse[i].compare(input) == 0)
                {
                    cse[i] = "null";
                    cse[i+1] = "null";
                    count = 1;
                }
            }
            if (count == 0) { cout << "----------------------------\nCannot detect matched name!!"; }
            else { cout << "----------------------------\nRemoved successfully"; }
        }
        else if (option == 5){
            break;
        }
        else {cout << "----------------------------\nInvalid choice !!";}
    }
    return 0;
}
