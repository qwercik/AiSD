cmake_minimum_required (VERSION 2.8.11)
project(graphs)

add_library(graphs
    src/graphs/Graph.cpp
    src/graphs/GraphException.cpp
    src/graphs/IncidenceMatrix/UndirectedIncidenceMatrixGraph.cpp
    src/graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.cpp
    src/graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.cpp
    src/graphs/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.cpp
    src/graphs/AdjacencyList/DirectedAdjacencyListGraph.cpp
    src/graphs/AdjacencyList/UndirectedAdjacencyListGraph.cpp
    
    src/graphs/CycleFind/CycleFindException.cpp
    src/graphs/CycleFind/EulerCycleFind.cpp
    src/graphs/CycleFind/HamiltonCycleFind.cpp

    src/graphs/Search/BreadthFirstSearch.cpp
    src/graphs/Search/DeepFirstSearch.cpp
    src/graphs/TopologicalSort/BreadthFirstSort.cpp
    src/graphs/TopologicalSort/DeepFirstSort.cpp
)

target_include_directories(graphs PUBLIC include/)


add_executable(example
    example/main.cpp
)

target_include_directories(example PUBLIC include/)
target_link_libraries(example PUBLIC graphs)


add_executable(unit-tests
    test/main.cpp
    test/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.cpp
    test/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.cpp
    test/IncidenceMatrix/UndirectedIncidenceMatrixGraph.cpp
    test/IncidenceMatrix/DirectedIncidenceMatrixGraph.cpp
    test/AdjacencyList/UndirectedAdjacencyListGraph.cpp
    test/AdjacencyList/DirectedAdjacencyListGraph.cpp
)

target_include_directories(unit-tests PUBLIC include/)
target_link_libraries(unit-tests PUBLIC graphs)

