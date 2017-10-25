#include <iostream>
#include <cmath>

using namespace std;

bool is_zero(float value) {
    return value == 0;
}

int main() {
    double a, b, c;

    cin >> a >> b >> c;

    if (is_zero(a)) {
        if (is_zero(b)) {
            // a=0, b=0, c = 0
            cout << 0 << endl;
        } else {
            // a=0, x = -c/b
            cout << -c / b << endl;
        }
    } else if (is_zero(c)) {
        // c=0, x = -b/a
        cout << 0 << ' '<<  -b / a << endl;
    } else {
        const double discriminant = b * b - 4 * a * c;

        if (is_zero(discriminant)) {
            cout << -b / (2 * a) << endl;
        } else if (discriminant < 0) {
            return 0;
        } else {
            double root1, root2;

            if (b > 0) {
                root1 = (-b - sqrt(discriminant)) / (2 * a);
                root2 = c / (a * root1);
            } else {
                root1 = 2 * c / (-b + sqrt(discriminant));
                root2 = c / (a * root1);
            }

            cout << root1 << ' ' << root2 << endl;
        }
    }

    return 0;
}