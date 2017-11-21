#include <iostream>
#include "Vector.h"
#include "Polyhed.h"

Tcor f(Vector);

int main() {
    Polyhed polyhed(*f);

    return 0;
}


Tcor f(Vector v) {
    Tcor A, B;

    A = 1;
    B = 1;

    return 2*(v.getX() - A) * (v.getX() - A) + (v.getY() - B) * (v.getY() - B);
}
