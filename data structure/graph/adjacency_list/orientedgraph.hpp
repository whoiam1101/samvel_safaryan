#ifndef __ADJACENCY_LIST_ORIENTED_GRAPH_H__
#define __ADJACENCY_LIST_ORIENTED_GRAPH_H__

#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::queue;
using std::cin;
using std::cout;
using std::endl;

class OrientedGraph {
private:
    vector<vector<int>> _adjacency_list;
    int _number_of_edges;

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

    void printAdjacencyList() const;
};

// constructors
OrientedGraph::OrientedGraph() {
    _number_of_edges = 0;
}

OrientedGraph::OrientedGraph(int number_of_vertices) {
    _adjacency_list = vector<vector<int>>(number_of_vertices);
    _number_of_edges = 0;
}

OrientedGraph::OrientedGraph(const OrientedGraph& graph) {
    _adjacency_list = graph._adjacency_list;
    _number_of_edges = graph._number_of_edges;
}

// methods
int OrientedGraph::numberOfVertices() const {
    return _adjacency_list.size();
}

int OrientedGraph::numberOfEdges() const {
    return _number_of_edges;
}

int OrientedGraph::numberOfIncomingEdges(int u) const {
    int degree = 0;
    for (int i = 0; i < numberOfVertices(); i++) {
        for (int j = 0; j < (int) _adjacency_list[i].size(); j++) {
            if (_adjacency_list[i][j] == u) {
                degree++;
                break;
            }
        }
    }
    return degree;
}

int OrientedGraph::numberOfOutgoingEdges(int u) const {
    return _adjacency_list[u].size();
}

int OrientedGraph::getDegree(int u) const {
    return numberOfIncomingEdges(u) + numberOfOutgoingEdges(u) - (isThereAnOrientedEdge(u, u) ? 1 : 0);
}

bool OrientedGraph::isThereAnOrientedEdge(int u, int v) const {
    for (int i = 0; i < numberOfOutgoingEdges(u); i++) {
        if (_adjacency_list[u][i] == v) {
            return true;
        }
    }
    return false;
}

bool OrientedGraph::isThereAnEdge(int u, int v) const {
    return isThereAnOrientedEdge(u, v) || isThereAnOrientedEdge(v, u);
}

bool OrientedGraph::isConnected(int u, int v) const {
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
                if (!is_visited[i] && isThereAnOrientedEdge(current_vertex, i)) {
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
            if (!is_visited[i] && isThereAnOrientedEdge(current_vertex, i)) {
                is_visited[i] = true;
                queue_vertices.push(i);
            }
        }
    }
    vector<int> answer;
    for (int i = 0; i < numberOfVertices(); i++) {
        if (is_visited[i]) {
            answer.push_back(i);
        }
    }
    return answer;
}

int OrientedGraph::distance(int u, int v) const {
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
                if (!is_visited[i] && isThereAnOrientedEdge(current_vertex, i)) {
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
    _adjacency_list.push_back(vector<int>());
}

void OrientedGraph::removeVertex(int u) {
    _number_of_edges -= getDegree(u);
    _adjacency_list.erase(_adjacency_list.begin() + u);
    for (int i = 0; i < numberOfVertices(); i++) {
        for (int j = 0; j < (int) _adjacency_list[i].size(); j++) {
            if (_adjacency_list[i][j] == u) {
                _adjacency_list[i].erase(_adjacency_list[i].begin() + j);
                break;
            }
        }
        for (int j = 0; j < (int) _adjacency_list[i].size(); j++) {
            if (_adjacency_list[i][j] > u) {
                _adjacency_list[i][j]--;
            }
        }
    }
}

void OrientedGraph::addOrientedEdge(int u, int v) {
    if (!isThereAnOrientedEdge(u, v)) {
        _number_of_edges++;
        _adjacency_list[u].push_back(v);
    }
}

void OrientedGraph::addEdge(int u, int v) {
    addOrientedEdge(u, v);
    addOrientedEdge(v, u);
}

void OrientedGraph::removeOrientedEdge(int u, int v) {
    if (isThereAnOrientedEdge(u, v)) {
        _number_of_edges--;
        for (int i = 0; i < (int) _adjacency_list[u].size(); i++) {
            if (_adjacency_list[u][i] == v) {
                _adjacency_list[u].erase(_adjacency_list[u].begin() + i);
                break;
            }
        }
    }
}

void OrientedGraph::removeEdge(int u, int v) {
    removeOrientedEdge(u, v);
    removeOrientedEdge(v, u);
}

void OrientedGraph::printAdjacencyList() const {
    cout << "|V| = " << numberOfVertices() << endl;
    cout << "|E| = " << numberOfEdges() << endl;
    cout << " ";
    for (int i = 0; i < numberOfVertices(); i++) {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < numberOfVertices(); i++) {
        cout << i << " ---> ";
        for (int j = 0; j < (int) _adjacency_list[i].size(); j++) {
            cout << " " << _adjacency_list[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

#endif // __ADJACENCY_LIST_ORIENTED_GRAPH_H__