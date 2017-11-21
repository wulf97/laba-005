#ifndef POLYHED_H
#define POLYHED_H

#include <iostream>
#include "vector"
#include "Vector.h"

typedef Tcor (*Tfun)(Vector);

class Polyhed {
public:
    Polyhed(Tfun);

private:
    void init();
    void sort();
    Vector getC();
    Vector reflect(Vector, Tcor);
    Vector stretch(Vector, Vector, Tcor);
    Vector compression(Vector, Vector, Tcor);
    void globalCompression();
    Tcor max();

    Tfun f;
    Vector v[3];
};

#endif // POLYHED_H
