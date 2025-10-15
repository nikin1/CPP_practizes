#include <iostream>
 
template <typename T>
const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}
 
int main()
{
    int i = max(4, 8);
    std::cout << i << '\n';
 
    double d = max(7.56, 21.434);
    std::cout << d << '\n';
 
    char ch = max('b', '9');
    std::cout << ch << '\n';
 
    return 0;
}