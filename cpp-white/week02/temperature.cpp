#include<iostream>
#include<string>
#include<vector>
#include <ctype.h>

using namespace std;

int main() {
    int n = 0, sum = 0;
    vector<int> temperatures, high;

    cin >> n;
    temperatures.resize(n, 0);

    for(int& temperature: temperatures) {
        cin >> temperature;
        sum += temperature;
    }

    sum/=n;

    n = 0;
    for(auto temperature: temperatures) {
        if (temperature > sum) {
            high.push_back(n);
        }
        n++;
    }

    cout << high.size() << endl;
    for(auto index: high) {
        cout << index << " ";
    }

    return 0;
}