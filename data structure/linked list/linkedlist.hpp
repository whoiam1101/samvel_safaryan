#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <ostream>

template<typename T>
struct Node {
    T _value;
    Node<T>* _prev;
    Node<T>* _next;

    Node() : _prev(NULL), _next(NULL) {}
    Node(T value) : _value(value), _prev(NULL), _next(NULL) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* _first;
    Node<T>* _last;
    int _size;

public:
    // constructors
    LinkedList();
    LinkedList(T);

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
    template<class TT>
    friend std::ostream& operator << (std::ostream&, const LinkedList<TT>&);
};

#endif