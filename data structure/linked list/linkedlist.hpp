#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <ostream>

template<typename T>
struct Node {
    T _value;
    Node* _prev;
    Node* _next;

    Node() : _prev(nullptr), _next(nullptr) {}
    Node(T value) : _value(value), _prev(nullptr), _next(nullptr) {}
};

template<class T>
class LinkedList {
private:
    Node<T>* _first, _last;
    int _size;

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

    // print all elements in list
    friend std::ostream& operator << (std::ostream&, const LinkedList<T>&);
};

#endif