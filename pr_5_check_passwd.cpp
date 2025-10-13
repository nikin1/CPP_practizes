#include <iostream>

bool check_passwd(std::string passwd) {
    if (passwd.size() < 8 || passwd.size() > 14)
        return false;



    for (char c : passwd) {
        if (c < 33 || c > 126) {
            return false;
        }
        
        // std::cout << c << "\n";
    }



    return true;
}

int main() {
    std::string passwd;
    std::cin >> passwd;
    if (check_passwd(passwd))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}