#include "stack.hpp"

#include <cassert>

// push back new element
template<class T>
void Stack<T>::push(T value) {
    Node* top = new Node(value);
    top->_next = _top;
    _top = top;
}

// pop back last element
template<class T>
void Stack<T>::pop() {
    assert(("Stack is empty!", !isEmpty()));
    _top = _top->_next;
}

// peek _top element
template<class T>
T Stack<T>::peek() const {
    assert(("Stack is empty!", !isEmpty()));
    return _top->_value;
}

// is empty
template<class T>
bool Stack<T>::isEmpty() const {
    return _top == nullptr;
}
