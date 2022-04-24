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
    T pop();

    // peek top element
    T peek() const;

    // is empty
    bool isEmpty() const;
};

// push back new element
template<class T>
void Stack<T>::push(T value) {
    Node* top = new Node(value);
    top->_next = _top;
    _top = top;
}

// pop back last element
template<class T>
T Stack<T>::pop() {
    T return_value = _top->_value;
    Node* temporary_node = _top;
    _top = _top->_next;
    delete temporary_node;
    return return_value;
}

// peek _top element
template<class T>
T Stack<T>::peek() const {
    return _top->_value;
}

// is empty
template<class T>
bool Stack<T>::isEmpty() const {
    return _top == nullptr;
}

#endif