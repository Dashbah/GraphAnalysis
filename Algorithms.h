#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "Graph.h"

std::vector<int> dijkstra(const Graph& graph, int source);

std::vector<std::vector<int>> floydWarshall(const Graph& graph);

std::vector<int> bellmanFord(const Graph& graph, int source);

void generateCompleteGraph(Graph& graph, int numVertices);

void generateConnectedGraph(Graph& graph, int numVertices);

void generateSparseGraph(Graph& graph, int numVertices);

long long measureDijkstra(const Graph& graph, int source);

long long measureFloydWarshall(const Graph& graph);

long long measureBellmanFord(const Graph& graph, int source);

#endif  // ALGORITHMS_H
