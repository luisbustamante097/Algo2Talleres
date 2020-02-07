#include "Meses.h"
#include "Funciones.h"
#include "Periodo.h"

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  void sumar_periodo(Periodo p);

 private:
  Anio _anio;
  Mes _mes;
  Dia _dia;

  void ajustar_fecha();
  void sumar_anios(Anio anios);
  void sumar_meses(Mes meses);
  void sumar_dias(Dia dias);
};

Fecha::Fecha(Anio anio, Mes mes, Dia dia) {
  _anio = anio;
  _mes = mes;
  _dia = dia;
}

Anio Fecha::anio() const {
  return _anio;
}

Mes Fecha::mes() const {
  return _mes;
}

Dia Fecha::dia() const {
  return _dia;
}

bool Fecha::operator==(Fecha o) const {
  return (_anio == o.anio() and _mes == o.mes() and _dia == o.dia());
}

bool Fecha::operator<(Fecha o) const {
  return (_anio < o.anio() or
          (_anio == o.anio() and _mes < o.mes()) or
          (_anio == o.anio() and _mes == o.mes() and _dia < o.dia()));
}

bool operator!=(Fecha f1, Fecha f2) {
  return not (f1 == f2);
}

void Fecha::ajustar_fecha() {
  while (_mes > 12 || _dia > diasEnMes(_anio, _mes)) {
    if (_mes > 12) {
      _mes -= 12;
      _anio += 1;
    } else {
      _dia -= diasEnMes(_anio, _mes);
      _mes += 1;
    }
  }
}

void Fecha::sumar_anios(int anios) {
  _anio += anios;
  ajustar_fecha();
}

void Fecha::sumar_meses(int meses) {
  _mes += meses;
  ajustar_fecha();
}

void Fecha::sumar_dias(int dias) {
  _dia += dias;
  ajustar_fecha();
}

void Fecha::sumar_periodo(Periodo p) {
  sumar_anios(p.anios());
  sumar_meses(p.meses());
  sumar_dias(p.dias());
}

class Intervalo {
 public:
  // pre: desde < hasta
  Intervalo(Fecha desde, Fecha hasta);

  Fecha desde() const;
  Fecha hasta() const;

  int enDias() const;

 private:
  Fecha _desde;
  Fecha _hasta;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : _desde(desde), _hasta(hasta) {};

Fecha Intervalo::desde() const {
  return _desde;
}

Fecha Intervalo::hasta() const {
  return _hasta;
}

int Intervalo::enDias() const {
  Fecha actual = _desde;
  int dias = 0;
  while (actual != _hasta) {
    dias++;
    actual.sumar_periodo(Periodo(0, 0, 1));
  }
  return dias;
}
