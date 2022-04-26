#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template<typename T>
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
    Stack();
    Stack(T);

    // destructor
    ~Stack();

    // push back new element
    void push(T);

    // pop back last element
    T pop();

    // peek top element
    T peek() const;

    // is empty
    bool isEmpty() const;
};

// push back new element
template<typename T>
void Stack<T>::push(T value) {
    Node* top = new Node(value);
    top->_next = _top;
    _top = top;
}

// pop back last element
template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::invalid_argument("Stack is empty!");
    }
    T return_value = _top->_value;
    Node* temporary_node = _top;
    _top = _top->_next;
    delete temporary_node;
    return return_value;
}

// peek _top element
template<typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::invalid_argument("Stack is empty!");
    }
    return _top->_value;
}

// is empty
template<typename T>
bool Stack<T>::isEmpty() const {
    return _top == nullptr;
}

// constructors
template<typename T>
Stack<T>::Stack() {
    _top = nullptr;
}

template<typename T>
Stack<T>::Stack(T value) {
    _top = new Node(value);
}

// destructor
template<typename T>
Stack<T>::~Stack() {
    Node* current_node = _top;
    Node* next = nullptr;
    while (current_node) {
        next = current_node->_next;
        delete current_node;
        current_node = next;
    }
    _top = nullptr;
}

#endif