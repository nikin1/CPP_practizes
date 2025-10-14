#include <iostream>

class Stack {
    
    private:
        int m_array[10];
        int len;
    
    
    public:
        void reset() {
            len = 0;
            for (int i = 0; i < 10; i++) {
                m_array[i] = 0;
            }
        }

        bool push (int x) {
            if (len > 9) return false;
            m_array[len] = x;
            len += 1;
            return true;
        }

        bool pop() {
            if (len < 1) return false;

            m_array[len] = 0;
            len -= 1;
            return true;
        }

        void print() const {
            std::cout << "( ";
            for (auto i = 0; i < len; i++) {
                std::cout << m_array[i] << " ";
            }
            std::cout << ")" << std::endl;
        }

};





int main()
{
	Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
 
	return 0;
}


