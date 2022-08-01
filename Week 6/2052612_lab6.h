#include <iostream>
#include<iomanip>
#include <string>
#include <climits>
#include <math.h>
using namespace std;

class University;
class UniStu;
class ColStu;

int uni_counter = 0, col_counter = 0;

//*****************************************************(MAIN CLASS) STUDENT SECTION*****************************************************************
class Student
{
    private:
        int position;
        int next_index = 0;
    protected:
        string* data;
    public:
        Student();
        ~Student();
        friend class University;
};

Student::Student()
{
    data = new string [100];
    for (int i = 0; i < 100; i++){data[i] = "null";}
    position = 100;
    next_index = 0;
}

Student::~Student(){delete[] data; }

//*****************************************************UNI_STUDENT SECTION*****************************************************************
class UniStu : protected Student {
    protected:
        struct Uni_Stu
        {
            Uni_Stu()
            {
                for (int i = 0; i < 4; i++){for (int j = 0; j < 3; j++){sem[i][j] = -1;}}
                uni_avg = -1.00;
            }
            int sem[8][6];
            float uni_avg;
        };
    public:
        Uni_Stu* uniscore = new Uni_Stu [100];
        void DoAssignment();
        void TakeTest();
        void TakeExam();
        ~UniStu();
}; 

void UniStu::DoAssignment(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 3; j ++){
            uniscore[uni_counter - 1].sem[i][j] = rand()%11;
        }
    }
}

void UniStu::TakeTest(){
    for (int i = 0; i < 8; i++){
        for (int k = 3; k < 5; k ++){
            uniscore[uni_counter - 1].sem[i][k] = rand()%11;
        }
    }
}

void UniStu::TakeExam(){
    for (int i = 0; i < 8; i++){
        uniscore[uni_counter - 1].sem[i][5] = rand()%11;
    }
}

UniStu::~UniStu() {delete[] uniscore;}

//*****************************************************COL_STUDENT SECTION*****************************************************************
class ColStu : protected Student {
    protected:
        struct Col_Stu
        {
            Col_Stu()
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 3; j++){sem[i][j] = -1;}
                    col_avg = -1.00;
                }
            }
            int sem[4][3];
            float col_avg;
        };
    public:
        Col_Stu* colscore = new Col_Stu [100];
        void DoAssignment();
        void TakeTest();
        void TakeExam();
        ~ColStu();
}; 

void ColStu::DoAssignment(){
    for (int i = 0; i < 4; i++){
        colscore[col_counter - 1].sem[i][0] = rand()%11;
    }
}

void ColStu::TakeTest(){
    for (int i = 0; i < 4; i++){
        colscore[col_counter - 1].sem[i][1] = rand()%11;
    }
}

void ColStu::TakeExam(){
    for (int i = 0; i < 4; i++){
        colscore[col_counter - 1].sem[i][2] = rand()%11;
    }
}

ColStu::~ColStu() {delete[] colscore;}

//*****************************************************UNIVERSITY SECTION*****************************************************************
class University{
    public:
        string& operator[](int index);
        void add(string new_data); 
        void addemo(int uni_or_col);
        void display();
        void dabezt();
        void remove();

        int size();
        void addcol();
        void adduni();
        Student ptn;
        UniStu unistu;
        ColStu colstu;
};

