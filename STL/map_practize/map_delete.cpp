#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m = {{1, "Geeks"},
             {2, "For"}, {3, "Geeks"}};

    // Deleting by key
    m.erase(2);
    
    // Deleting by iterator
    m.erase(m.begin());
    
    for(auto i : m)
        cout << i.first << " " << i.second
        << endl;
    return 0;
}
