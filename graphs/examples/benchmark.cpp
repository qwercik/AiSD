#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <chrono>
#include <graphs/graphs.hpp>

using Algorithm = void(*)(int verticesNumber, int saturationPercents);


double measureExecutionTime(std::function<void()> callback) {
    auto startTime = std::chrono::high_resolution_clock::now();
    callback();
    auto stopTime = std::chrono::high_resolution_clock::now();

    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();
    return milliseconds / 1000.;
}

template <typename GraphGenerator>
void generateGraph(int verticesNumber, int saturationPercents) {
    GraphGenerator generator;

    std::cout << measureExecutionTime([&]() {
        auto graph = generator.generate(verticesNumber, saturationPercents);
    }) << '\n';
}

template <typename GraphGenerator, typename SearchAlgorithm>
void searchGraph(int verticesNumber, int saturationPercents) {
    GraphGenerator generator;
    auto graph = generator.generate(verticesNumber, saturationPercents);
    SearchAlgorithm search;

    std::cout << measureExecutionTime([&]() {
        search.search(graph);
    }) << '\n';
}

template <typename GraphGenerator, typename SortAlgorithm>
void topologicalSortGraph(int verticesNumber, int saturationPercents) {
    GraphGenerator generator;
    auto graph = generator.generate(verticesNumber, saturationPercents);
    SortAlgorithm sort;

    std::cout << measureExecutionTime([&]() {
        sort.sort(graph);
    }) << '\n';
}

template <typename GraphGenerator, typename CycleFindAlgorithm>
void findSingleCycle(int verticesNumber, int saturationPercents) {
    GraphGenerator generator;
    auto graph = generator.generate(verticesNumber, saturationPercents);
    CycleFindAlgorithm finder(graph);

    std::cout << measureExecutionTime([&]() {
        try {
            finder.find();
        } catch (CycleNotFoundException& e) {
            // Do nothing
        }
    }) << '\n';
}

template <typename GraphGenerator, typename CycleFindAlgorithm>
void findAllCycles(int verticesNumber, int saturationPercents) {
    GraphGenerator generator;
    auto graph = generator.generate(verticesNumber, saturationPercents);
    CycleFindAlgorithm finder(graph);

    std::cout << measureExecutionTime([&]() {
        while (true) {
            try {
                finder.find();
            } catch (CycleNotFoundException& e) {
                break;
            }
        }
    }) << '\n';
}


