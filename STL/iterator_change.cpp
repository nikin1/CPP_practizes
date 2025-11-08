#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};

    // Iterator pointing to the first element
    auto it = v.begin();

    // Dereferencing iterator to access value
    cout << "First element: " << *it << endl;

    // Dereferencing iterator to update value
    *it = 100;

    // Printing updated first element
    cout << "Updated first element: " << *it << endl;

    return 0;
}