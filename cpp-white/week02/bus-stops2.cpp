#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;


int main() {
    int operations = 0;
    map<set<string>, int> buses;

    cin >> operations;

    while (--operations >= 0) {
        int count;

        cin >> count;

        vector<string> t(count);
        for (string& stop : t) {
            cin >> stop;
        }

        set<string> stops(begin(t), end(t));

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