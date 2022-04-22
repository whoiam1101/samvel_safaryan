#include "stack.hpp"

// push back new element
template<class T>
void Stack<T>::push(T value) {
    Node* new_top = new Node(value);
    new_top->next = top;
    top = new_top;
}

// pop back last element
template<class T>
void Stack<T>::pop() {
    top = top->next;
}

// peek top element
template<class T>
T Stack<T>::peek() const {
    return top->_value;
}

// is empty
template<class T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

// constructors
template<class T>
Stack<T>::Stack() {
    top = nullptr;
}

template<class T>
Stack<T>::Stack(T value) {
    top = new Node(value);
}

// destructor
template<class T>
Stack<T>::~Stack() {
    while (top->next) {
        delete top;
        top = top->next;
    }
}
