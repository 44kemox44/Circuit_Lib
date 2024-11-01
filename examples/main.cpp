#include <iostream>
#include <memory>
#include "Circuit.h"
#include "Resistor.h"

int main() {
    Circuit circuit;  // Create a circuit

    // Create resistors
    auto resistor1 = std::make_shared<Resistor>(10); // 10 ohm resistor
    auto resistor2 = std::make_shared<Resistor>(10); // 10 ohm resistor
    auto resistor3 = std::make_shared<Resistor>(10); // 10 ohm resistor

    // Connect nodes with resistors
    circuit.connect(0, 1, resistor1);
    circuit.connect(1, 2, resistor2);
    circuit.connect(1, 2, resistor3);  // Adding another path to the same nodes
    circuit.connect(0, 2, resistor1); // Direct connection with another 10 ohm resistor

    double totalResistance = circuit.calculateResistance(0, 2);
    std::cout << "Total Resistance from Node 0 to Node 2: " << totalResistance << " ohms" << std::endl;  // Expected output: 6 ohms

    return 0;
}