int main(int argc, char *argv[]) {
    std::unordered_map<std::string, Algorithm> actions = {
        {"generate-undirected-adjacency-matrix", generateGraph<IterativeGenerator<UndirectedAdjacencyMatrixGraph>>},
        {"generate-undirected-adjacency-list", generateGraph<IterativeGenerator<UndirectedAdjacencyListGraph>>},
        {"generate-undirected-incidence-matrix", generateGraph<IterativeGenerator<UndirectedIncidenceMatrixGraph>>},
        {"generate-directed-adjacency-matrix", generateGraph<IterativeGenerator<DirectedAdjacencyMatrixGraph>>},
        {"generate-directed-adjacency-list", generateGraph<IterativeGenerator<DirectedAdjacencyListGraph>>},
        {"generate-directed-incidence-matrix", generateGraph<IterativeGenerator<DirectedIncidenceMatrixGraph>>},
        
        {"search-bfs-undirected-adjacency-matrix", searchGraph<IterativeGenerator<UndirectedAdjacencyMatrixGraph>, BreadthFirstSearch>},
        {"search-bfs-undirected-adjacency-list", searchGraph<IterativeGenerator<UndirectedAdjacencyListGraph>, BreadthFirstSearch>},
        {"search-bfs-undirected-incidence-matrix", searchGraph<IterativeGenerator<UndirectedIncidenceMatrixGraph>, BreadthFirstSearch>},
        {"search-bfs-directed-adjacency-matrix", searchGraph<IterativeGenerator<DirectedAdjacencyMatrixGraph>, BreadthFirstSearch>},
        {"search-bfs-directed-adjacency-list", searchGraph<IterativeGenerator<DirectedAdjacencyListGraph>, BreadthFirstSearch>},
        {"search-bfs-directed-incidence-matrix", searchGraph<IterativeGenerator<DirectedIncidenceMatrixGraph>, BreadthFirstSearch>},

        {"search-dfs-undirected-adjacency-matrix", searchGraph<IterativeGenerator<UndirectedAdjacencyMatrixGraph>, DeepFirstSearch>},
        {"search-dfs-undirected-adjacency-list", searchGraph<IterativeGenerator<UndirectedAdjacencyListGraph>, DeepFirstSearch>},
        {"search-dfs-undirected-incidence-matrix", searchGraph<IterativeGenerator<UndirectedIncidenceMatrixGraph>, DeepFirstSearch>},
        {"search-dfs-directed-adjacency-matrix", searchGraph<IterativeGenerator<DirectedAdjacencyMatrixGraph>, DeepFirstSearch>},
        {"search-dfs-directed-adjacency-list", searchGraph<IterativeGenerator<DirectedAdjacencyListGraph>, DeepFirstSearch>},
        {"search-dfs-directed-incidence-matrix", searchGraph<IterativeGenerator<DirectedIncidenceMatrixGraph>, DeepFirstSearch>},


        {"sort-bfs-directed-adjacency-matrix", topologicalSortGraph<IterativeGenerator<DirectedAdjacencyMatrixGraph>, TopologicalBreadthFirstSort>},
        {"sort-bfs-directed-adjacency-list", topologicalSortGraph<IterativeGenerator<DirectedAdjacencyListGraph>, TopologicalBreadthFirstSort>},
        {"sort-bfs-directed-incidence-matrix", topologicalSortGraph<IterativeGenerator<DirectedIncidenceMatrixGraph>, TopologicalBreadthFirstSort>},
        {"sort-dfs-directed-adjacency-matrix", topologicalSortGraph<IterativeGenerator<DirectedAdjacencyMatrixGraph>, TopologicalDeepFirstSort>},
        {"sort-dfs-directed-adjacency-list", topologicalSortGraph<IterativeGenerator<DirectedAdjacencyListGraph>, TopologicalDeepFirstSort>},
        {"sort-dfs-directed-incidence-matrix", topologicalSortGraph<IterativeGenerator<DirectedIncidenceMatrixGraph>, TopologicalDeepFirstSort>},

        {"generate-hamiltonian-eulerian", generateGraph<BothEulerianAndHamiltonianGenerator<UndirectedAdjacencyMatrixGraph>>},

        {"find-single-cycle-in-hamiltonian", findSingleCycle<BothEulerianAndHamiltonianGenerator<UndirectedAdjacencyMatrixGraph>, HamiltonianCycleFind>},
        {"find-all-cycles-in-hamiltonian", findAllCycles<BothEulerianAndHamiltonianGenerator<UndirectedAdjacencyMatrixGraph>, HamiltonianCycleFind>},
        {"find-any-cycle-in-nonhamiltonian", findSingleCycle<OnlyEulerianAndNotHamiltonianGenerator<UndirectedAdjacencyMatrixGraph>, HamiltonianCycleFind>},

        {"find-single-cycle-in-eulerian", findSingleCycle<BothEulerianAndHamiltonianGenerator<UndirectedAdjacencyMatrixGraph>, EulerianCycleFind>},
        {"find-all-cycles-in-eulerian", findAllCycles<BothEulerianAndHamiltonianGenerator<UndirectedAdjacencyMatrixGraph>, EulerianCycleFind>},
        {"find-any-cycle-in-noneulerian", findSingleCycle<OnlyHamiltonianAndNotEulerianGenerator<UndirectedAdjacencyMatrixGraph>, EulerianCycleFind>},
    };

    if (argc != 3) {
        std::cerr << "Incorrect usage\n";
        std::cerr << "Usage: " << argv[0] << " <action> <saturation>\n";
        std::cerr << "Pass value <vertices> at standard input\n\n";
        std::cerr << "Legend:\n";
        std::cerr << "  ->  <vertices> - a positive integer representing number of vertices in graph\n";
        std::cerr << "  ->  <saturation> a positive integer from range [0, 100] representing saturation coefficient\n";
        return 1;
    }

    std::string actionName = argv[1];
    if (actions.find(actionName) == actions.end()) {
        std::cerr << "Such action does not exist\n";
        return 1;
    }

    int saturationPercents = std::stoi(argv[2]);
    if (saturationPercents <= 0 || saturationPercents >= 100) {
        std::cerr << "Saturation percents should be from range [0, 100]\n";
        return 1;
    }

    int verticesNumber;
    std::cin >> verticesNumber;
    if (verticesNumber <= 0) {
        std::cerr << "Vertices number should be a positive integer\n";
        return 1;
    }

    actions[actionName](verticesNumber, saturationPercents);
}