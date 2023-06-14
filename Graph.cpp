#include "Graph.h"

Graph::Graph(int V) : V(V) {}

void Graph::addEdge(int source, int destination, int weight) {
    Edge edge = {source, destination, weight};
    edges.push_back(edge);
}

int Graph::getVertexCount() const {
    return V;
}

int Graph::getEdgeCount() const {
    return edges.size();
}

const std::vector<Edge>& Graph::getEdges() const {
    return edges;
}