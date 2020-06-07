#include <cxxabi.h>

#include <graphs/graphs.hpp>


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

    RandomGenerator<GraphBackend> gen;
    auto graph = gen.generate(VerticesNumber, SaturationPercents);

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

    RandomGenerator<GraphBackend> gen;
    auto graph = gen.generate(VerticesNumber, SaturationPercents);

    graph.dedicatedPrint(std::cout);
    std::cout << '\n';

    DeepFirstSearch dfs;
    BreadthFirstSearch bfs;
    std::cout << "Przeszukiwanie BFS: " << bfs.search(graph) << '\n';
    std::cout << "Przeszukiwanie DFS: " << dfs.search(graph) << '\n';
    std::cout << '\n';
}


void printCyclesWithAsk(CycleFind& finder) {
    while (true) {
        auto cycle = finder.find();
        if (cycle.size() == 0) {
            break;
        }

        std::cout << cycle;

        std::cout << "\tKontynuować (t/n)? ";
        char reply = std::cin.get();

        if (reply == 'n') {
            break;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename GraphGenerator, int VerticesNumber, int SaturationPercents>
void cyclesFindExample() {
    GraphGenerator gen;
    auto graph = gen.generate(VerticesNumber, SaturationPercents);
    std::cout << graph;

    EulerCycleFind euler(graph);
    HamiltonCycleFind hamilton(graph);

    std::cout << "Cykle Hamiltona:" << std::endl;
    printCyclesWithAsk(hamilton);
    std::cout << std::endl;

    std::cout << "Obwody Eulera:" << std::endl;
    printCyclesWithAsk(euler);
    std::cout << std::endl;
}


int main(void) {
    void (*callbacks[])() = {
        directedGraphExample<DirectedAdjacencyMatrixGraph, 10, 50>,
        undirectedGraphExample<UndirectedAdjacencyMatrixGraph, 10, 50>,

        directedGraphExample<DirectedIncidenceMatrixGraph, 10, 50>,
        undirectedGraphExample<UndirectedIncidenceMatrixGraph, 10, 50>,

        directedGraphExample<DirectedAdjacencyListGraph, 10, 50>,
        undirectedGraphExample<UndirectedAdjacencyListGraph, 10, 50>,

        cyclesFindExample<BothEulerAndHamiltonGenerator<UndirectedIncidenceMatrixGraph>, 10, 30>,
        cyclesFindExample<NeitherEulerNorHamiltonGenerator<UndirectedIncidenceMatrixGraph>, 10, 70>,
    };

    printSeparator();
    for (const auto& callback : callbacks) {
        callback();
        printSeparator();
    }
}