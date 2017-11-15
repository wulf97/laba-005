#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

typedef double Tcor;

class Vector {
public:
    Vector(Tcor _x = 0, Tcor _y = 0) : x(_x), y(_y) {}

    void operator = (Vector);
    Vector operator + (Vector);
    Vector operator - (Vector);
    Vector operator * (Tcor);
    Vector operator / (Tcor);

    void set(Tcor, Tcor);
    Tcor getX();
    Tcor getY();
    Tcor dist(Vector);
    void print();
private:
    Tcor x;
    Tcor y;
};

#endif // VECTOR_H
