#include "Circuit.h"
#include <limits> // Ensure this is included

const double INF = 1e9; // Define a large constant to represent "infinity"

void Circuit::connect(int node1Idx, int node2Idx, std::shared_ptr<CircuitComponent> component) {
    connections[node1Idx][node2Idx].push_back(component);
}

double Circuit::calculateResistance(int start, int end) {
    std::set<int> visited;  // To track visited nodes and prevent cycles
    return calculateResistanceBetween(start, end, visited);
}

double Circuit::calculateResistanceBetween(int start, int end, std::set<int>& visited) {
    if (start == end) return 0.0;  // No resistance to itself
    if (visited.count(start)) return INF;  // Prevent cycles

    visited.insert(start);
    double totalReciprocal = 0.0;

    for (const auto& nextNode : connections[start]) {
        int nodeIndex = nextNode.first;
        double pathResistance = calculatePathResistance(nextNode.second);
        double remainingResistance = calculateResistanceBetween(nodeIndex, end, visited);
        if (remainingResistance != INF) {
            totalReciprocal += (1.0 / (pathResistance + remainingResistance));
        }
    }

    visited.erase(start);  // Backtrack
    return totalReciprocal > 0 ? 1.0 / totalReciprocal : INF;
}

double Circuit::calculatePathResistance(const std::vector<std::shared_ptr<CircuitComponent>>& components) {
    if (components.empty()) return INF;

    double parallelReciprocal = 0.0;
    for (const auto& component : components) {
        parallelReciprocal += (1.0 / component->getResistance());
    }
    return 1.0 / parallelReciprocal;  // Convert to equivalent resistance
}
