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

// get value at index
template<typename T>
T LinkedList<T>::operator [](int index) {
    Node<T>* temporary_node = _first;
    while (index--) {
        temporary_node = temporary_node->_next;
    }
    return temporary_node->_value;
}

// remove by index
template<typename T>
void LinkedList<T>::removeByIndex(int index) {
    Node<T>* temporary_node = _first;
    while (index--) {
        temporary_node = temporary_node->_next;
    }
    Node<T>* prev = temporary_node->_prev;
    Node<T>* next = temporary_node->_next;
    if (prev) {
        prev->_next = next;
    }
    if (next) {
        next->_prev = prev;
    }
    delete temporary_node;
    _size--;
    if (!prev && !next) {
        _first = NULL;
        _last  = NULL;
    }
}

// add at index
template<typename T>
void LinkedList<T>::addAtIndex(int index, T value) {
    Node<T>* node = new Node<T>(value);
    if (index < size()) {
        Node<T>* temporary_node = _first;
        index--;
        while (index--) {
            temporary_node = temporary_node->_next;
        }
        Node<T>* prev = temporary_node->_prev;
        if (prev) {
            prev->_next = node;
        }
        node->_prev = prev;
        node->_next = temporary_node;
        temporary_node->_prev = node;
    } else {
        if (!isEmpty()) {
            _last->_next = node;
            node->_prev  = _last;
            _last = node;
        } else {
            _first = node;
            _last = node;
        }
    }
    _size++;
}

// count of nodes
template<typename T>
int LinkedList<T>::size() const {
    return _size;
}

// is empty
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return _size == 0;
}

// print all elements in list
template<typename T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& list) {
    struct Node<T>* temporary_node = list._first;
    while (temporary_node) {
        out << temporary_node->_value << " ";
        temporary_node = temporary_node->_next;
    }
    return out;
}

// constructors
template<typename T>
LinkedList<T>::LinkedList() {
    _first = NULL;
    _last = NULL;
    _size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T value) {
    _first = new Node<T>(value);
    _last = _first;
    _size = 1;
}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current_node = _first;
    Node<T>* next = NULL;
    while (current_node) {
        next = current_node->_next;
        delete current_node;
        current_node = next;
    }
    _first = NULL;
    _last = NULL;
    _size = 0;
}

#endif