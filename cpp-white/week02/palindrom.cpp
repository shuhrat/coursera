#include<string>
#include <ctype.h>

using namespace std;

bool IsPalindrom(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        while(!isalnum(str[left])) left++;
        while(!isalnum(str[right])) right--;

        if (str[left] == str[right]) {
            left++;
            right--;
        } else {
            return false;
        }
    }

    return true;
}