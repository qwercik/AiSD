#pragma once

#include <list>
#include <vector>
#include <knapsack/KnapsackSolver.hpp>
#include <knapsack/Item.hpp>
#include <io.hpp>

template <typename Weight, typename Value>
class BruteForceKnapsackSolver : public KnapsackSolver<Weight, Value> {
public:
    virtual std::list<Item<Weight, Value>> solve(Weight capacity, const std::vector<Item<Weight, Value>>& allItems) const override {
        Value theBestSetOfItemsValue = 0;
        std::list<bool> theBestSetOfItems;
        std::list<bool> currentSetOfItems(allItems.size(), false);

        do {
            auto weight = countTotalWeightInSetOfItems(currentSetOfItems, allItems);
            auto value = countTotalValueInSetOfItems(currentSetOfItems, allItems);

            if (weight <= capacity && value > theBestSetOfItemsValue) {
                theBestSetOfItemsValue = value;
                theBestSetOfItems = currentSetOfItems;
            }
        } while (generateNextSet(currentSetOfItems));

        return getSetAsListOfItems(theBestSetOfItems, allItems);
    }

private:
    std::list<Item<Weight, Value>> getSetAsListOfItems(const std::list<bool>& set, const std::vector<Item<Weight, Value>>& allItems) const {
        std::list<Item<Weight, Value>> resultList;
        
        std::size_t index = 0;
        for (const auto& elementInSet : set) {
            if (elementInSet) {
                resultList.push_back(allItems[index]);
            }

            index++;
        }

        return resultList;
    }

    Value countTotalValueInSetOfItems(const std::list<bool>& set, const std::vector<Item<Weight, Value>>& allItems) const {
        Value totalValue = 0;
        std::size_t index = 0;
        for (const auto& itemInSet : set) {
            if (itemInSet) {
                totalValue += allItems[index].second;
            }

            index++;
        }

        return totalValue;
    }

    Weight countTotalWeightInSetOfItems(const std::list<bool>& set, const std::vector<Item<Weight, Value>>& allItems) const {
        Weight totalWeight = 0;
        std::size_t index = 0;
        for (const auto& itemInSet : set) {
            if (itemInSet) {
                totalWeight += allItems[index].first;
            }

            index++;
        }

        return totalWeight;
    }

    bool generateNextSet(std::list<bool>& list) const {
        auto currentElement = list.rbegin();
        while (true) {
            if (currentElement == list.rend()) {
                return false;
            } else if (*currentElement == false) {
                *currentElement = true;
                return true;
            } else {
                *currentElement = false;
                currentElement++;
            }
        }
    }
};