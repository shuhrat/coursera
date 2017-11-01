#include<string>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {
        str = "";
    }

    ReversibleString(const string &new_str) {
        str = new_str;
    }

    string ToString() const {
        return str;
    }

    void Reverse() {
        int size = str.length() - 1;
        int mid = str.length() / 2;

        for (int i = 0; i < mid; ++i) {
            char temp = str[i];
            str[i] = str[size - i];
            str[size - i] = temp;
        }
    }

private:
    string str;
};
