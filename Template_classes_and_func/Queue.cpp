#include <iostream>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    std::deque<T> data;

public:
    Queue() = default;

    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        T value = data.front();
        data.pop_front();
        return value;
    }

    void push (const T& value) {
        data.push_back(value);
    }

    const T& front() const {
        if (data.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    T& front() {
        if (data.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }


    int size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

    bool operator == (const Queue<T, Container>& other) const {
        return data == other.data;
    }

};













int main() {
    Queue<int> queue1;
    queue1.push(10);
    queue1.push(20);
    queue1.push(30);

    std::cout << "Queue size: " << queue1.size() << '\n';
    std::cout << "Front element: " << queue1.front() << '\n';

    // std::cout << "Popped element: " << queue1.pop() << '\n';
    // std::cout << "Queue size after pop: " << queue1.size() << '\n';


    Queue<std::string> queue2;
    queue2.push("Hello");
    queue2.push("World");

    std::cout << "Queue size: " << queue2.size() << '\n';
    std::cout << "Front element: " << queue2.front() << '\n';

    std::cout << "Popped element: " << queue2.pop() << '\n';
    std::cout << "Queue size after pop: " << queue2.size() << '\n';



    Queue<int> queue3;
    queue3.push(10);
    queue3.push(20);
    queue3.push(30);

    std::cout << " == " << (queue1 == queue3) << std::endl;
    return 0;
}




