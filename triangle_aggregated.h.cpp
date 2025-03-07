#ifndef TRIANGLE_AGGREGATED_H
#define TRIANGLE_AGGREGATED_H

#include "dot.h.cpp"

class TriangleAggregated {
private:
    Dot* a;
    Dot* b;
    Dot* c;

public:
    TriangleAggregated(Dot* a, Dot* b, Dot* c);
    ~TriangleAggregated(); 
    double sideLengthAB();
    double sideLengthBC();
    double sideLengthCA();
    double perimeter();
    double area();
};

#endif 
