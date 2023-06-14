#include <iostream>
#include "Graph.h"
#include "Algorithms.h"
#include "CSVWriter.h"

int main() {
    CSVWriter csvWriter("results.csv"); // Создание объекта для записи в CSV

    // Заголовки столбцов в файле CSV
    csvWriter.writeRow({"Number of Vertices", "Number of Edges", "Dijkstra", "Floyd-Warshall", "Bellman-Ford"});

    for (int numVertices = 10; numVertices <= 1010; numVertices += 50) {
        Graph graph(numVertices);

        // Генерация графов разных типов
        // а. Полные графы
        std::cout << numVertices << '\n';
        std::cout << "generateCompleteGraph\n";
        generateCompleteGraph(graph, numVertices);

        // б. Связные графы с коэффициентом плотности 0.4-0.5
        generateConnectedGraph(graph, numVertices);

        // в. Разреженные графы (деревья)
        generateSparseGraph(graph, numVertices);

        int source = 0;
        int destination = numVertices - 1;

        // Замер времени выполнения для каждого алгоритма
        long long durationDijkstra = measureDijkstra(graph, source);
        long long durationFloydWarshall = measureFloydWarshall(graph);
        long long durationBellmanFord = measureBellmanFord(graph, source);

        // Запись результатов в файл CSV
        csvWriter.writeRow({std::to_string(numVertices), std::to_string(graph.getEdgeCount()),
                            std::to_string(durationDijkstra), std::to_string(durationFloydWarshall),
                            std::to_string(durationBellmanFord)});
    }

    return 0;
}
