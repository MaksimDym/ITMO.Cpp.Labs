#ifndef DOT_H
#define DOT_H

class Dot {
private:
    double x;
    double y;

public:
    Dot();
    Dot(double x, double y);
    double distanceTo(Dot point);
    double getX() const { return x; }
    double getY() const { return y; }
};

#endif 