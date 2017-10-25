#include <iostream>

using namespace std;

int main() {
    int lower, higher;

    cin >> lower >> higher;

    for(int i=lower; i<=higher; i++) {
        if (i % 2 != 0) continue;

        cout << i << ' ';
    }

    return 0;
}