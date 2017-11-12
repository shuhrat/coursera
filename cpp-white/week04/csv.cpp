#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;


int main() {
    ifstream input("input.txt");

    if (input) {
        double N, M;

        input >> N >> M;

        for(int row=0; row < N; row++) {
            for(int col=0; col < M; col++) {
                int value;
                input >> value;
                input.ignore(1);
                cout << setw(10) << value;
                if (col < M - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
