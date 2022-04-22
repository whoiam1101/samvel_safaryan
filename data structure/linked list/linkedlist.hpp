#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template<class T>
class LinkedList {
private:
    struct Node {
        T _value;
        Node* _prev;
        Node* _next;

        Node() : _prev(nullptr), _next(nullptr) {}
        Node(T value) : _value(value), _prev(nullptr), _next(nullptr) {}
    }* _first, _last;

public:
    // constructors
    LinkedList();
    LinkedList(T value);

    // destructor
    ~LinkedList();

    // get value at index
    T operator [](int);

    // remove by index
    void removeByIndex(int);

    // add at index
    void addAtIndex(int, T);

    // count of nodes
    int size() const;

    // is empty
    bool isEmpty() const;
};

#endif