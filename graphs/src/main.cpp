#include <graphs/graphs.hpp>

void printSeparator() {
    const int WIDTH = 80;
    std::cout << "\n" << std::string(WIDTH, '-') << "\n\n";
}


const int VERTICES = 10;

template <typename GraphBackend, int VerticesNumber, int SaturationPercents>
void directedGraphExample() {
    std::cout << "Graf skierowany (" << VerticesNumber << ", " << SaturationPercents << "%) klasy "  << '\n';

    DirectedGraphGenerator gen;
    auto graph = gen.generateRandomly<GraphBackend>(VerticesNumber, SaturationPercents);

    graph.dedicatedPrint(std::cout);
    std::cout << '\n';

    DeepFirstSearch dfs;
    BreadthFirstSearch bfs;
    std::cout << "Przeszukiwanie BFS: " << bfs.search(graph) << '\n';
    std::cout << "Przeszukiwanie DFS: " << dfs.search(graph) << '\n';
    std::cout << '\n';

    DeepFirstSort dfsort;
    BreadthFirstSort bfsort;
    std::cout << "Sortowanie BFS: " << bfsort.sort(graph) << '\n';
    std::cout << "Sortowanie DFS: " << dfsort.sort(graph) << '\n';
    std::cout << '\n';
}

template <typename GraphBackend, int VerticesNumber, int SaturationPercents>
void undirectedGraphExample() {
    std::cout << "Graf skierowany (" << VerticesNumber << ", " << SaturationPercents << "%) klasy "  << '\n';

    UndirectedGraphGenerator gen;
    auto graph = gen.generateRandomly<GraphBackend>(VerticesNumber, SaturationPercents);

    graph.dedicatedPrint(std::cout);
    std::cout << '\n';

    DeepFirstSearch dfs;
    BreadthFirstSearch bfs;
    std::cout << "Przeszukiwanie BFS: " << bfs.search(graph) << '\n';
    std::cout << "Przeszukiwanie DFS: " << dfs.search(graph) << '\n';
    std::cout << '\n';
}

int main(void) {
    void (*callbacks[])() = {
        directedGraphExample<DirectedAdjacencyMatrixGraph, 10, 50>
    };

    printSeparator();
    for (const auto& callback : callbacks) {
        callback();
        printSeparator();
    }
}