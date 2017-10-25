#include <iostream>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }

    cout << abs(a) << endl;

    return 0;
}