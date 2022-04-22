#ifndef STACK_HPP
#define STACK_HPP

template<class T>
class Stack {
private:
    struct Node {
        T _value;
        Node* next;

        Node() : next(nullptr) {}
        Node(T value) : _value(value), next(nullptr) {}
    }* top;

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