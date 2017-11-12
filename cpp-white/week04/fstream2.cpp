#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;


int main() {
    ifstream input("input.txt");

    if (input) {
        double value;

        cout << fixed << setprecision(3);

        while (!input.eof()) {
            input >> value;
            cout << value << endl;
        }
    }

    return 0;
}
