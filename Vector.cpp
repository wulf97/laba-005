#include "Vector.h"

void Vector::operator = (Vector v) {
    x = v.x;
    y = v.y;
}

Vector Vector::operator + (Vector v) {
    Vector rv;

    rv.x = x + v.x;
    rv.y = y + v.y;

    return rv;
}

Vector Vector::operator - (Vector v) {
    Vector rv;

    rv.x = x - v.x;
    rv.y = y - v.y;

    return rv;
}

Vector Vector::operator *(Tcor cor) {
    Vector rv;

    rv.x = x * cor;
    rv.y = y * cor;

    return rv;
}

Vector Vector::operator / (Tcor cor) {
    Vector rv;

    rv.x = x / cor;
    rv.y = y / cor;

    return rv;
}

void Vector::set(Tcor _x, Tcor _y) {
    x = _x;
    y = _y;
}

Tcor Vector::getX() {
    return x;
}

Tcor Vector::getY() {
    return y;
}

Tcor Vector::dist(Vector v) {
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

void Vector::print() {
    std::cout << "[" << x << ";" << y << "]" << std::endl;
}
