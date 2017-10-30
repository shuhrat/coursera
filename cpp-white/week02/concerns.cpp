#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


int main() {
    int operations = 0;
    int counter = 0;

    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    map<int, vector<string>> todo;

    cin >> operations;

    while (--operations >= 0) {
        string operation;

        cin >> operation;

        if (operation == "ADD") {
            int day;
            string job;

            cin >> day >> job;

            todo[day].push_back(job);
        }

        if (operation == "NEXT") {
            int month = counter % 12;
            int days_in_current_month = months[month];
            int days_in_next_month = months[month + 1];

            if (days_in_current_month > days_in_next_month) {
                while (days_in_current_month > days_in_next_month) {
                    for(auto job: todo[days_in_current_month]) {
                        todo[days_in_next_month].push_back(job);
                    }
                    todo.erase(days_in_current_month);
                    days_in_current_month--;
                }
            }
            counter++;
        }

        if (operation == "DUMP") {
            int day;

            cin >> day;

            cout << todo[day].size() << " ";
            for(auto item: todo[day]) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    return 0;
}