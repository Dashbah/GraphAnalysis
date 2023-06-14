#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

// Структура для представления ребра графа
struct Edge {
    int source, destination, weight;
};

// Класс для представления графа
class Graph {
    int V; // Число вершин
    std::vector<Edge> edges; // Вектор ребер

public:
    Graph(int V);

    void addEdge(int source, int destination, int weight);

    int getVertexCount() const;

    int getEdgeCount() const;

    const std::vector<Edge>& getEdges() const;
};

#endif  // GRAPH_H