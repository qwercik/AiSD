cmake_minimum_required (VERSION 2.8.11)
project(graphs)

add_library(graphs
    src/graphs/Graph/Graph.cpp
    src/graphs/Graph/GraphException.cpp
    src/graphs/Graph/GraphVertexOutOfRangeException.cpp
    src/graphs/Graph/GraphEdgeNotExistException.cpp

    src/graphs/Graph/IncidenceMatrix/UndirectedIncidenceMatrixGraph.cpp
    src/graphs/Graph/IncidenceMatrix/DirectedIncidenceMatrixGraph.cpp
    src/graphs/Graph/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.cpp
    src/graphs/Graph/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.cpp
    src/graphs/Graph/AdjacencyList/DirectedAdjacencyListGraph.cpp
    src/graphs/Graph/AdjacencyList/UndirectedAdjacencyListGraph.cpp

    src/graphs/CycleFind/CycleFindException.cpp
    src/graphs/CycleFind/CycleNotFoundException.cpp
    src/graphs/CycleFind/EulerianCycleFind.cpp
    src/graphs/CycleFind/HamiltonianCycleFind.cpp

    src/graphs/Search/BreadthFirstSearch.cpp
    src/graphs/Search/DeepFirstSearch.cpp

    src/graphs/TopologicalSort/TopologicalSortException.cpp
    src/graphs/TopologicalSort/TopologicalSortCycleFoundException.cpp
    src/graphs/TopologicalSort/TopologicalBreadthFirstSort.cpp
    src/graphs/TopologicalSort/TopologicalDeepFirstSort.cpp

    src/graphs/Generator/GeneratorException.cpp
    src/graphs/Generator/GeneratorSaturationOutOfRangeException.cpp

    src/graphs/random.cpp
)

target_include_directories(graphs PUBLIC include/)



add_executable(unit-tests
    test/main.cpp

    test/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.cpp
    test/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.cpp
    test/IncidenceMatrix/UndirectedIncidenceMatrixGraph.cpp
    test/IncidenceMatrix/DirectedIncidenceMatrixGraph.cpp
    test/AdjacencyList/UndirectedAdjacencyListGraph.cpp
    test/AdjacencyList/DirectedAdjacencyListGraph.cpp

    test/Cycles/HamiltonianGraph.cpp
    test/Cycles/EulerianGraph.cpp
)

target_include_directories(unit-tests PUBLIC include/)
target_link_libraries(unit-tests PUBLIC graphs)



add_executable(example
    examples/example.cpp
)
target_include_directories(example PUBLIC include/)
target_link_libraries(example PUBLIC graphs)


add_executable(benchmark
    examples/benchmark.cpp
)
target_include_directories(benchmark PUBLIC include/)
target_link_libraries(benchmark PUBLIC graphs)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -Wpedantic -O2")