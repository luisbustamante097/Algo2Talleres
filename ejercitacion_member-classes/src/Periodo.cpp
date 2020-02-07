#include "Periodo.h"

Periodo::Periodo(int anios, int meses, int dias) : _anios(anios), 
    _meses(meses), _dias(dias) {};

int Periodo::anios() const {
  return _anios;
}

int Periodo::meses() const {
  return _meses;
}

int Periodo::dias() const {
  return _dias;
}
