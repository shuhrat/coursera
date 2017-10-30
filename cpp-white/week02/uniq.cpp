#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {
    int operations = 0;
    set<string> lines;

    cin >> operations;

    while (--operations >= 0) {
        string line;

        cin >> line;
        lines.insert(line);
    }

    cout << lines.size() << endl;

    return 0;
}