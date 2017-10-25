#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int index;
    int count = 0;
    char needle = 'f';

    cin >> str;

    for(index = 0; index <= str.length(); index++) {
        if (str[index] != needle) continue;

        count++;
        if (count == 2) break;
    }

    if (count == 0) index = -2;
    if (count == 1) index = -1;

    cout << index << endl;

    return 0;
}