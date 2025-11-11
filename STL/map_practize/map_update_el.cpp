#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m = {{1, "Geeks"},
             {2, "For"}, {3, "Geeks"}};

    // Updating value
    m[0] = "Tweaks";
    m.at(1) = "By";
    
    cout << m[0] << endl;
    cout << m.at(1);
    return 0;
}

