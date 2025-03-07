#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "dot.h.cpp"

class Triangle {
private:
    Dot a;
    Dot b;
    Dot c;

public:
    Triangle(Dot a, Dot b, Dot c);
    double sideLengthAB();
    double sideLengthBC();
    double sideLengthCA();
    double perimeter();
    double area();
};

#endif  