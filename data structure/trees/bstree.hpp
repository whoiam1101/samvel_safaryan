#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stdexcept>
#include <queue>
#include <iostream>
#include <algorithm>

#include "node.hpp"

using std::cout;
using std::endl;
using std::queue;
using std::invalid_argument;

class BSTree {
private:
    Node* root;

    Node* search(Node*, int) const;

    Node* remove(Node*, int);
    void insert(Node*, int);

    void bfs(Node*) const;
    void dfs(Node*) const;
    void sortedPrinting(Node*) const;

    int min(Node*) const;
    int max(Node*) const;
    int sum(Node*) const;

public:
    BSTree();
    BSTree(int);

    ~BSTree();

    Node* search(int) const;

    void insert(int);
    void remove(int);

    void bfs() const;
    void dfs() const;
    void sortedPrinting() const;

    int min() const;
    int max() const;
    int sum() const;

    bool isEmpty() const;
};

BSTree::BSTree() {
    root = nullptr;
}

BSTree::BSTree(int data) {
    root = new Node(data);
}

BSTree::~BSTree() {
    root->_clearAll();
}

Node* BSTree::search(Node* node, int data) const {
    Node* temporary_node = node;
    while (temporary_node) {
        if (temporary_node->_data == data) {
            return temporary_node;
        } else if (temporary_node->_left && temporary_node->_data > data) {
            temporary_node = temporary_node->_left;
        } else {
            temporary_node = temporary_node->_right;
        }
    }
    return nullptr;
}

Node* BSTree::search(int data) const {
    return search(root, data);
}

void BSTree::insert(Node* node, int data) {
    if (node->_data > data) {
        if (node->_left) {
            insert(node->_left, data);
        } else {
            node->_left = new Node(data);
        }
    } else {
        if (node->_right) {
            insert(node->_right, data);
        } else {
            node->_right = new Node(data);
        }
    }
}

void BSTree::insert(int data) {
    if (root) {
        insert(root, data);
    } else {
        root = new Node(data);
    }
}

Node* BSTree::remove(Node* node, int data) {
    if (node) {
        if (node->_data != data) {
            if (data < node->_data) {
                node->_left = remove(node->_left, data);
            } else {
                node->_right = remove(node->_right, data);
            }
        } else if (!(node->_left) && !(node->_right)) {
            node = nullptr;
        } else if (node->_left && !(node->_right)) {
            node = node->_left;
        } else if (!(node->_left) && node->_right) {
            node = node->_right;
        } else {
            int _min = min(node->_right);
            node->_data = _min;
            node->_right = remove(node->_right, _min);
        }
        return node;
    }
    return nullptr;
}

void BSTree::remove(int data) {
    root = remove(root, data);
}

void BSTree::bfs(Node* node) const {
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

void BSTree::bfs() const {
    bfs(root);
}

void BSTree::dfs(Node* node) const {
    if (node) {
        cout << node->_data << " ";
        dfs(node->_left);
        dfs(node->_right);
    }
}

void BSTree::dfs() const {
    dfs(root);
}

void BSTree::sortedPrinting(Node* node) const {
    if (node) {
        sortedPrinting(node->_left);
        cout << node->_data << " ";
        sortedPrinting(node->_right);
    }
}

void BSTree::sortedPrinting() const {
    sortedPrinting(root);
}

int BSTree::min(Node* node) const {
    Node* temporary_node = node;
    while (temporary_node->_left) {
        temporary_node = temporary_node->_left;
    }
    return temporary_node->_data;
}

int BSTree::min() const {
    if (isEmpty()) {
        throw invalid_argument("Tree is empty!(min)");
    }
    return min(root);
}

int BSTree::max(Node* node) const {
    Node* temporary_node = node;
    while (temporary_node->_right) {
        temporary_node = temporary_node->_right;
    }
    return temporary_node->_data;
}

int BSTree::max() const {
    if (isEmpty()) {
        throw invalid_argument("Tree is empty!(max)");
    }
    return max(root);
}

int BSTree::sum(Node* node) const {
    if (node) {
        return node->_data + sum(node->_left) + sum(node->_right);
    }
    return 0;
}

int BSTree::sum() const {
    if (isEmpty()) {
        throw invalid_argument("Tree is empty!(sum)");
    }
    return sum(root);
}

bool BSTree::isEmpty() const {
    return root == nullptr;
}

#endif // __BSTREE_H__