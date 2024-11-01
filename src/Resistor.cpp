#include "Resistor.h"

Resistor::Resistor(double r) : resistance(r) {}

double Resistor::getResistance() const {
    return resistance;
}
