#include <catch2/catch.hpp>
#include <graphs/graphs.hpp>

TEST_CASE("Generate complete graph and find all Hamilton cycles", "[HamiltonianGraph]") {
    const int VERTICES = 7;
    const int TOTAL_HAMILTONIAN_CYCLES = 720; // (n-1)!

    UndirectedIncidenceMatrixGraph graph(VERTICES);
    for (int i = 0; i < VERTICES - 1; ++i) {
        for (int j = i + 1; j < VERTICES; ++j) {
            graph.addEdge(i, j);
        }
    }

    HamiltonianCycleFind finder(graph);
    std::list<int> cycle;
    int counter = 0;
    while (true) {
        try {
            cycle = finder.find();
            counter++;
        } catch (CycleFindException& e) {
            break;
        }
    }

    REQUIRE(counter == TOTAL_HAMILTONIAN_CYCLES);
}

TEST_CASE("Generate Hamiltonian graph and find at least one Hamilton cycles", "[HamiltonianGraph]") {
    const int VERTICES = 10;
    const int SATURATION = 30;

    BothEulerianAndHamiltonianGenerator<UndirectedIncidenceMatrixGraph> gen;
    auto graph = gen.generate(VERTICES, SATURATION);

    HamiltonianCycleFind finder(graph);
    std::list<int> cycle;
    bool cycleFound = true;
    try {
        cycle = finder.find();
    } catch (CycleFindException& e) {
        cycleFound = false; 
    }

    REQUIRE(cycleFound);
}

TEST_CASE("Generate graph which is not Hamiltonian and try to find at least one Hamilton cycles", "[HamiltonianGraph]") {
    const int VERTICES = 10;
    const int SATURATION = 30;

    OnlyEulerianAndNotHamiltonianGenerator<UndirectedIncidenceMatrixGraph> gen;
    auto graph = gen.generate(VERTICES, SATURATION);

    HamiltonianCycleFind finder(graph);
    std::list<int> cycle;
    bool cycleNotFound = false;
    try {
        cycle = finder.find();
    } catch (CycleFindException& e) {
        cycleNotFound = true; 
    }

    REQUIRE(cycleNotFound);
}