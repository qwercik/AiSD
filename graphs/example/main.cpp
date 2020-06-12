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

template <typename GraphGenerator, int VerticesNumber, int SaturationPercents>
void directedGraphExample() {
    printExampleHeader<GraphGenerator, VerticesNumber, SaturationPercents>();

    GraphGenerator gen;
    auto graph = gen.generate(VerticesNumber, SaturationPercents);

    std::cout << "Postać wewnętrzna:\n";
    graph.dedicatedPrint(std::cout);
    std::cout << '\n';

    std::cout << "Postać abstrakcyjna:\n";
    std::cout << graph << '\n';

    DeepFirstSearch dfs;
    BreadthFirstSearch bfs;
    std::cout << "Przeszukiwanie BFS: " << bfs.search(graph) << '\n';
    std::cout << "Przeszukiwanie DFS: " << dfs.search(graph) << '\n';
    std::cout << '\n';

    BreadthFirstSort bfsort;
    std::list<int> bfsList;
    if (bfsort.sort(graph, bfsList)) {
        std::cout << "Sortowanie BFS: " << bfsList << '\n';
    } else {
        std::cout << "Nie udało się posortować BFS\n";
    }

    DeepFirstSort dfsort;
    std::list<int> dfsList;
    if (dfsort.sort(graph, dfsList)) {
        std::cout << "Sortowanie DFS: " << dfsList << '\n';
    } else {
        std::cout << "Nie udało się posortować DFS\n";
    }

    
    std::cout << '\n';
}

template <typename GraphGenerator, int VerticesNumber, int SaturationPercents>
void undirectedGraphExample() {
    printExampleHeader<GraphGenerator, VerticesNumber, SaturationPercents>();

    GraphGenerator gen;
    auto graph = gen.generate(VerticesNumber, SaturationPercents);

    std::cout << "Postać wewnętrzna:\n";
    graph.dedicatedPrint(std::cout);
    std::cout << '\n';

    std::cout << "Postać abstrakcyjna:\n";
    std::cout << graph << '\n';

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

        std::cout << "\tKontynuować? ";
        std::string reply;
        std::getline(std::cin, reply);

        if (reply == "n") {
            break;
        }
    }
}

template <typename GraphGenerator, int VerticesNumber, int SaturationPercents>
void cyclesFindExample() {
    printExampleHeader<GraphGenerator, VerticesNumber, SaturationPercents>();

    GraphGenerator gen;
    auto graph = gen.generate(VerticesNumber, SaturationPercents);
    std::cout << graph << '\n';

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
    srand(time(nullptr));

    void (*callbacks[])() = {
        directedGraphExample<IterativeGenerator<DirectedAdjacencyMatrixGraph>, 10, 50>,
        undirectedGraphExample<IterativeGenerator<UndirectedAdjacencyMatrixGraph>, 10, 50>,

        directedGraphExample<IterativeGenerator<DirectedIncidenceMatrixGraph>, 10, 50>,
        undirectedGraphExample<IterativeGenerator<UndirectedIncidenceMatrixGraph>, 10, 50>,

        directedGraphExample<IterativeGenerator<DirectedAdjacencyListGraph>, 10, 50>,
        undirectedGraphExample<IterativeGenerator<UndirectedAdjacencyListGraph>, 10, 50>,

        cyclesFindExample<BothEulerAndHamiltonGenerator<UndirectedAdjacencyMatrixGraph>, 10, 30>,
        cyclesFindExample<OnlyEulerAndNotHamiltonGenerator<UndirectedAdjacencyMatrixGraph>, 10, 30>,
        cyclesFindExample<OnlyHamiltonAndNotEulerGenerator<UndirectedAdjacencyMatrixGraph>, 10, 30>,
        cyclesFindExample<NeitherEulerNorHamiltonGenerator<UndirectedAdjacencyMatrixGraph>, 10, 30>,
    };

    printSeparator();
    for (const auto& callback : callbacks) {
        callback();
        printSeparator();
    }
}
