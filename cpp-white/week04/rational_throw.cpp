#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator_, int denominator_) {
        if (denominator_ == 0) {
            throw invalid_argument();
        }

        int commonDivisor = gcd(numerator_, denominator_);
        int sign = (denominator_ > 0) ? 1 : -1;

        numerator = sign * numerator_ / commonDivisor;
        denominator = abs(denominator_) / commonDivisor;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b) {
            int c = a % b;
            a = b;
            b = c;
        }

        return abs(a);
    }
};

Rational operator*(const Rational &lhs, const Rational &rhs) {
    int numerator = lhs.Numerator() * rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error();
    }

    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
