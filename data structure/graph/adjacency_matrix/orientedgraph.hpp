#ifndef __ADJACENCY_MATRIX_ORIENTED_GRAPH_H__
#define __ADJACENCY_MATRIX_ORIENTED_GRAPH_H__

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using std::queue;
using std::vector;
using std::invalid_argument;
using std::cin;
using std::cout;
using std::endl;

class OrientedGraph {
private:
    vector<vector<bool>> _adjacency_matrix;
    int _number_of_edges;

    void outOfBoundException(int) const;

    void dfs(bool*, int) const;

public:
    // constructors
    OrientedGraph();
    OrientedGraph(int);
    OrientedGraph(const OrientedGraph&);

    // methods
    int numberOfVertices() const;
    int numberOfEdges() const;

    int numberOfIncomingEdges(int) const;
    int numberOfOutgoingEdges(int) const;
    int getDegree(int) const;

    bool isThereAnOrientedEdge(int, int) const;
    bool isThereAnEdge(int, int) const;
    bool isConnected(int, int) const;

    vector<int> verticesWithWhichItIsConnected(int) const;
    int distance(int, int) const;

    void addVertex();
    void removeVertex(int);

    void addOrientedEdge(int, int);
    void addEdge(int, int);
    void removeOrientedEdge(int, int);
    void removeEdge(int, int);

    void readAdjacencyMatrix();
    void printAdjacencyMatrix() const;
};

void OrientedGraph::outOfBoundException(int u) const {
    if (u < 0 || numberOfVertices() <= u) {
        throw invalid_argument("Out of bound exception!");
    }
}

OrientedGraph::OrientedGraph() {
    _number_of_edges = 0;
}

OrientedGraph::OrientedGraph(int number_of_vertices) {
    _adjacency_matrix = vector<vector<bool>>(number_of_vertices, vector<bool>(number_of_vertices, false));
    _number_of_edges = 0;
}

OrientedGraph::OrientedGraph(const OrientedGraph& oriented_graph) {
    _adjacency_matrix = oriented_graph._adjacency_matrix;
    _number_of_edges = oriented_graph._number_of_edges;
}

int OrientedGraph::numberOfVertices() const {
    return (int) _adjacency_matrix.size();
}

int OrientedGraph::numberOfEdges() const {
    return _number_of_edges;
}

int OrientedGraph::numberOfIncomingEdges(int u) const {
    outOfBoundException(u);
    int number_of_incoming_edges = 0;
    for (int i = 0; i < numberOfVertices(); i++) {
        if (_adjacency_matrix[i][u]) {
            number_of_incoming_edges++;
        }
    }
    return number_of_incoming_edges;
}

int OrientedGraph::numberOfOutgoingEdges(int u) const {
    outOfBoundException(u);
    int number_of_outgoing_edges = 0;
    for (int i = 0; i < (int) numberOfVertices(); i++) {
        if (_adjacency_matrix[u][i]) {
            number_of_outgoing_edges++;
        }
    }
    return number_of_outgoing_edges;
}

int OrientedGraph::getDegree(int u) const {
    return numberOfIncomingEdges(u) + numberOfOutgoingEdges(u) - (_adjacency_matrix[u][u] ? 1 : 0);
}

bool OrientedGraph::isThereAnOrientedEdge(int u, int v) const {
    outOfBoundException(u);
    outOfBoundException(v);
    return _adjacency_matrix[u][v];
}

bool OrientedGraph::isThereAnEdge(int u, int v) const {
    return isThereAnOrientedEdge(u, v) || isThereAnOrientedEdge(v, u);
}

void OrientedGraph::dfs(bool* is_visited, int u) const {
    is_visited[u] = true;
    for (int i = 0; i < numberOfVertices(); i++) {
        if (!is_visited[i] && _adjacency_matrix[u][i]) {
            dfs(is_visited, i);
        }
    }
}

bool OrientedGraph::isConnected(int u, int v) const {
    outOfBoundException(u);
    outOfBoundException(v);
    if (u != v) {
        bool* is_visited = new bool[numberOfVertices()];
        for (int i = 0; i < numberOfVertices(); i++) {
            is_visited[i] = false;
        }
        queue<int> queue_vertices;
        queue_vertices.push(u);
        is_visited[u] = true;
        while (!queue_vertices.empty()) {
            int current_vertex = queue_vertices.front();
            queue_vertices.pop();
            for (int i = 0; i < numberOfVertices(); i++) {
                if (!is_visited[i] && _adjacency_matrix[current_vertex][i]) {
                    if (i == v) {
                        return true;
                    } else {
                        is_visited[i] = true;
                        queue_vertices.push(i);
                    }
                }
            }
        }
        return false;
    }
    return true;
}

