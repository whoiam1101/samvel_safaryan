#ifndef __NODE_H__
#define __NODE_H__

struct Node {
    Node* _left;
    Node* _right;
    int _data;

    Node() : _left(nullptr), _right(nullptr) {}
    Node(int data) : _left(nullptr), _right(nullptr), _data(data) {}

    void _clearAll();
};

void Node::_clearAll() {
    Node* left = _left;
    Node* right = _right;
    delete this;
    if (left) {
        left->_clearAll();
    }
    if (right) {
        right->_clearAll();
    }
}

#endif // __NODE_H__