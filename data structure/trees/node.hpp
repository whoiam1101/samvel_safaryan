#ifndef __NODE_H__
#define __NODE_H__

struct Node {
    Node* _left;
    Node* _right;
    int _data;

    Node() : _left(nullptr), _right(nullptr) {}
    Node(int data) : _left(nullptr), _right(nullptr), _data(data) {}
};

#endif // __NODE_H__