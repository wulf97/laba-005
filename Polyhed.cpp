#include "Polyhed.h"

Polyhed::Polyhed(Tfun _f) {
    Vector v_c, v_r, v_e, v_s;
    Tcor a = 1,
         b = 2,
         g = 0.5;
    Tcor r, eps = 0.000001;

    this->f = _f;

    // Инициализация начальных векторов
    this->init();

    do {
        // Сортировка векторов по убыванию f(v[0]) - самое большое значение
        this->sort();

        // Получение центра масс
        v_c = this->getC();
        // Отражение точки относительно центра с коэффициентом a
        v_r = this->reflect(v_c, a);

        std::cout << "v_h";
        v[0].print();
        std::cout << "v_g";
        v[1].print();
        std::cout << "v_l";
        v[2].print();
        std::cout << "v_c";
        v_c.print();
        std::cout << "v_r";
        v_r.print();
        std::cout << std::endl;

        if (f(v_r) < f(this->v[2])) {
            // Растяжение фигуры
            v_e = this->stretch(v_c, v_r, b);

            if (f(v_e) < f(this->v[2]))
                this->v[0] = v_e;
            else
                this->v[0] = v_r;


        } else {
            if (f(this->v[2]) <= f(v_r) && f(v_r) < f(this->v[1])) {
                this->v[0] = v_r;
            } else {
                if (f(this->v[1]) <= f(v_r) && f(v_r) < f(this->v[0])) {
                    std::swap(v_r, this->v[0]);
                } else {
                    // Сжатие фигуры
                    v_s = this->compression(v_c, this->v[0], g);

                    if (f(v_s) < f(this->v[0]))
                        this->v[0] = v_s;
                    else
                        if (f(v_s) >= f(this->v[0]))
                            this->globalCompression();
                }
            }

        }

        r = this->max();
    } while (r > eps);

    std::cout << f(this->v[2]) << std::endl;
}

void Polyhed::init() {
    Vector v1(0, 0);
    Vector v2(1, 0);
    Vector v3(0, 1);

    this->v[0] = v1;
    this->v[1] = v2;
    this->v[2] = v3;

}

void Polyhed::sort() {
    for (int i = 2; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (f(this->v[j]) < f(this->v[j + 1]))
                std::swap(this->v[j], this->v[j + 1]);
        }
    }
}

Vector Polyhed::getC() {
    return (this->v[1] + this->v[2]) / 2;
}

Vector Polyhed::reflect(Vector v_c, Tcor a) {
    return v_c - (this->v[0] - v_c) * a;
}

Vector Polyhed::stretch(Vector v_c, Vector v_r, Tcor b) {
    return v_c + (v_r - v_c) * b;
}

Vector Polyhed::compression(Vector v_c, Vector v_h, Tcor g) {
    return v_c + (v_h - v_c) * g;
}

void Polyhed::globalCompression() {
    this->v[0] = this->v[2] + (this->v[0] - this->v[2]) / 2;
    this->v[1] = this->v[2] + (this->v[1] - this->v[2]) / 2;
}

Tcor Polyhed::max() {
    Tcor max;

    max = this->v[0].dist(this->v[1]);

    if (max < this->v[0].dist(this->v[2]))
        max = this->v[0].dist(this->v[2]);
    else
        if (max < this->v[1].dist(this->v[2]))
             max = this->v[1].dist(this->v[2]);

    return max;
}
