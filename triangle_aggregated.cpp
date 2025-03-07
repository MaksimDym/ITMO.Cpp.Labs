#include "triangle_aggregated.h.cpp"
#include <cmath>
TriangleAggregated::TriangleAggregated(Dot* a, Dot* b, Dot* c) : a(a), b(b), c(c) {}

TriangleAggregated::~TriangleAggregated() {
    // Не освобождаем память для a, b, c, так как это агрегация
}

double TriangleAggregated::sideLengthAB() {
    return a->distanceTo(*b);
}

double TriangleAggregated::sideLengthBC() {
    return b->distanceTo(*c);
}

double TriangleAggregated::sideLengthCA() {
    return c->distanceTo(*a);
}

double TriangleAggregated::perimeter() {
    return sideLengthAB() + sideLengthBC() + sideLengthCA();
}

double TriangleAggregated::area() {
    double s = perimeter() / 2;
    double area = sqrt(s * (s - sideLengthAB()) * (s - sideLengthBC()) * (s - sideLengthCA()));
    return area;
}

