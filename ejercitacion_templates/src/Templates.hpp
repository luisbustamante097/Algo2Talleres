//
// Created by luis on 10/2/20.
//

#ifndef SOLUCION_TEMPLATES_HPP
#define SOLUCION_TEMPLATES_HPP

template<class T>
T cuadrado(T x) {
    return x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    bool res = true;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            res = false;
        }
    }
    return res;
}

template<class Contenedor, class Elem>
Elem maximo(Contenedor c) {
    Elem res = c[0];
    for (int i = 1; i < c.size(); ++i) {
        if (c[i]>res){
            res = c[i];
        }
    }
    return res;
}

#endif //SOLUCION_TEMPLATES_HPP
