#include <iostream>

class Numbers {
    private:
        int m_a, m_b, m_c;
    public:
        void setValues(int x, int y, int z) {
            m_a = x;
            m_b = y;
            m_c = z;
        }
        void print() const {
            std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">" << std::endl;
        }
};




int main()
{
    Numbers point;
    point.setValues(3.0, 4.0, 5.0);
 
    point.print();
 
    return 0;
}