vector<int> OrientedGraph::verticesWithWhichItIsConnected(int u) const {
    outOfBoundException(u);
    bool* is_visited = new bool[numberOfVertices()];
    for (int i = 0; i < numberOfVertices(); i++) {
        is_visited[i] = false;
    }
    dfs(is_visited, u);
    vector<int> answer;
    for (int i = 0; i < numberOfVertices(); i++) {
        if (is_visited[i]) {
            answer.push_back(i);
        }
    }
    return answer;
}

int OrientedGraph::distance(int u, int v) const {
    outOfBoundException(u);
    outOfBoundException(v);
    if (u != v) {
        bool* is_visited = new bool[numberOfVertices()];
        int* distance_to_vertex = new int[numberOfVertices()];
        for (int i = 0; i < numberOfVertices(); i++) {
            is_visited[i] = false;
            distance_to_vertex[i] = 0;
        }
        queue<int> queue_vertices;
        queue_vertices.push(u);
        is_visited[u] = true;
        while (!queue_vertices.empty()) {
            int current_vertex = queue_vertices.front();
            queue_vertices.pop();
            for (int i = 0; i < numberOfVertices(); i++) {
                if (!is_visited[i] && _adjacency_matrix[current_vertex][i]) {
                    distance_to_vertex[i] = distance_to_vertex[current_vertex] + 1;
                    is_visited[i] = true;
                    queue_vertices.push(i);
                }
            }
        }
        if (distance_to_vertex[v] != 0) {
            return distance_to_vertex[v];
        }
        return -1;
    }
    return 0;
}

void OrientedGraph::addVertex() {
    _adjacency_matrix.push_back(vector<bool>(numberOfVertices()));
    for (int i = 0; i < numberOfVertices(); i++) {
        _adjacency_matrix[i].push_back(0);
    }
}

void OrientedGraph::removeVertex(int u) {
    outOfBoundException(u);
    _number_of_edges -= getDegree(u);
    _adjacency_matrix.erase(_adjacency_matrix.begin() + u);
    for (int i = 0; i < numberOfVertices(); i++) {
        _adjacency_matrix[i].erase(_adjacency_matrix[i].begin() + u);
    }
}

void OrientedGraph::addOrientedEdge(int u, int v) {
    outOfBoundException(u);
    outOfBoundException(v);
    if (!_adjacency_matrix[u][v]) {
        _number_of_edges++;
        _adjacency_matrix[u][v] = true;
    }
}

void OrientedGraph::addEdge(int u, int v) {
    addOrientedEdge(u, v);
    addOrientedEdge(v, u);
}

void OrientedGraph::removeOrientedEdge(int u, int v) {
    outOfBoundException(u);
    outOfBoundException(v);
    if (_adjacency_matrix[u][v]) {
        _number_of_edges--;
        _adjacency_matrix[u][v] = false;
    }
}

void OrientedGraph::removeEdge(int u, int v) {
    removeOrientedEdge(u, v);
    removeOrientedEdge(v, u);
}

void OrientedGraph::readAdjacencyMatrix() {
    cout << " ";
    for (int i = 0; i < numberOfVertices(); i++) {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < numberOfVertices(); i++) {
        cout << i << " ";
        for (int j = 0; j < numberOfVertices(); j++) {
            bool temporary;
            cin >> temporary;
            _adjacency_matrix[i][j] = temporary;
            _number_of_edges += (int) temporary;
        }
    }
}

void OrientedGraph::printAdjacencyMatrix() const {
    cout << "|V| = " << numberOfVertices() << endl;
    cout << "|E| = " << numberOfEdges() << endl;
    cout << " ";
    for (int i = 0; i < numberOfVertices(); i++) {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < numberOfVertices(); i++) {
        cout << i;
        for (int j = 0; j < numberOfVertices(); j++) {
            cout << " " << _adjacency_matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

#endif // __ADJACENCY_MATRIX_ORIENTED_GRAPH_H__