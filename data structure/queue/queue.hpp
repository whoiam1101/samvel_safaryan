#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../linked list/linkedlist.hpp"

template<typename T>
class Queue {
private:
    LinkedList<T> _queue_container;
public:
    // contructor
    Queue() = default;

    // destructor
    ~Queue();

    // pop front
    T popFront();

    // push back
    void pushBack(T);

    // return front and back element
    T front() const;
    T back() const;

    // is empty
    bool isEmpty() const;

    // size of container
    int size() const;
};

template<typename T>
Queue<T>::~Queue() {
    _queue_container.~LinkedList();
}

template<typename T>
T Queue<T>::popFront() {
    T return_value = front();
    _queue_container.removeByIndex(0);
    return return_value;
}

template<typename T>
void Queue<T>::pushBack(T value) {
    _queue_container.addAtIndex(_queue_container.size(), value);
}

template<typename T>
T Queue<T>::front() const {
    return _queue_container[0];
}

template<typename T>
T Queue<T>::back() const {
    return _queue_container[_queue_container.size() - 1];
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return _queue_container.isEmpty();
}

template<typename T>
int Queue<T>::size() const {
    return _queue_container.size();
}

#endif // __QUEUE_H__