#include <iostream>

template <typename T> // объявление параметра шаблона функции
const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}


template <class T>
T average(T *array, int length)
{
    T sum = 0;
    for (int count=0; count < length; ++count)
        sum += array[count];
 
    sum /= length;
    return sum;
}



class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars)
        : m_dollars(dollars)
    {
    }

    friend bool operator>(const Dollars &d1, const Dollars &d2)
    {
        return (d1.m_dollars > d2.m_dollars);
    }


    friend std::ostream& operator<< (std::ostream &out, const Dollars &dollars)
    {
        out << dollars.m_dollars << " dollars ";
        return out;
    }


    Dollars& operator+=(Dollars dollars)
    {
        m_dollars += dollars.m_dollars;
        return *this;
    }
 


    Dollars& operator/=(int value)
    {
        m_dollars /= value;
        return *this;
    }
};


int main()
{
    Dollars seven(7);
    Dollars twelve(12);
 
    Dollars bigger = max(seven, twelve);
 




    int array1[] = { 6, 4, 1, 3, 7 };
    std::cout << average(array1, 5) << '\n';
 
    double array2[] = { 4.25, 5.37, 8.44, 9.25 };
    std::cout << average(array2, 4) << '\n';




    Dollars array3[] = { Dollars(7), Dollars(12), Dollars(18), Dollars(15) };
    std::cout << average(array3, 4) << '\n';
    return 0;
}


