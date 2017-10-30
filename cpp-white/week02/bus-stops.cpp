#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


int main() {
    int operations = 0;
    map<vector<string>, int> buses;

    cin >> operations;

    while (--operations >= 0) {
        int count;

        cin >> count;

        vector<string> stops(n);
        for (string& stop : stops) {
            cin >> stop;
        }

        if (buses.count(stops) == 1) {
            cout << "Already exists for " << buses[stops] << endl;
        } else {
            int num = buses.size() + 1;

            buses[stops] = num;

            cout << "New bus " << num << endl;
        }
    }

    return 0;
}