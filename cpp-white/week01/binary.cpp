#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int decimal;
    vector<int> binary;

    cin >> decimal;

    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary.push_back(0);
        } else {
            binary.push_back(1);
        }

        decimal /= 2;
    }

    reverse(begin(binary), end(binary));

    bool flag = true;
    for(auto bit: binary) {
        if (flag && bit == 0) continue;
        flag = false;

        cout << bit;
    }

    return 0;
}