void University::addcol(){
    cout << "\nThe col students have 4 semesters in their courses and each semester has 1 assignment, 1 test and 1 exam (total 12 values)\n";
    cout << "THE SCORE FROM 0 TO 10 !! \n";
    float avg_ass = 0.00;
    float avg_test = 0.00;
    float avg_exam = 0.00;
    int ranAss = 0;
    int ranTest = 0;
    int ranExam = 0;
    for (int i = 0; i < 4; i++){
        int score = -1;
        if (i == 0){
            int hand_or_ran = 0;
            cout << "Do you wish to input Assigment record by hand or RANDOM ?\n1: By hand\n2: Randomly\n";
            cin >> hand_or_ran;
            while (cin.fail()|| hand_or_ran < 1 || hand_or_ran > 2) {cin.clear();cin.ignore(INT_MAX, '\n');cout << "----------------------------\nInvalid!!\nPlease re-enter your choice\n----------------------------\nChoice: ";cin >> hand_or_ran;}
            if (hand_or_ran == 2){
                colstu.DoAssignment();
                ranAss++;
            }
            hand_or_ran = 0;
            cout << "Do you wish to input Test record by hand or RANDOM ?\n1: By hand\n2: Randomly\n";
            cin >> hand_or_ran;
            while (cin.fail()|| hand_or_ran < 1 || hand_or_ran > 2) {cin.clear();cin.ignore(INT_MAX, '\n');cout << "----------------------------\nInvalid!!\nPlease re-enter your choice\n----------------------------\nChoice: ";cin >> hand_or_ran;}
            if (hand_or_ran == 2){
                colstu.TakeTest();
                ranTest++;
            }
            hand_or_ran = 0;
            cout << "Do you wish to input Exam record by hand or RANDOM ?\n1: By hand\n2: Randomly\n";
            cin >> hand_or_ran;
            while (cin.fail()|| hand_or_ran < 1 || hand_or_ran > 2) {cin.clear();cin.ignore(INT_MAX, '\n');cout << "----------------------------\nInvalid!!\nPlease re-enter your choice\n----------------------------\nChoice: ";cin >> hand_or_ran;}
            if (hand_or_ran == 2){
                colstu.TakeExam();
                ranExam++;
            }
        }
        if (ranAss == 0){
            cout << "Please input the record of the assignment: \n";
            cin >> score;
            while (cin.fail()|| score < 0 || score > 10) 
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s assignment record\n----------------------------\nStudent\'s assignment record: ";
                cin >> score;
            }
            colstu.colscore[col_counter - 1].sem[i][0] = score;
            cout << "Add information successfully.\n\n"; 
            score = -1;
        }
        if (ranTest == 0){
            cout << "Please input the record of the test: \n";
            cin >> score;
            while (cin.fail()|| score < 0 || score > 10) 
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s test record\n----------------------------\nStudent\'s test record: ";
                cin >> score;
            }
            colstu.colscore[col_counter - 1].sem[i][1] = score;
            cout << "Add information successfully.\n\n"; 
            score = -1;
        }
        if (ranExam == 0){
            cout << "Please input the record of the exam: \n";
            cin >> score;
            while (cin.fail()|| score < 0 || score > 10) 
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s exam record\n----------------------------\nStudent\'s exam record: ";
                cin >> score;
            }
            colstu.colscore[col_counter - 1].sem[i][2] = score;
            cout << "Add information successfully.\n\n"; 
            score = -1;
        }
    }
    for (int i = 0; i < 4; i++){avg_ass += colstu.colscore[col_counter - 1].sem[i][0];}
    avg_ass *= 0.2;
    for (int i = 0; i < 4; i++){avg_test += colstu.colscore[col_counter - 1].sem[i][1];}
    avg_test *= 0.3;
    for (int i = 0; i < 4; i++){avg_exam += colstu.colscore[col_counter - 1].sem[i][2];}
    avg_exam *= 0.5;
    colstu.colscore[col_counter - 1].col_avg = (avg_ass + avg_test + avg_exam)/4;
    
}

