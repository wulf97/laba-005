#include <iomanip>
#include "Polyhed.h"

Polyhed::Polyhed(Tfun _f) {
    Vector v_c, v_r, v_e, v_s;
    Tcor a = 1,
         b = 2,
         g = 0.5;
    Tcor r, eps = 0.000001;
    int it = 0;

    f = _f;

    // Инициализация начальных векторов
    init();

    do {
        // Сортировка векторов по убыванию f(v[0]) - самое большое значение
        sort();

        // Получение центра масс
        v_c = getC();
        // Отражение точки относительно центра с коэффициентом a
        v_r = reflect(v_c, a);

        if (f(v_r) < f(v[2])) {
            // Растяжение фигуры
            v_e = stretch(v_c, v_r, b);

            if (f(v_e) < f(v[2]))
                v[0] = v_e;
            else
                v[0] = v_r;
        } else {
            if (f(v[2]) <= f(v_r) && f(v_r) < f(v[1])) {
                v[0] = v_r;
            } else {
                if (f(v[1]) <= f(v_r) && f(v_r) < f(v[0])) {
                    std::swap(v_r, v[0]);
                } else {
                    // Сжатие фигуры
                    v_s = compression(v_c, v[0], g);

                    if (f(v_s) < f(v[0]))
                        v[0] = v_s;
                    else
                        if (f(v_s) >= f(v[0]))
                            globalCompression();
                }
            }

        }

        r = max();
        it++;

        std::cout << std::left << std::setw(2) << std::setfill(' ') << it << " | ";
        std::cout << std::left << std::setw(10) << std::setfill(' ') << v[2].getX() << " | ";
        std::cout << std::left << std::setw(10) << std::setfill(' ') << v[2].getY() << " | ";
        std::cout << std::left << std::setw(10) << std::setfill(' ') << r << std::endl;
    } while (r > eps);
}

void Polyhed::init() {
    Vector v1(0, 0);
    Vector v2(1, 0);
    Vector v3(0, 1);

    v[0] = v1;
    v[1] = v2;
    v[2] = v3;

}

void Polyhed::sort() {
    for (int i = 2; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (f(v[j]) < f(v[j + 1]))
                std::swap(v[j], v[j + 1]);
        }
    }
}

Vector Polyhed::getC() {
    return (v[1] + v[2]) / 2;
}

Vector Polyhed::reflect(Vector v_c, Tcor a) {
    return v_c - (v[0] - v_c) * a;
}

Vector Polyhed::stretch(Vector v_c, Vector v_r, Tcor b) {
    return v_c + (v_r - v_c) * b;
}

Vector Polyhed::compression(Vector v_c, Vector v_h, Tcor g) {
    return v_c + (v_h - v_c) * g;
}

void Polyhed::globalCompression() {
    v[0] = v[2] + (v[0] - v[2]) / 2;
    v[1] = v[2] + (v[1] - v[2]) / 2;
}

Tcor Polyhed::max() {
    Tcor max;

    max = v[0].dist(v[1]);

    if (max < v[0].dist(v[2]))
        max = v[0].dist(v[2]);
    else
        if (max < v[1].dist(v[2]))
             max = v[1].dist(v[2]);

    return max;
}
