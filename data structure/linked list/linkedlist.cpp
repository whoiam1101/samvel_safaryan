#include "linkedlist.hpp"

#include <cassert>

// get value at index
template<class T>
T LinkedList<T>::operator [](int index) {
    assert(("Index out of bounds exception!", 0 <= index && index < size()));
    Node<T>* temporary_node = _first;
    while (index--) {
        temporary_node = temporary_node->_next;
    }
    return temporary_node->_value;
}

// remove by index
template<class T>
void LinkedList<T>::removeByIndex(int index) {
    assert(("Index out of bounds exception!", 0 <= index && index < size()));
    Node<T>* temporary_node = _first;
    while (index--) {
        temporary_node = temporary_node->_next;
    }
    Node<T>* prev = temporary_node->_prev;
    Node<T>* next = temporary_node->_next;
    if (prev) prev->_next = next;
    if (next) next->_prev = prev;
    delete temporary_node;
    _size--;
    if (!prev && !next) {
        _first = nullptr;
        _last  = nullptr;
    }
}

// add at index
template<class T>
void LinkedList<T>::addAtIndex(int index, T value) {
    assert(("Index out of bounds exception!", 0 <= index && index <= size()));
    if (index < size()) {
        Node<T>* temporary_node = _first;
        index--;
        while (index--) {
            temporary_node = temporary_node->_next;
        }
        Node<T>* prev = temporary_node->_prev;
        Node<T>* node = new Node(value);
        if (prev) prev->_next = node;
        node->_prev = prev;
        node->_next = temporary_node;
        temporary_node->_prev = node;
    } else {
        Node<T>* node = new Node(value);
        _last->_next = node;
        node->_prev  = _last;
        _last = node;
    }
    _size++;
}

// count of nodes
template<class T>
int LinkedList<T>::size() const {
    return _size;
}

// is empty
template<class T>
bool LinkedList<T>::isEmpty() const {
    return _size == 0;
}

// print all elements in list
template<class T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& list) {
    Node<T>* temporary_node = list._first;
    while (temporary_node) {
        out << temporary_node->_value << " ";
        temporary_node = temporary_node->_next;
    }
    return out;
}

// constructors
template<class T>
LinkedList<T>::LinkedList() {
    _first = nullptr;
    _last  = nullptr;
    _size = 0;
}

template<class T>
LinkedList<T>::LinkedList(T value) {
    _first = new Node(value);
    _last  = _first;
    _size = 1;
}

// destructor
template<class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current_node = _first;
    Node<T>* next = nullptr;
    while (current_node) {
        next = current_node->_next;
        delete current_node;
        current_node = next;
    }
    _first = nullptr;
    _last  = nullptr;
    _size = 0;
}