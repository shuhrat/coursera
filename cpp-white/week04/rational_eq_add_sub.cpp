#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator_, int denominator_) {
        int commonDivisor = gcd(numerator_, denominator_);
        int sign = (denominator_ > 0) ? 1 : -1;

        numerator = sign * numerator_/commonDivisor;
        denominator = abs(denominator_)/commonDivisor;
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

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator()) {
        return lhs.Denominator() == rhs.Denominator();
    }

    return false;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int lhsNumerator = lhs.Numerator() * rhs.Denominator();
    int rhsNumerator = rhs.Numerator() * lhs.Denominator();

    return lhsNumerator < rhsNumerator;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int numerator = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int numerator = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}


Rational operator/(const Rational& lhs, const Rational& rhs) {
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
