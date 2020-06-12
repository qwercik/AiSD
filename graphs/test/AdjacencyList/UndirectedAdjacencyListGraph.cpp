#include <catch2/catch.hpp>
#include <graphs/Graph/AdjacencyList/UndirectedAdjacencyListGraph.hpp>

TEST_CASE("Basic UndirectedAdjacencyListGraph operations", "[UndirectedAdjacencyListGraph]") {
    const int VERTICES = 10;

    UndirectedAdjacencyListGraph graph(VERTICES);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 1);
    graph.addEdge(3, 5);

    REQUIRE(graph.totalEdges() == 6);
    REQUIRE(graph.maxEdges() == VERTICES * (VERTICES - 1) / 2);
    REQUIRE(!graph.isComplete());

    REQUIRE(graph.containsEdge(2, 3));
    REQUIRE(graph.containsEdge(3, 2));
    REQUIRE(!graph.containsEdge(2, 4));

    REQUIRE(graph.getDegree(1) == 2);
    REQUIRE(graph.getDegree(3) == 3);

    graph.removeEdge(2, 3);
    REQUIRE(!graph.containsEdge(2, 3));
}