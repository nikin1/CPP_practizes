
class Figure {
    public:
        virtual int Perimeter() const = 0;
        virtual ~Figure() {}
};

class Triangle: public Figure {
private:
    int m_a, m_b, m_c;
public:
    Triangle(int a, int b, int c) {
        m_a = a;
        m_b = b;
        m_c = c;
    }
    
    int Perimeter() const override {
        return m_a + m_b + m_c;
    }
};


class Rectangle: public Figure {
private:
    int m_a, m_b;
public:
    Rectangle(int a, int b) {
        m_a = a;
        m_b = b;
    }

    int Perimeter() const override {
        return 2 * (m_a + m_b);
    }

};
