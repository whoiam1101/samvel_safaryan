#include <iostream>

#define endl "\n"

using std::cin;
using std::cout;

int root(bool**, int);
int dfs(bool**, int, bool*, int);
bool isConnectivity(bool**, int);

bool isTree(bool**, int);
bool isBinaryTree(bool**, int);
bool isBinarySearchTree(bool**, int);

int main() {
    int number_of_vertices;
    cout << " |V| = ";
    cin >> number_of_vertices;
    bool** graph = new bool*[number_of_vertices];
    cout << "Adjacency matrix\n";
    cout << " ";
    for (int i = 0; i < number_of_vertices; i++) {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < number_of_vertices; i++) {
        graph[i] = new bool[number_of_vertices];
        cout << i << " ";
        for (int j = 0; j < number_of_vertices; j++) {
            cin >> graph[i][j];
        }
    }
    if (isTree(graph, number_of_vertices)) {
        cout << " Graph is a tree!\n";
        cout << " The root is " << root(graph, number_of_vertices) << endl;
        if (isBinaryTree(graph, number_of_vertices)) {
            cout << "   Graph is a binary tree!\n";
            if (isBinarySearchTree(graph, number_of_vertices)) {
                cout << "     Graph is a binary search tree!\n";
            } else {
                cout << "     Graph isn't a binary search tree!\n";
            }
        } else {
            cout << "   Graph isn't a binary tree\n";
        }
    } else {
        cout << " Graph isn't a tree!\n";
    }
    return 0;
}

int dfs(bool** graph, int number_of_vertices, bool* is_visited, int vertex) {
    int number_of_vertices_visited = 1;
    is_visited[vertex] = true;
    for (int i = 0; i < number_of_vertices; i++) {
        if (graph[vertex][i] && !is_visited[i]) {
            number_of_vertices_visited += dfs(graph, number_of_vertices, is_visited, i);
        }
    }
    return number_of_vertices_visited;
}

int root(bool** graph, int number_of_vertices) {
    for (int i = 0; i < number_of_vertices; i++) {
        bool* is_visited = new bool[number_of_vertices];
        for (int j = 0; j < number_of_vertices; j++) {
            is_visited[j] = false;
        }
        if (dfs(graph, number_of_vertices, is_visited, i) == number_of_vertices) {
            return i;
        }
    }
    return -1;
}

bool isConnectivity(bool** graph, int number_of_vertices) {
    for (int i = 0; i < number_of_vertices; i++) {
        bool* is_visited = new bool[number_of_vertices];
        for (int j = 0; j < number_of_vertices; j++) {
            is_visited[j] = false;
        }
        if (dfs(graph, number_of_vertices, is_visited, i) == number_of_vertices) {
            return true;
        }
    }
    return false;
}

bool isTree(bool** graph, int number_of_vertices) {
    int number_of_edges = 0;
    for (int i = 0; i < number_of_vertices; i++) {
        for (int j = 0; j < number_of_vertices; j++) {
            if (graph[i][j]) {
                number_of_edges++;
            }
        }
    }
    return isConnectivity(graph, number_of_vertices) && (number_of_edges == number_of_vertices - 1);
}

bool isBinaryTree(bool** graph, int number_of_vertices) {
    for (int i = 0; i < number_of_vertices; i++) {
        int degree = 0;
        for (int j = i + 1; j < number_of_vertices; j++) {
            if (graph[i][j]) {
                degree++;
            }
        }
        if (degree > 2) {
            return false;
        }
    }
    return isTree(graph, number_of_vertices);
}

bool isBinarySearchTree(bool** graph, int number_of_vertices) {
    if (isBinaryTree(graph, number_of_vertices)) {
        for (int i = 0; i < number_of_vertices; i++) {
            int less_than = 0;
            int greater_than = 0;
            for (int j = i + 1; j < number_of_vertices; j++) {
                if (graph[i][j]) {
                    if (i > j) {
                        less_than++;
                    } else {
                        greater_than++;
                    }
                }
            }
            if (less_than > 1 || greater_than > 1) {
                return false;
            }
        }
        return true;
    }
    return false;
}