void University::adduni(){
    cout << "\nThe col students have 8 semesters in their courses and each semester has 3 assignments, 2 tests and 1 exam (total 48 values)\n";
    cout << "THE SCORE FROM 0 TO 10 !! \n";
    int ranAss = 0;
    int ranTest = 0;
    int ranExam = 0;
    for (int i = 0; i < 8; i++){
        int score = -1;
        if (i == 0){
            int hand_or_ran = 0;
            cout << "Do you wish to input Assigment record by hand or RANDOM ?\n1: By hand\n2: Randomly\n";
            cin >> hand_or_ran;
            while (cin.fail()|| hand_or_ran < 1 || hand_or_ran > 2) {cin.clear();cin.ignore(INT_MAX, '\n');cout << "----------------------------\nInvalid!!\nPlease re-enter your choice\n----------------------------\nChoice: ";cin >> hand_or_ran;}
            if (hand_or_ran == 2){
                unistu.DoAssignment();
                ranAss++;
            }
            hand_or_ran = 0;
            cout << "Do you wish to input Test record by hand or RANDOM ?\n1: By hand\n2: Randomly\n";
            cin >> hand_or_ran;
            while (cin.fail()|| hand_or_ran < 1 || hand_or_ran > 2) {cin.clear();cin.ignore(INT_MAX, '\n');cout << "----------------------------\nInvalid!!\nPlease re-enter your choice\n----------------------------\nChoice: ";cin >> hand_or_ran;}
            if (hand_or_ran == 2){
                unistu.TakeTest();
                ranTest++;
            }
            hand_or_ran = 0;
            cout << "Do you wish to input Exam record by hand or RANDOM ?\n1: By hand\n2: Randomly\n";
            cin >> hand_or_ran;
            while (cin.fail()|| hand_or_ran < 1 || hand_or_ran > 2) {cin.clear();cin.ignore(INT_MAX, '\n');cout << "----------------------------\nInvalid!!\nPlease re-enter your choice\n----------------------------\nChoice: ";cin >> hand_or_ran;}
            if (hand_or_ran == 2){
                unistu.TakeExam();
                ranExam++;
            }
        }
        if (ranAss == 0){
            cout << "Please input the record of the assignment: \n";
            for (int j = 0; j < 3; j ++){
                cout << "Record of assignment " << j + 1 << ": "; 
                cin >> score;
                while (cin.fail()|| score < 0 || score > 10) 
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s assignment record\n----------------------------\nStudent\'s assignment record: ";
                    cin >> score;
                }
                unistu.uniscore[uni_counter - 1].sem[i][j] = score;
                cout << "Add information successfully.\n\n"; 
                score = -1;
            }
        }
        if (ranTest == 0){
            cout << "Please input the record of the test: \n";
            for (int k = 3; k < 5; k ++){
                cout << "Record of test " << k -2 << ": "; 
                cin >> score;
                while (cin.fail()|| score < 0 || score > 10) 
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s assignment record\n----------------------------\nStudent\'s assignment record: ";
                    cin >> score;
                }
                unistu.uniscore[uni_counter - 1].sem[i][k] = score;
                cout << "Add information successfully.\n\n"; 
                score = -1;
            }
        }
        if (ranExam == 0){
            cout << "Please input the record of the exam: \n";
            cin >> score;
            while (cin.fail()|| score < 0 || score > 10) 
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "----------------------------\nInvalid!!\nPlease re-enter student\'s exam record\n----------------------------\nStudent\'s exam record: ";
                cin >> score;
            }
            unistu.uniscore[uni_counter - 1].sem[i][5] = score;
            cout << "Add information successfully.\n\n"; 
            score = -1;
        }
    }   
    
    float avg_ass = 0.00;
    float avg_test = 0.00;
    float avg_exam = 0.00;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 3; j ++){avg_ass += unistu.uniscore[uni_counter - 1].sem[i][j];}
        for (int k = 3; k < 5; k++){avg_test += unistu.uniscore[uni_counter - 1].sem[i][k];}
        avg_exam += unistu.uniscore[uni_counter - 1].sem[i][5];
    }
    avg_ass *= 0.2;
    avg_test *= 0.3;
    avg_exam *= 0.5;
    unistu.uniscore[uni_counter - 1].uni_avg = (avg_ass + avg_test + avg_exam)/8; 
}

string& University::operator[](int index) {
    string* data_new;
    if (index >= ptn.position) { 
        data_new = new string[index + 100];
        for (int i = 0; i < ptn.next_index; i++){ 
            data_new[i] = ptn.data[i];
        }
        for (int j = ptn.next_index; j < index + 100; j++){
            data_new[j] = "null";
        }
        ptn.position = index + 100; 
        delete [] ptn.data;
        ptn.data = data_new;
    }
    if (index > ptn.next_index) 
        ptn.next_index = index + 6;
    return *(ptn.data + index); 
}

