#include <iostream>
#include <string>

using namespace std;

class BankAccount {

    string ownerName;
    double balance;

public:
    BankAccount(string owner, double initBalance) {
        ownerName = owner;
        if (initBalance < 0) {
            cout << "Начальный баланс не может быть отрицательным. Ставим 0." << endl;
            balance = 0;
        } else {
            balance = initBalance;
        }
    }



    
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Сумма " << amount << " добавлена." << endl;
        } else {
            cout << "Нельзя положить отрицательное!" << endl;
        }
    }


    bool withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Вы сняли " << amount << endl;
            return true;
        }
        cout << "Недостаточно средств или неверная сумма!" << endl;
        return false;
    }

    void printInfo() {
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << endl;
    }
};

int main() {
    BankAccount acc("Иван", 1000);

    acc.printInfo();

    acc.deposit(500);
    acc.withdraw(200);
    acc.withdraw(1500);

    acc.printInfo();

    return 0;
}
