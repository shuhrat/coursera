#include <iostream>

using namespace std;

int main() {
    double total;
    double lower, higher;
    double discount_lower, discount_higher;
    double discount = 0;

    cin >> total >> lower >> higher >> discount_lower >> discount_higher;

    if (total > lower) {
        discount = discount_lower;
    }

    if (total > higher) {
        discount = discount_higher;
    }

    cout << total * (1 - discount/100) << endl;
    return 0;
}