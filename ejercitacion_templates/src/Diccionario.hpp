//
// Created by luis on 10/2/20.
//

#ifndef SOLUCION_DICCIONARIO_HPP
#define SOLUCION_DICCIONARIO_HPP

#include <vector>
#include <cassert>

using namespace std;

template <class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    vector<Clave> claves() const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};


template <class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {
}

template <class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template <class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template <class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template <class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    //assert(false);
}

template<class Clave, class Valor>
vector<Clave> Diccionario<Clave, Valor>::claves() const {
    vector<Clave> res;
    if (!_asociaciones.empty()){
        for (Asociacion elem : _asociaciones){
            res.push_back(elem.clave);
        }
        for (int i = 0; i < res.size() - 1; ++i) {
            for (int j = i; j < res.size(); ++j) {
                if (res[j] < res[i]){
                    Clave aux;
                    aux = res[j];
                    res[j] = res[i];
                    res[i] = aux;
                }
            }
        }
        return res;
    }

}

#endif //SOLUCION_DICCIONARIO_HPP
