#include "triangle.h.cpp"
#include <cmath>

Triangle::Triangle(Dot a, Dot b, Dot c) : a(a), b(b), c(c) {}

double Triangle::sideLengthAB() {
    return a.distanceTo(b);
}

double Triangle::sideLengthBC() {
    return b.distanceTo(c);
}

double Triangle::sideLengthCA() {
    return c.distanceTo(a);
}

double Triangle::perimeter() {
    return sideLengthAB() + sideLengthBC() + sideLengthCA();
}

double Triangle::area() {
    double s = perimeter() / 2;
    double area = sqrt(s * (s - sideLengthAB()) * (s - sideLengthBC()) * (s - sideLengthCA()));
    return area;
}
