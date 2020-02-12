//
// Created by luis on 11/2/20.
//

#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP

#include <map>
#include "Diccionario.hpp"

using namespace std;
template <class T>
class Multiconjunto{
  public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

  private:
    Diccionario<T,int> _elementos;
};

template<class T>
Multiconjunto<T>::Multiconjunto() : _elementos(){
}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if (_elementos.def(x)){
        _elementos.definir(x,_elementos.obtener(x)+1);
    }else{
        _elementos.definir(x,1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    return _elementos.obtener(x);
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    bool res = true;
    if (otro._elementos.claves().empty()){
        res = this->_elementos.claves().empty();
    } else {
        for (T clave : this->_elementos.claves()) {
            if (otro._elementos.def(clave)) {
                if (this->ocurrencias(clave) > otro.ocurrencias(clave)) {
                    res = false;
                }
            } else {
                res = false;
            }
        }
    }
    return res;
}


#endif //SOLUCION_MULTICONJUNTO_HPP
