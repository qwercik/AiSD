#pragma once

#include <graphs/Graph.hpp>
#include <graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.hpp>
#include <graphs/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.hpp>
#include <graphs/AdjacencyList/DirectedAdjacencyListGraph.hpp>
#include <graphs/AdjacencyList/UndirectedAdjacencyListGraph.hpp>
#include <graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.hpp>
#include <graphs/IncidenceMatrix/UndirectedIncidenceMatrixGraph.hpp>
#include <graphs/Search/Search.hpp>
#include <graphs/Search/DeepFirstSearch.hpp>
#include <graphs/Search/BreadthFirstSearch.hpp>
#include <graphs/TopologicalSort/BreadthFirstSort.hpp>
#include <graphs/TopologicalSort/DeepFirstSort.hpp>
#include <graphs/Generator/Generator.hpp>
#include <graphs/Generator/IterativeGenerator.hpp>
#include <graphs/Generator/RandomGenerator.hpp>
#include <graphs/Generator/BothEulerAndHamiltonGenerator.hpp>
#include <graphs/Generator/NeitherEulerNorHamiltonGenerator.hpp>
#include <graphs/Generator/OnlyEulerAndNotHamiltonGenerator.hpp>
#include <graphs/Generator/OnlyHamiltonAndNotEulerGenerator.hpp>
#include <graphs/CycleFind/CycleFindException.hpp>
#include <graphs/CycleFind/HamiltonCycleFind.hpp>
#include <graphs/CycleFind/EulerCycleFind.hpp>
