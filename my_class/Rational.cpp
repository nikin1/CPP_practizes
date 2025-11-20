#include <iostream>

class Rational {

private:
    int num;
    int denom;
public:
    Rational(int x, int y) {
        num = x;
        denom = y;
    }
    Rational(): num(0), denom(-1) {}


    int get_num() {
        return num;
    }
    int get_denom() {
        return denom;
    }


    void set_num(int x) {
        num = x;
    }
    void set_denom(int y) {
        denom = y;
    }


    // 1-ый const - не меняем число b, второй - не меняем текущий объект
    Rational operator-(const Rational& b) const {
        return Rational(num - b.num, b.denom);
    }
    Rational operator-(int a) const {
        return Rational(num - a * denom, denom);
    }
    Rational operator-() const {
        return Rational(num * -1, denom);
    }





    Rational operator+(const Rational& b) const {
        return Rational(num + b.num, b.denom);
    }
    Rational operator+(int a) const {
        return Rational(num + a * denom, denom);
    }
    Rational operator+() const {
        return Rational(num, denom);
    }


    Rational operator*(const Rational& b) const {
        return Rational(num * b.num, denom * b.denom);
    }
    Rational operator*(int a) const {
        return Rational(num * a, denom);
    }

    Rational operator/(const Rational& b) const {
        return Rational(num * b.denom, denom * b.num);
    }
    Rational operator/(int a) const {
        return Rational(num, denom * a);
    }


};



int main() {
    Rational a(1, 2);
    Rational b(3, 2);
    // y = a + b;
    // Rational y = b - a;

    Rational y = a + 1;

    std::cout << "y = " << y.get_num() << "/" << y.get_denom() << std::endl;
 

    return 0;
}

