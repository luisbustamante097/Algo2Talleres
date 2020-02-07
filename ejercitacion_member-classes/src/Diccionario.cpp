/* Completar */

#include "Diccionario.h"


Diccionario::Diccionario() : _elementos() {

}

void Diccionario::definir(Clave k, Valor v) {
    bool encontrado = false;
    for (Asociacion& elem : _elementos){
        if (k == elem.clave){
            elem = {k,v};
            encontrado = true;
        }
    }
    if (!encontrado){
        _elementos.push_back({k,v});
    }
}

bool Diccionario::def(Clave k) const {
    bool encontrado = false;
    for (Asociacion elem : _elementos){
        if (k == elem.clave){
            encontrado = true;
        }
    }
    return encontrado;
}

Valor Diccionario::obtener(Clave k) const {
    Valor res;
    for (Asociacion elem : _elementos){
        if (k == elem.clave){
            res = elem.valor;
        }
    }
    return res;
}

void Diccionario::borrar(int clave) {
    int i = 0;
    for (Asociacion elem : _elementos) {
        if (clave == elem.clave){
            _elementos.erase(_elementos.begin() + i);
        }
        i++;
    }
}

vector<Clave> Diccionario::claves() const {
    vector<Clave> res;
    for (Asociacion elem : _elementos) {
        res.push_back(elem.clave);
    }
    return res;
}

bool Diccionario::operator==(Diccionario o) {
    bool res = true;
    for (Asociacion elem : _elementos){
        if (!o.def(elem.clave) || o.obtener(elem.clave) != elem.valor){
            res = false;
        }
    }
    for (Asociacion elem : o._elementos){
        if (!this->def(elem.clave) || this->obtener(elem.clave) != elem.valor){
            res = false;
        }
    }
    return res;
}

Diccionario Diccionario::operator||(Diccionario o) const{
    Diccionario unionRes;
    for(Asociacion a : _elementos){
        unionRes.definir(a.clave,a.valor);
    }
    for(Asociacion a : o._elementos){
        if (!unionRes.def(a.clave)){
            unionRes.definir(a.clave,a.valor);
        }
    }
    return unionRes;
}


Diccionario Diccionario::operator&&(Diccionario o) const{
    Diccionario interseccionRes;
    for(Asociacion a : _elementos){
        if (o.def(a.clave)){
            interseccionRes.definir(a.clave,a.valor);
        }
    }
    return interseccionRes;
}
