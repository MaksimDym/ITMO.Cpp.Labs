#include <iostream>
#include "dot.h.cpp"
#include "triangle.h.cpp"
#include "triangle_aggregated.h.cpp"
#include "Windows.h"

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Dot d1(0, 0);
    Dot d2(3, 0);
    Dot d3(3, 4);

    Triangle t(d1, d2, d3);

    std::cout << "Стороны треугольника: " << t.sideLengthAB() << ", " << t.sideLengthBC() << ", " << t.sideLengthCA() << std::endl;
    std::cout << "Периметр: " << t.perimeter() << std::endl;
    std::cout << "Площадь: " << t.area() << std::endl;

    Dot* d4 = new Dot(0, 0);
    Dot* d5 = new Dot(5, 0);
    Dot* d6 = new Dot(5, 12);

    TriangleAggregated ta(d4, d5, d6);

    std::cout << "Стороны треугольника (агрегация): " << ta.sideLengthAB() << ", " << ta.sideLengthBC() << ", " << ta.sideLengthCA() << std::endl;
    std::cout << "Периметр (агрегация): " << ta.perimeter() << std::endl;
    std::cout << "Площадь (агрегация): " << ta.area() << std::endl;
    delete d4; // Освобождаем память для агрегации
    delete d5;
    delete d6;

    return 0;
}