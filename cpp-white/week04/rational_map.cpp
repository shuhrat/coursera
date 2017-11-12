#include <iostream>
#include <map>
#include <set>
#include <vector>
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

istream &operator>>(istream &stream, Rational &rational) {
    if (stream.eof()) {
        return stream;
    }

    int numerator, denominator;

    stream >> numerator;
    stream.ignore(1);
    stream >> denominator;

    rational = {numerator, denominator};

    return stream;
}

ostream &operator<<(ostream &stream, const Rational &rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();

    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
