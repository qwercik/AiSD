#pragma once

#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/io.hpp>

/** Remember that graph structure is destroyed after using this class!
 **/
class EulerianCycleFind : public CycleFind {
public:
    EulerianCycleFind(UndirectedGraph& graph);

    virtual std::list<int> find() override;

private:
    bool checkExist();

    /**
     * Returns true if Eulerian cycle has been already found
     */
    bool findNextCycle();

    int startingVertex;
    int totalEdges;
    bool anyCycleExist;

    UndirectedGraph& graph;
    std::list<int> path;
    std::list<std::list<int>> successors;
    int currentVertex;
};