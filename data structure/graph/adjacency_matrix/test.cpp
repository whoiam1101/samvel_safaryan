#include <ctime>
#include <random>

#include "orientedgraph.hpp"

using std::mt19937;

mt19937 gen(time(nullptr));
int _genInteger(int a = 0, int b = 13) {
    return gen() % (b - a + 1) + a;
}

int main() {
    OrientedGraph graph(4);
    for (int i = 0; i < 13; i++) {
        graph.addOrientedEdge(_genInteger(0, graph.numberOfVertices() - 1),
                              _genInteger(0, graph.numberOfVertices() - 1), _genInteger(1, 12));
    }
    graph.printAdjacencyMatrix();
    int* distances = graph.minimalDistanceFromToAll(0);
    for (int i = 0; i < graph.numberOfVertices(); i++) {
        cout << "distance from " << 0 << " to " << i << " equal to " << distances[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < graph.numberOfVertices(); i++) {
        cout << i << " --->";
        vector<int> temporary_array = graph.verticesWithWhichItIsConnected(i);
        for (int i = 0; i < (int) temporary_array.size(); i++) {
            cout << " " << temporary_array[i];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < graph.numberOfVertices(); i++) {
        int u = _genInteger(0, (int) graph.numberOfVertices() - 1);
        int v = _genInteger(0, (int) graph.numberOfVertices() - 1);
        cout << "Is connected " << u << " and " << v << " = " << graph.isConnected(u, v) << endl;
    }
    cout << endl;
    for (int i = 0; i < graph.numberOfVertices(); i++) {
        for (int j = 0; j < graph.numberOfVertices(); j++) {
            cout << "Distance from " << i << " to " << j << " = " << graph.distance(i, j) << endl;
        }
    }
    cout << endl;
    for (int i = 0; i < 2; i++) {
        graph.removeVertex(_genInteger(0, graph.numberOfVertices() - 1));
        graph.printAdjacencyMatrix();
    }
    return 0;
}