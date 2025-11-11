#include <iostream>
#include <thread>
#include <string>

void say_hello(const std::string& name) {
    std::cout << "hello " << name << std::endl;
}

int main(int argc, char * argv[]) {
    std::thread th(say_hello, "world");
    th.join();
return 0;
}