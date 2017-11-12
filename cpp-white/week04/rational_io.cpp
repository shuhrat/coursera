#include <iostream>
#include <sstream>
#include <istream>
#include <ostream>

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

bool operator==(const Rational &lhs, const Rational &rhs) {
    if (lhs.Numerator() == rhs.Numerator()) {
        return lhs.Denominator() == rhs.Denominator();
    }

    return false;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    int lhsNumerator = lhs.Numerator() * rhs.Denominator();
    int rhsNumerator = rhs.Numerator() * lhs.Denominator();

    return lhsNumerator < rhsNumerator;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
    int numerator = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    int numerator = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    int numerator = lhs.Numerator() * rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();

    return {numerator, denominator};
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;
    is >> n >> c >> d;
    if (is && c == '/') {
        r = Rational(n, d);
    }
    return is;
}

ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}

int main() {
    Rational a, b;
    char operation;
    cin >> a >> operation >> b;

    switch (operation) {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
    }
    return 0;
}
