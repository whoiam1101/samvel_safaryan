#include "linkedlist.hpp"

#include <cassert>

// get value at index
template<class T>
T LinkedList<T>::operator [](int index) {
    Node* temporary_node = _first;
    while (temporary_node && index--) {
        temporary_node = temporary_node->_next;
    }
    assert(("Index out of bounds exception!", temporary_node));
    return temporary_node->_value;
}

// remove by index
template<class T>
void LinkedList<T>::removeByIndex(int index) {
    Node* temporary_node = _first;
    while (temporary_node && index--) {
        temporary_node = temporary_node->_next;
    }
    assert(("Index out of bounds exception!", temporary_node));
    Node* prev = temporary_node->_prev;
    Node* next = temporary_node->_next;
    if (prev) prev->_next = next;
    if (next) next->_prev = prev;
    delete temporary_node;
    if (!prev && !next) _first = nullptr;
}

// add at index
template<class T>
void LinkedList<T>::addAtIndex(int index, T value) {
    if (index > 0) {
        Node* temporary_node = _first;
        index--;
        while (temporary_node && index--) {
            temporary_node = temporary_node->_next;
        }
        assert(("Index out of bounds exception!", temporary_node));
        Node* next = temporary_node->_next;
        Node* node = new Node(value);
        if (next) next->_prev = node;
        node->_next = next;
        node->_prev = temporary_node;
        temporary_node->_next = node;
    } else {
        _first = new Node(value);
    }
}

// count of nodes
template<class T>
int LinkedList<T>::size() const {
    int size = 0;
    Node* temporary_node = _first;
    while (temporary_node) {
        size++;
        temporary_node = temporary_node->_next;
    }
    return size;
}

// is empty
template<class T>
bool LinkedList<T>::isEmpty() const {
    return _first == nullptr;
}

// constructors
template<class T>
LinkedList<T>::LinkedList() {
    _first = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(T value) {
    _first = new Node(value);
}

// destructor
template<class T>
LinkedList<T>::~LinkedList() {
    Node* current_node = _first;
    Node* next = nullptr;
    while (current_node) {
        next = current_node->_next;
        delete current_node;
        current_node = next;
    }
    _first = nullptr;
}