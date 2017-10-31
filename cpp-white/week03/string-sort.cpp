#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>

using namespace std;

int main() {
    int n = 0;

    cin >> n;
    vector<string> v(n);

    for (auto &i: v) {
        cin >> i;
    }

    sort(begin(v), end(v), [](string a, string b) {
        for (auto &i: a) {
            i = tolower(i);
        }

        for (auto &i: b) {
            i = tolower(i);
        }

        return a < b;
    });

    for (const auto &i: v) {
        cout << i << " ";
    }

    return 0;
}