#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
private:
    int num;
    int denom;

    void normalize() {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int gcd = std::gcd(num, denom);
        num /= gcd;
        denom /= gcd;
        if (denom < 0) {   // Знаменатель положительный
            denom = -denom;
            num = -num;
        }
    }

public:
    Rational(int x = 0, int y = 1) : num(x), denom(y) {
        normalize();
    }

    int Numerator() const { return num; }
    int Denominator() const { return denom; }

    Rational operator+(const Rational& b) const {
        return Rational(num * b.denom + b.num * denom, denom * b.denom);
    }

    Rational operator-(const Rational& b) const {
        return Rational(num * b.denom - b.num * denom, denom * b.denom);
    }

    Rational operator*(const Rational& b) const {
        return Rational(num * b.num, denom * b.denom);
    }

    Rational operator/(const Rational& b) const {
        if (b.num == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Rational(num * b.denom, denom * b.num);
    }

    Rational operator+(int a) const {
        return *this + Rational(a);
    }

    Rational operator-(int a) const {
        return *this - Rational(a);
    }

    Rational operator*(int a) const {
        return *this * Rational(a);
    }

    Rational operator/(int a) const {
        if (a == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return *this / Rational(a);
    }

    Rational& operator+=(const Rational& b) {
        *this = *this + b;
        return *this;
    }

    Rational& operator-=(const Rational& b) {
        *this = *this - b;
        return *this;
    }

    Rational& operator*=(const Rational& b) {
        *this = *this * b;
        return *this;
    }

    Rational& operator/=(const Rational& b) {
        *this = *this / b;
        return *this;
    }

    Rational& operator+=(int a) {
        *this = *this + a;
        return *this;
    }

    Rational& operator-=(int a) {
        *this = *this - a;
        return *this;
    }

    Rational& operator*=(int a) {
        *this = *this * a;
        return *this;
    }

    Rational& operator/=(int a) {
        if (a == 0) {
            throw std::invalid_argument("Division by zero");
        }
        *this = *this / a;
        return *this;
    }

    bool operator==(const Rational& b) const {
        return num == b.num && denom == b.denom;
    }

    bool operator!=(const Rational& b) const {
        return !(*this == b);
    }

    Rational operator-() const {
        return Rational(-num, denom);
    }

    Rational operator+() const {
        return *this;
    }
};

// Оператор умножения int * Rational вне класса
Rational operator*(int a, const Rational& r) {
    return r * a;
}
Rational operator/(int a, const Rational& r) {
    return r / a;
}



// Можно добавить другие операторы с int слева по аналогии

int main() {
    Rational a(1, 2);
    Rational b(3, 4);

    Rational c = a + b;
    Rational d = c - 1;
    Rational e = d * 2;
    Rational f = 2 * e;  // Работает благодаря свободному operator*

    std::cout << "c = " << c.Numerator() << "/" << c.Denominator() << std::endl;
    std::cout << "d = " << d.Numerator() << "/" << d.Denominator() << std::endl;
    std::cout << "e = " << e.Numerator() << "/" << e.Denominator() << std::endl;
    std::cout << "f = " << f.Numerator() << "/" << f.Denominator() << std::endl;

    return 0;
}
