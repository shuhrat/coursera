#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n = 0;

    cin >> n;
    vector<int> v(n);

    for (auto &i: v) {
        cin >> i;
    }

    sort(begin(v), end(v), [](const int& a, const int& b) {
        return abs(a) < abs(b);
    });

    for (const auto &i: v) {
        cout << i << " ";
    }

    return 0;
}