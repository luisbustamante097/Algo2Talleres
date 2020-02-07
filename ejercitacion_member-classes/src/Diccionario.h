#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

typedef int Clave;
typedef int Valor;

using namespace std;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;

    void borrar(int clave);

    vector<Clave> claves() const;

    bool operator==(Diccionario o);

    Diccionario operator||(Diccionario o) const;
    Diccionario operator&&(Diccionario o) const;

        private:
	struct Asociacion {
		Clave clave;
		Valor valor;
	};
	vector<Asociacion> _elementos;
};

#endif /*__DICCIONARIO_H__*/
