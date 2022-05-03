#ifndef __TREE_H__
#define __TREE_H__

#include <queue>
#include <iostream>
#include <limits>
#include <algorithm>

#include "node.hpp"

using std::cout;
using std::endl;
using std::queue;

const int PLUS_INFINITY = std::numeric_limits<int>::max();
const int MINUS_INFINITY = std::numeric_limits<int>::min();

class Tree {
private:
    Node* root;

    void insert(Node*, int);

    void dfs(Node*) const;
    void bfs(Node*) const;

    bool isExist(Node*, int) const;

    int sum(Node*) const;
    int min(Node*) const;
    int max(Node*) const;

public:
    Tree();
    Tree(int data);

    ~Tree();

    void insert(int);

    void dfs() const;
    void bfs() const;

    bool isExist(int) const;

    int sum() const;
    int min() const;
    int max() const;
};

Tree::Tree() {
    root = nullptr;
}

Tree::Tree(int data) {
    root = new Node(data);
}

Tree::~Tree() {
    root->_clearAll();
}

void Tree::insert(Node* node, int data) {
    queue<Node*> vertex;
    vertex.push(node);
    while (!vertex.empty()) {
        Node* current_node = vertex.front();
        vertex.pop();
        if (current_node->_left) {
            vertex.push(current_node->_left);
        } else {
            current_node->_left = new Node(data);
            return;
        }
        if (current_node->_right) {
            vertex.push(current_node->_right);
        } else {
            current_node->_right = new Node(data);
            return;
        }
    }
}

void Tree::insert(int data) {
    if (root) {
        insert(root, data);
    } else {
        root = new Node(data);
    }
}

void Tree::dfs(Node* node) const {
    if (node) {
        cout << node->_data << " ";
        dfs(node->_left);
        dfs(node->_right);
    }
}

void Tree::dfs() const {
    dfs(root);
}

void Tree::bfs(Node* node) const {
    if (node) {
        queue<Node*> vertex;
        vertex.push(node);
        while (!vertex.empty()) {
            Node* current_node = vertex.front();
            vertex.pop();
            cout << current_node->_data << " ";
            if (current_node->_left) {
                vertex.push(current_node->_left);
            }
            if (current_node->_right) {
                vertex.push(current_node->_right);
            }
        }
    }
}

void Tree::bfs() const {
    bfs(root);
}

bool Tree::isExist(Node* node, int data) const {
    if (node) {
        if (node->_data == data) {
            return true;
        }
        return isExist(node->_left, data) || isExist(node->_right, data);
    }
    return false;
}

bool Tree::isExist(int data) const {
    return isExist(root, data);
}

int Tree::sum(Node* node) const {
    if (node) {
        return node->_data + sum(node->_left) + sum(node->_right);
    }
    return 0;
}

int Tree::sum() const {
    return sum(root);
}

int Tree::min(Node* node) const {
    if (node) {
        return std::min(node->_data, std::min(min(node->_left), min(node->_right)));
    }
    return PLUS_INFINITY;
}

int Tree::min() const {
    return min(root);
}

int Tree::max(Node* node) const {
    if (node) {
        return std::max(node->_data, std::max(max(node->_left), max(node->_right)));
    }
    return MINUS_INFINITY;
}

int Tree::max() const {
    return max(root);
}

#endif // __TREE_H__