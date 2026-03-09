
#include <iostream>
using namespace std;

class Rational{
private:
    int numerator;
    int denominator;

public:
    Rational(int a = 0, int b = 1){
        numerator = a;
        denominator = b;
    }

    Rational operator+(const Rational& other) const{
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator-(const Rational& other) const{
        return Rational(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator*(const Rational& other) const{
        return Rational(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }

    Rational operator/(const Rational& other) const{
        return Rational(
            numerator * other.denominator,
            denominator * other.numerator
        );
    }

    bool operator==(const Rational& other) const{
        return numerator * other.denominator == other.numerator * denominator;
    }

    operator double() const{
        return (double)numerator / denominator;
    }

    friend ostream& operator<<(ostream& os, const Rational& r){
        os << r.numerator << "/" << r.denominator;
        return os;
    }
};

int main(){

    Rational r1(1,2);
    Rational r2(3,4);

    Rational sum = r1 + r2;
    Rational diff = r1 - r2;
    Rational prod = r1 * r2;
    Rational quot = r1 / r2;

    bool equal = r1 == r2;
    double value = r1;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;
    cout << "Equal: " << equal << endl;
    cout << "Value: " << value << endl;

    return 0;
}