#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* _left;
    Node* _right;
    int _data;

    Node() : _left(nullptr), _right(nullptr) {}
    Node(int data) : _left(nullptr), _right(nullptr), _data(data) {}
};

void insert(Node* root, int data) {
    queue<Node*> _queue;
    _queue.push(root);
    while (!_queue.empty()) {
        Node* current_node = _queue.front();
        _queue.pop();
        if (current_node->_left) {
            _queue.push(current_node->_left);
        } else {
            current_node->_left = new Node(data);
            return;
        }
        if (current_node->_right) {
            _queue.push(current_node->_right);
        } else {
            current_node->_right = new Node(data);
            return;
        }
    }
}

void dfs(Node* root, vector<vector<string>> &tree, int height) {
    if ((int) tree.size() <= height) {
        tree.push_back(vector<string>());
    }
    if (root) {
        tree[height].push_back(to_string(root->_data));
        dfs(root->_left, tree, height + 1);
        dfs(root->_right, tree, height + 1);
    } else {
        tree[height].push_back("-");
    }
}

void printSpace(int n) {
    while (n--) {
        cout << " ";
    }
}

mt19937 gen(time(nullptr));
int _genInteger(int a = -20, int b = 20) {
    return gen() % (b - a + 1) + a;
}

int main() {
    Node* root = new Node(_genInteger());
    for (int i = 0; i < 16; i++) {
        insert(root, _genInteger(0, 9));
    }
    vector<vector<string>> tree;
    dfs(root, tree, 0);
    int height = (int) tree.size();
    for (int i = 0; i < height; i++) {
        printSpace((1 << (height - i)) - 1);
        for (int j = 0; j < (int) tree[i].size(); j++) {
            cout << tree[i][j];
            printSpace((1 << (height - i + 1)) - 1);
        }
        cout << endl;
    }
    return 0;
}
