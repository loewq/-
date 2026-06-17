#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
 return (a < b) ? a : b;
}

struct Student {
 string id;
 string name;
 int score;
};

void addStudent(vector<Student>& students){
    Student newstudent;
    cout <<"Enter Student ID: ";
    cin >> newstudent.id;

    for (int i = 0; i < students.size(); i++){
        if (newstudent.id == students[i].id){
            cout <<"ID 重複"<<endl;
            return;
        }
    }

    cout <<"Enter Student Name: ";
    cin.ignore();
    getline(cin,newstudent.name);
    cout <<"Enter Student Score: ";
    cin >> newstudent.score;
    cout <<"==================="<<endl;

    students.push_back(newstudent);
}

void liststudent(const vector<Student>& student){
    if (student.empty()) {
        cout << "\nNo student data\n";
        return; 
    }
    for (int i = 0; i < student.size(); i++){
        cout << "|ID: "<< student[i].id << "\t";
        cout << "|Name: "<< student[i].name << "\t";
        cout << "|Score: "<< student[i].score << "\n";
    }
    cout <<"==================="<<endl;
}

void sortstudent(vector<Student>& student){
    if (student.empty()) {
        cout << "\nNo student data\n";
        return; 
    }
    sort(student.begin(), student.end(), [](const Student& a, const Student& b){return a.score > b.score;});
}


void searchstudent(vector<Student>& student){
    if (student.empty()) {
        cout << "\nNo student data\n";
        return; 
    }
    Student s1;
    cout <<"Enter student ID: ";
    cin >> s1.id;

    for (int i = 0; i < student.size(); i++){
        if (student[i].id == s1.id){
            cout << "|ID: "<< student[i].id <<"\t";
            cout << "|Name: "<< student[i].name <<"\t";
            cout << "|Score: "<< student[i].score <<endl;
            cout <<"==================="<<endl;
            return;
        }
    }
    cout << "Cant find student!"<<endl;
    return;
}

void statistics(vector<Student>& student){
    if (student.empty()) {
        cout << "\nNo student data\n";
        return; 
    }
    double avg;
    int pass=0;
    int failed=0;

    int n = 0;
    for (int i = 0; i < student.size(); i++){
        n += student[i].score;
    }
    avg = n/student.size();

    int highest = student[0].score;
    int lowest = student[0].score;

    for (int i = 0; i < student.size(); i++){
        highest = getMax(highest,student[i].score);
        lowest = getMin(lowest,student[i].score);
    }
    

    for (int i = 0; i < student.size(); i++){
        if (student[i].score < 60){
            failed++;
        } 
    }
    pass = student.size() - failed;

    cout << "\n|Class average: "<< avg <<"\t";
    cout << "|Highest score: "<< highest <<"\t";
    cout << "|Lowest score: "<< lowest <<endl;
    cout << "|Number of passed: "<< pass <<"\t";
    cout << "|Number of failed: "<< failed;
    cout <<"========================"<<endl;
}

int main(){
    vector<Student> students;
    int d;
    do
    {
        cout << "1. Add student\n2. List all students\n3. Sort by score\n4. Search by id\n5. Show statistics\n0. Exit"<<endl;
        cout <<"========================"<<endl;
        cin >>d;
        switch (d)
        {
        case 1:
        addStudent(students);
            break;
        case 2:
        liststudent(students);
            break;
        case 3:
        sortstudent(students);
            break;
        case 4:
        searchstudent(students);
            break;
        case 5:
        statistics(students);
            break;
        }

    } while (d != 0);

    return 0;
}
