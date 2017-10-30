#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<char, int> BuildCharCounters(const string& str) {
    map<char, int> result;

    for(char item: str) {
        result[item]++;
    }

    return result;
};

bool isAnagramm(string string1, string string2) {
    map<char, int> string1_map = BuildCharCounters(string1);
    map<char, int> string2_map = BuildCharCounters(string2);

    if (string1_map.size() != string2_map.size()) {
        return false;
    }

    for(auto item: string1_map) {
        if (string2_map[item.first] != item.second) {
            return false;
        }
    }

    return true;
}


int main() {
    int operations = 0;
    vector<bool> results;


    cin >> operations;

    while (--operations >= 0) {
        string a, b;

        cin >> a >> b;

        results.push_back(isAnagramm(a, b));
    }

    for (auto result: results) {
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}