#ifndef COMPONENT_H
#define COMPONENT_H

class CircuitComponent {
public:
    virtual double getResistance() const = 0; // Pure virtual function
    virtual ~CircuitComponent() = default;     // Virtual destructor
};

#endif // COMPONENT_H
