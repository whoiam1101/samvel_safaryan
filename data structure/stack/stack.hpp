#ifndef STACK_HPP
#define STACK_HPP

template<class T>
class Stack {
private:
    struct Node {
        T _value;
        Node* _next;

        Node() : _next(nullptr) {}
        Node(T value) : _value(value), _next(nullptr) {}
    }* _top;

public:
    // constructors
    Stack() {
        _top = nullptr;
    }

    Stack(T value) {
        _top = new Node(value);
    }

    // destructor
    ~Stack() {
        Node* current_node = _top;
        Node* next = nullptr;
        while (current_node) {
            next = current_node->_next;
            delete current_node;
            current_node = next;
        }
        _top = nullptr;
    }

    // push back new element
    void push(T);

    // pop back last element
    void pop();

    // peek top element
    T peek() const;

    // is empty
    bool isEmpty() const;
};


#endif