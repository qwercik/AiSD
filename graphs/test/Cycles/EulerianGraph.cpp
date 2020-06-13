#include <catch2/catch.hpp>
#include <graphs/graphs.hpp>

TEST_CASE("Generate complete graph and find all Eulerian cycles", "[EulerianGraph]") {
    const int VERTICES = 5;
    // Value from the following document: http://www.algana.co.uk/publications/Counting.pdf
    const int TOTAL_EULERIAN_CYCLES = 528;

    UndirectedIncidenceMatrixGraph graph(VERTICES);
    for (int i = 0; i < VERTICES - 1; ++i) {
        for (int j = i + 1; j < VERTICES; ++j) {
            graph.addEdge(i, j);
        }
    }

    EulerianCycleFind finder(graph);
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

    REQUIRE(counter == TOTAL_EULERIAN_CYCLES);
}

TEST_CASE("Generate Eulerian graph and find at least one Eulerian cycle", "[EulerianGraph]") {
    const int VERTICES = 10;
    const int SATURATION = 30;

    BothEulerianAndHamiltonianGenerator<UndirectedIncidenceMatrixGraph> gen;
    auto graph = gen.generate(VERTICES, SATURATION);

    EulerianCycleFind finder(graph);
    std::list<int> cycle;
    bool cycleFound = true;
    try {
        cycle = finder.find();
    } catch (CycleFindException& e) {
        cycleFound = false; 
    }

    REQUIRE(cycleFound);
}

TEST_CASE("Generate graph which is not Eulerian and try to find at least one Eulerian cycles", "[EulerianGraph]") {
    const int VERTICES = 10;
    const int SATURATION = 30;

    OnlyHamiltonianAndNotEulerianGenerator<UndirectedIncidenceMatrixGraph> gen;
    auto graph = gen.generate(VERTICES, SATURATION);

    EulerianCycleFind finder(graph);
    std::list<int> cycle;
    bool cycleNotFound = false;
    try {
        cycle = finder.find();
    } catch (CycleFindException& e) {
        cycleNotFound = true; 
    }

    REQUIRE(cycleNotFound);
}