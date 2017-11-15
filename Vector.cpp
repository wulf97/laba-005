#include "Vector.h"

void Vector::operator = (Vector v) {
    this->x = v.x;
    this->y = v.y;
}

Vector Vector::operator + (Vector v) {
    Vector rv;

    rv.x = this->x + v.x;
    rv.y = this->y + v.y;

    return rv;
}

Vector Vector::operator - (Vector v) {
    Vector rv;

    rv.x = this->x - v.x;
    rv.y = this->y - v.y;

    return rv;
}

Vector Vector::operator *(Tcor cor) {
    Vector rv;

    rv.x = this->x * cor;
    rv.y = this->y * cor;

    return rv;
}

Vector Vector::operator / (Tcor cor) {
    Vector rv;

    rv.x = this->x / cor;
    rv.y = this->y / cor;

    return rv;
}

void Vector::set(Tcor _x, Tcor _y) {
    this->x = _x;
    this->y = _y;
}

Tcor Vector::getX() {
    return this->x;
}

Tcor Vector::getY() {
    return this->y;
}

Tcor Vector::dist(Vector v) {
    return sqrt((this->x - v.x) * (this->x - v.x) + (this->y - v.y) * (this->y - v.y));
}

void Vector::print() {
    std::cout << "[" << this->x << ";" << this->y << "]" << std::endl;
}
