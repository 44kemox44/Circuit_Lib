#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor : public CircuitComponent {
private:
    double resistance;  // Resistance value

public:
    Resistor(double r);
    double getResistance() const override;
};

#endif // RESISTOR_H