void University::add(string val) {
    string *lmao;
    if (ptn.next_index == ptn.position) {
        ptn.position = ptn.position + 100;
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

void University::addemo(int uni_or_col){
    int score = -1;
    //int count = 0;
    string names = "null", dob = "null", schoolnames = "null", coursename = "null";
    // name input
    cout << "Please enter the student\'s name: ";
    cin.ignore();
    getline(cin, names);
    // birthday input
    cout << "Please enter date of births: ";
    getline(cin, dob);
    // school names
    cout << "Please enter the school names: ";
    getline(cin, schoolnames);
    // course names
    cout << "Please enter the course names: ";
    getline(cin, coursename);
    // ô đầu là (1 or 2) xác định là unistu hay là colstu
    // ô 2 là đếm số lượt của ô đầu
    // |1/2|1|names|dob|schools|courses|
    string uni_or_col_string = "null"; 
    uni_or_col_string = to_string(uni_or_col);
    add(uni_or_col_string);
    string uni_or_col_counter = "null";
    if (uni_or_col == 1){
        uni_counter++;
        uni_or_col_counter = to_string(uni_counter - 1);
        add(uni_or_col_counter);
    }
    if (uni_or_col == 2){
        col_counter++;
        uni_or_col_counter = to_string(col_counter - 1);
        add(uni_or_col_counter);
    }
    add(names);
    add(dob);
    add(schoolnames);
    add(coursename);
    cout << "----------------------------\nAdd information successfully\nPlease continue adding the record:"; 
}

void University::display(){
    int count = 0;
    cout << "\n_____________________________________\n------------Students list------------";
    for (int i = 0; i < size(); i+=6)
    {
        if (ptn.data[i].compare("null") != 0)
        {
            count++;
            cout << "\n*************************************\nName: " << ptn.data[i+2] << endl;
            cout << "Date of birth: " << ptn.data[i+3] << endl;
            cout << "School: " << ptn.data[i+4] << endl;
            cout << "Course: " << ptn.data[i+5] << endl;
            int definer = stoi(ptn.data[i]);
            int counter = stoi(ptn.data[i+1]);
            
            if (definer == 1){
                for (int i = 0; i < 8; i++)
                {
                    cout << "\n______________________\nRECORD OF SEM " << i + 1 << endl << "Assignments record: ";
                    for (int j = 0; j < 3; j ++){cout << unistu.uniscore[counter].sem[i][j] << " ";}
                    cout << "\nExams record: ";
                    for (int j = 3; j < 5; j ++){cout << unistu.uniscore[counter].sem[i][j] << " ";}
                    cout << "\nText record: " << unistu.uniscore[counter].sem[i][5];
                }
            }

            if (definer == 2){
                for (int i = 0; i < 4; i++)
                {
                    cout << "\n______________________\nRECORD OF SEM " << i + 1 << endl << "Assignment record: ";
                    cout << colstu.colscore[counter].sem[i][0] << endl << "Test record: ";
                    cout << colstu.colscore[counter].sem[i][1] << endl << "Exam record: ";
                    cout << colstu.colscore[counter].sem[i][2] << endl;
                }
            }
        }
    }
    if (count == 0){cout << "\n----------------------------\nThe list is empty.";}
}

void University::dabezt(){
    double uni_top = -1.00, col_top = -1.00;
    string uni_info[4];
    string col_info[4];
    for (int i = 0; i < size(); i+=6)
    {
        if (ptn.data[i].compare("null") != 0)
        {
            int definer = stoi(ptn.data[i]);
            int counter = stoi(ptn.data[i+1]);
            if (definer == 1){
                if (uni_top < unistu.uniscore[counter].uni_avg){
                    uni_top = unistu.uniscore[counter].uni_avg;
                    for (int j = 0; j < 4; j++){uni_info[j] = ptn.data[i+j+2];}
                }
            }
            if (definer == 2){
                if (col_top < colstu.colscore[counter].col_avg){
                    col_top = colstu.colscore[counter].col_avg;
                    for (int j = 0; j < 4; j++){col_info[j] = ptn.data[i+j+2];}
                }
            }
        }
    }
    cout << endl << "================================================" << endl;
    if (uni_top == -1.00){cout << "\nThe Uni Student list is empty.\n";}
    else{
        cout << "Da bezt Uni Student:\nName: " << uni_info[0] << "\nDate of birth: " << uni_info[1] << "\nSchool: " << uni_info[2] << "\nCourse: " << uni_info[3] << endl;
    }
    if (col_top == -1.00){cout << "\nThe College Student list is empty.\n";}
    else{
        cout << "\nDa bezt College Student:\nName: " << col_info[0] << "\nDate of birth: " << col_info[1] << "\nSchool: " << col_info[2] << "\nCourse: " << col_info[3] << endl;
    }
}

void University::remove(){
    string name;
    int count = 0;
    cout << "Enter a name to remove: ";
    cin.ignore();
    getline(cin, name);
    for (int i = 2; i < size(); i+=6)
    {
        if (ptn.data[i].compare(name) == 0)
        {
            for (int ham = i; ham < i + 4; ham ++){ptn.data[ham] = "null";}
            int definer = stoi(ptn.data[i-2]);
            int counter = stoi(ptn.data[i-1]);
            if (definer == 1){
                for (int m = 0; m < 8; m++){
                    for (int n = 0; n < 6; n++){
                        unistu.uniscore[counter].sem[m][n]= -1;
                    }
                }
                unistu.uniscore[counter].uni_avg = -1;                
            }
            if (definer == 2){
                for (int m = 0; m < 8; m++){
                    for (int n = 0; n < 6; n++){
                        colstu.colscore[counter].sem[m][n] = -1;
                    }
                }
                colstu.colscore[counter].col_avg = -1;                
            } 
            ptn.data[i-1] = "null";
            ptn.data[i-2] = "null";
            count ++;
        }
    }
    if (count == 0) {cout << "----------------------------\nCannot detect matched name!!";}
    else {cout << "----------------------------\nRemoved successfully";}
}

int University::size() {return ptn.position;}