#ifndef __DEQUE_H__
#define __DEQUE_H__

#include "../linked list/linkedlist.hpp"

template<typename T>
class Deque {
private:
    LinkedList<T> _deque_container;

public:
    // constructor
    Deque() = default;

    // destructor
    ~Deque();

    // push front and push back
    void pushFront(T);
    void pushBack(T);

    // pop front and pop back
    T popFront();
    T popBack();

    // get front and get back
    T front() const;
    T back() const;

    // is empty
    bool isEmpty() const;

    // size
    int size() const;
};

template<typename T>
Deque<T>::~Deque() {
    _deque_container.~LinkedList();
}

template<typename T>
void Deque<T>::pushFront(T value) {
    _deque_container.addAtIndex(0, value);
}

template<typename T>
void Deque<T>::pushBack(T value) {
    _deque_container.addAtIndex(_deque_container.size(), value);
}

template<typename T>
T Deque<T>::popFront() {
    T return_value = front();
    _deque_container.removeByIndex(0);
    return return_value;
}

template<typename T>
T Deque<T>::popBack() {
    T return_value = back();
    _deque_container.removeByIndex(_deque_container.size() - 1);
    return return_value;
}

template<typename T>
T Deque<T>::front() const {
    return _deque_container[0];
}

template<typename T>
T Deque<T>::back() const {
    return _deque_container[_deque_container.size() - 1];
}

template<typename T>
bool Deque<T>::isEmpty() const {
    return _deque_container.isEmpty();
}

template<typename T>
int Deque<T>::size() const {
    return _deque_container.size();
}

#endif // __DEQUE_H__