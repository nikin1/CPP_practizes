#include <cstdio>
#include <exception>
#include <string>
#include <iostream>

class CannotOpenFileException {
};

class File {
private:
    std::FILE* f;  // тот самый файловый дескриптор, который мы оборачиваем

public:

    File(const File&) = delete;
    File& operator = (const File&) = delete;

    // Конструктор перемещения
    File(File&& other) noexcept {  // File&& — ссылка на временный объект
        f = other.f;
        other.f = nullptr;  // забираем владение дескриптором у временного объекта other!
    }


    // Оператор присваивания с семантикой перемещения
    // File& operator = (File&& other) noexcept {
    //     if (f != nullptr && f != other.f) {
    //         fclose(f);  // закрываем файл у текущего объекта
    //     }
    //     f = other.f;  // забираем владение у временного объекта other
    //     other.f = nullptr;
    //     return *this;
    // }

    File& operator = (File&& other) noexcept {
        std::swap(f, other.f);  // обмениваемся дескрипторами с other
        return *this;
    }







    File(const std::string& name) {
        f = std::fopen(name.c_str(), "r");
        if (f == nullptr) {
            throw CannotOpenFileException();
        }
    }


    // Добавим проверку в деструктор:
    ~File() noexcept {
        if (f != nullptr) {
            fclose(f);
        }
    }

    std::string Read() const {
        char buf[100];
        std::fscanf(f, "%99s", buf);
        return buf;
    }
};



int main() {
    try {
        File file("input.txt");
        auto str = file.Read();
        // ...
    } catch (const CannotOpenFileException&) {
        std::cout << "File open failure!\n";
    }



    File f1("a.txt");
    



    // Problem. Получается, что все 3 объекта обращаются к одному адрессу. Как тогда проводить дескрукторы
    // File f2 = f1;  // конструктор копирования
    // File f3("b.txt");
    // f3 = f1;  // оператор присваивания



}
