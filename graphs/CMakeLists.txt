cmake_minimum_required (VERSION 2.8.11)
project(graphs)

include_directories(include/)
add_executable(
    graphs
    src/main.cpp
    src/graphs/Graph.cpp
    src/graphs/IncidenceMatrix/UndirectedIncidenceMatrixGraph.cpp
    src/graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.cpp
    src/graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.cpp
    src/graphs/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.cpp
    src/graphs/AdjacencyList/DirectedAdjacencyListGraph.cpp
    src/graphs/AdjacencyList/UndirectedAdjacencyListGraph.cpp
    src/graphs/Search/BreadthFirstSearch.cpp
    src/graphs/Search/DeepFirstSearch.cpp
    src/graphs/TopologicalSorting/BreadthFirstSorting.cpp
    src/graphs/TopologicalSorting/DeepFirstSorting.cpp
)
