#include <memory>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;  // узел владеет следующим узлом
    };

    std::unique_ptr<Node> head;  // сам список владеет начальным узлом

public:
    void PushFront(const T& elem) {
        head = std::make_unique<Node>(elem, std::move(head));
    }

    void PopFront() {
        head = std::move(head->next);
    }

    const T& Front() const {
        return head->data;
    }

    bool Empty() const {
        return head == nullptr;
    }

    ~ForwardList() {
        // Можно было бы оставить деструктор пустым — всё корректно бы удалилось,
        // но на больших списках мог бы переполниться стек вызовов из-за рекурсии в деструкторе Node.
        while (!Empty()) {
            PopFront();
        }
    }

};
