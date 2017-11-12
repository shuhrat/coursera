#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (auto &student: students) {
        cin >> student.name >> student.surname;
        cin >> student.day >> student.month >> student.year;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string operation;
        int num;

        cin >> operation >> num;

        int student = num - 1;

        if (num > n || 0 >= num) {
            cout << "bad request" << endl;
            continue;
        }

        if (operation == "name") {
            cout << students[student].name << " " << students[student].surname << endl;
        } else if (operation == "date") {
            cout << students[student].day << "." << students[student].month << "." << students[student].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
