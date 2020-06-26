/** Program testujący wydajność poszczególnych implementacji problemu plecakowego
 * Na standardowym strumieniu wyjścia znajdzie się czas działania algorytmu w sekundach
 * Na standardowym strumieniu błędów znajdą się pozostałe informacje (ewentualne błędy, wynik działania algorytmu itd.)
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <cstdlib>
#include <functional>
#include <chrono>
#include <knapsack/knapsack.hpp>

void displayHelp() {
    std::cerr << "Use: ./benchmark <algorithm>\n\n";

    std::cerr << "Where:\n";
    std::cerr << "\t<algorithm>: brute, dynamic\n";
}

double measureExecutionTime(std::function<void()> callback) {
    auto startTime = std::chrono::high_resolution_clock::now();
    callback();
    auto stopTime = std::chrono::high_resolution_clock::now();

    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();
    return milliseconds / 1000.;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect usage\n";
        displayHelp();
        return EXIT_FAILURE;
    }

    std::string algorithmName = argv[1];
    std::unique_ptr<KnapsackSolver<unsigned int, unsigned int>> solver;

    if (algorithmName == "brute") {
        solver.reset(new BruteForceKnapsackSolver<unsigned int, unsigned int>);
    } else if (algorithmName == "dynamic") {
        solver.reset(new DynamicProgrammingKnapsackSolver<unsigned int, unsigned int>);
    } else {
        std::cerr << "Unknown algorithm \"" << algorithmName << "\"\n";
        displayHelp();
        return EXIT_FAILURE;
    }

    unsigned int capacity;
    std::cin >> capacity;

    std::vector<Item<unsigned int, unsigned int>> allItems;
    unsigned int weight, value;
    while (std::cin >> weight >> value) {
        allItems.push_back({weight, value});
    }

    std::list<Item<unsigned int, unsigned int>> result;
    std::cout << measureExecutionTime([&]() {
        result = solver->solve(capacity, allItems);
    }) << '\n';

    for (const auto& item : result) {
        std::cerr << item.first << ' ' << item.second << '\n';
    }
}