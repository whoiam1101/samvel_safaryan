#include <iostream>
#include <set>

using namespace std;

int root(bool**, int);
int dfs(bool**, int, bool*, int);
bool isBinaryTree(bool**, int);

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
    if (number_of_vertices == 0 || isBinaryTree(graph, number_of_vertices)) {
        cout << " This graph is a binary tree\n";
    } else {
        cout << " This graph isn't a binary tree\n";
    }
    return 0;
}

int root(bool** graph, int number_of_vertices) {
    int _root = 0;
    if (graph[0][0]) {
        return -1;
    }
    set<int> vertices;
    set<int> visited_vertices;
    visited_vertices.insert(0);
    for (int i = 0; i < number_of_vertices; i++) {
        vertices.insert(i);
    }
    while (!vertices.empty()) {
        for (set<int>::iterator _iterator = vertices.begin(); _iterator != vertices.end(); _iterator++) {
            if (graph[*_iterator][_root]) {
                if (visited_vertices.count(*_iterator)) {
                    return -1;
                }
                _root = *_iterator;
                visited_vertices.insert(*_iterator);
                vertices.erase(_iterator);
                break;
            }
        }
        int number_out_edges = 0;
        bool is_probably_root = true;
        for (int i = 0; i < number_of_vertices; i++) {
            if (graph[i][_root]) {
                is_probably_root = false;
                break;
            }
            if (graph[_root][i]) {
                number_out_edges++;
            }
        }
        if (is_probably_root && number_out_edges <= 2) {
            return _root;
        }
    }
    return -1;
}

int dfs(bool** graph, int number_of_vertices, bool* is_visited, int vertex) {
    int number_of_vertices_visited = 1;
    is_visited[vertex] = true;
    for (int i = 0; i < number_of_vertices; i++) {
        if (!is_visited[i] && graph[vertex][i]) {
            number_of_vertices_visited += dfs(graph, number_of_vertices, is_visited, i);
        }
    }
    return number_of_vertices_visited;
}

bool isBinaryTree(bool** graph, int number_of_vertices) {
    bool* is_visited = new bool[number_of_vertices];
    for (int i = 0; i < number_of_vertices; i++) {
        is_visited[i] = false;
    }
    int _root = root(graph, number_of_vertices);
    if (_root != -1 && dfs(graph, number_of_vertices, is_visited, _root) == number_of_vertices) {
        int number_of_edges = 0;
        for (int i = 0; i < number_of_vertices; i++) {
            for (int j = 0; j < number_of_vertices; j++) {
                if (graph[i][j]) {
                    number_of_edges++;
                }
            }
        }
        return number_of_edges == number_of_vertices - 1;
    }
    return false;
}
