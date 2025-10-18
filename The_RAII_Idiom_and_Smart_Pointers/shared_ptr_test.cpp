#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(17);
    std::cout << *ptr1 << "\n";  // 17
    std::cout << ptr1.use_count() << "\n";  // 1

    auto ptr2 = ptr1;  // копирование разрешено!
    std::cout << *ptr1 << "\n";  // 17
    std::cout << *ptr2 << "\n";  // 17 — это всё тот же объект
    std::cout << ptr1.use_count() << "\n";  // 2
    std::cout << ptr2.use_count() << "\n";  // 2

    std::shared_ptr<int> ptr3;
    std::cout << ptr3.use_count() << "\n";  // 0

    ptr3 = ptr1;  // присваивание тоже разрешено!
    std::cout << *ptr3 << "\n";  // 17
    std::cout << ptr1.use_count() << "\n";  // 3
    std::cout << ptr2.use_count() << "\n";  // 3
    std::cout << ptr3.use_count() << "\n";  // 3
}
