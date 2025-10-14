#include <iostream>


class Numbers {
    private:
        int a, b;
    public:
        Numbers() : a(0), b(0) {}
        Numbers(int x, int y) : a(x), b(y) {}
        
        void set(int x, int y) {
            a = x;
            b = y;
        }
        void print() const {
            std::cout << "a = " << a << ", b = " << b << std::endl;
        }
};




int main() {
	Numbers n1;
	n1.set(3, 3); // инициализируем объект n1 значениями 3 и 3
	
	Numbers n2{ 4, 4 }; // инициализируем объект n2 значениями 4 и 4
 
	n1.print();
	n2.print();
    return 0;
}