#include <graphs/graphs.hpp>
#include <cxxabi.h>

template <typename T>
void printType() {
    char *name = abi::__cxa_demangle(typeid(T).name(), 0, 0, NULL);
    std::cout << name;
    delete name;
}

void printSeparator() {
    const int WIDTH = 80;
    std::cout << "\n" << std::string(WIDTH, '-') << "\n\n";
}


template <typename GraphBackend, int VerticesNumber, int SaturationPercents>
void printExampleHeader() {
    std::cout << "Graf (" << VerticesNumber << ", " << SaturationPercents << "%) klasy ";
    printType<GraphBackend>();
    std::cout << '\n';
}

template <typename GraphBackend, int VerticesNumber, int SaturationPercents>
void directedGraphExample() {
    printExampleHeader<GraphBackend, VerticesNumber, SaturationPercents>();

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
    printExampleHeader<GraphBackend, VerticesNumber, SaturationPercents>();

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
        directedGraphExample<DirectedAdjacencyMatrixGraph, 10, 50>,
        undirectedGraphExample<UndirectedAdjacencyMatrixGraph, 10, 50>,

        directedGraphExample<DirectedIncidenceMatrixGraph, 10, 50>,
        undirectedGraphExample<UndirectedIncidenceMatrixGraph, 10, 50>,

        directedGraphExample<DirectedAdjacencyListGraph, 10, 50>,
        undirectedGraphExample<UndirectedAdjacencyListGraph, 10, 50>
    };

    printSeparator();
    for (const auto& callback : callbacks) {
        callback();
        printSeparator();
    }
}