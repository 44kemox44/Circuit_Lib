#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <map>
#include <vector>
#include <set>
#include <memory>
#include "Component.h"

class Circuit {
private:
    std::map<int, std::map<int, std::vector<std::shared_ptr<CircuitComponent>>>> connections;

public:
    void connect(int node1Idx, int node2Idx, std::shared_ptr<CircuitComponent> component);
    double calculateResistance(int start, int end);
    
private:
    double calculateResistanceBetween(int start, int end, std::set<int>& visited);
    double calculatePathResistance(const std::vector<std::shared_ptr<CircuitComponent>>& components);
};

#endif // CIRCUIT_H
