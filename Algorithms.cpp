#include <queue>
#include <climits>
#include <chrono>
#include "Algorithms.h"

std::vector<int> dijkstra(const Graph& graph, int source) {
    int V = graph.getVertexCount();
    std::vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph.getEdges()) {
            int v = edge.destination;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

std::vector<std::vector<int>> floydWarshall(const Graph& graph) {
    int V = graph.getVertexCount();
    std::vector<std::vector<int>> dist(V, std::vector<int>(V, INT_MAX));

    for (int i = 0; i < V; i++)
        dist[i][i] = 0;

    for (const auto& edge : graph.getEdges())
        dist[edge.source][edge.destination] = edge.weight;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

std::vector<int> bellmanFord(const Graph& graph, int source) {
    int V = graph.getVertexCount();
    std::vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i < V; i++) {
        for (const auto& edge : graph.getEdges()) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}

void generateCompleteGraph(Graph& graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            int weight = rand() % 100 + 1;
            graph.addEdge(i, j, weight);
            graph.addEdge(j, i, weight);
        }
    }
}

void generateConnectedGraph(Graph& graph, int numVertices) {
    int numEdges = (numVertices * (numVertices - 1)) / 2;
    int targetEdges = static_cast<int>(0.4 * numEdges) + rand() % (static_cast<int>(0.5 * numEdges) - static_cast<int>(0.4 * numEdges) + 1);

    while (graph.getEdgeCount() < targetEdges) {
        int source = rand() % numVertices;
        int destination = rand() % numVertices;
        if (source != destination) {
            int weight = rand() % 100 + 1;
            graph.addEdge(source, destination, weight);
            graph.addEdge(destination, source, weight);
        }
    }
}

void generateSparseGraph(Graph& graph, int numVertices) {
    for (int i = 1; i < numVertices; i++) {
        int weight = rand() % 100 + 1;
        int parent = rand() % i;
        graph.addEdge(parent, i, weight);
        graph.addEdge(i, parent, weight);
    }
}

long long measureDijkstra(const Graph& graph, int source) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> dist = dijkstra(graph, source);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}

long long measureFloydWarshall(const Graph& graph) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> dist = floydWarshall(graph);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}

long long measureBellmanFord(const Graph& graph, int source) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> dist = bellmanFord(graph, source);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}
