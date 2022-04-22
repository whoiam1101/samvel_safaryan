#ifndef STACK_HPP
#define STACK_HPP

template<class T>
class Stack {
private:
    struct Node {
        T _value;
        Node* _next;

        Node() : next(nullptr) {}
        Node(T value) : _value(value), _next(nullptr) {}
    }* _top;

public:
    // constructors
    Stack();
    Stack(T value);

    // destructor
    ~Stack();

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