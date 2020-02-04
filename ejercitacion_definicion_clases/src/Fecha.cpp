//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes){
    int res;
    switch (mes){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            res = 31;
            break;
        case 4:case 6:case 9:case 11:
            res = 30;
            break;
        case 2:
            res = esBisiesto(anio) ? 29 : 28;
            break;
    }
    return res;
}
//

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  // Ejercicio 7: sumar período a fecha
  void sumar_periodo(Periodo p);

 private:
  Anio _anio;
  Mes _mes; 
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia) : _anio(anio), _mes(mes), _dia(dia) {
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


// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    return this->_dia == o.dia() &&
            this->_mes == o.mes() &&
            this->_anio == o._anio;
}

bool Fecha::operator<(Fecha o) const { //2002 < 2004
    bool res;
    if (_anio != o.anio()){
        res = _anio < o.anio();
    } else{
        if (_mes != o.mes()){
            res = _mes < o.mes();
        } else{
            res = _dia < o.dia();
        }
    }
    return res;
}

// Ejercicio 7
void Fecha::sumar_anios(int anios) {
    _anio += anios;
}

void Fecha::sumar_meses(int meses) {
    while (_mes + meses > 12){
        meses -= 12;
        sumar_anios(1);
    }
    _mes += meses;
}

void Fecha::sumar_dias(int dias) {
    if (dias + _dia <= diasEnMes(_anio, _mes)) {
        _dia += dias;
    } else {
        while ((dias + _dia) > diasEnMes(_anio, _mes)){
            _dia = (dias > diasEnMes(_anio, _mes) ? _dia : (dias + _dia) % diasEnMes(_anio, _mes));
            sumar_meses(1);
            dias = (dias > diasEnMes(_anio, _mes) ? dias-diasEnMes(_anio,_mes) : 0);
        }
    }
}


// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
    return !(f1 == f2);
}

// Ejercicio 6: clase período
class Periodo {
  public:
    Periodo(int anios, int meses, int dias);
    int anios() const;
    int meses() const;
    int dias() const;
  private:
    int _anios;
    int _meses;
    int _dias;
};

Periodo::Periodo(int anios, int meses, int dias){
    _anios = anios;
    _meses = meses;
    _dias = dias;
}

int Periodo::anios() const {
    return _anios;
}

int Periodo::meses() const {
    return _meses;
}

int Periodo::dias() const {
    return _dias;
}

// Ejercicio 7:
void Fecha::sumar_periodo(Periodo p) {
    sumar_anios(p.anios());
    sumar_meses(p.meses());
    sumar_dias(p.dias());
}

// Ejercicio 8: clase Intervalo

class Intervalo{
  public:
    Intervalo(Fecha desde, Fecha hasta);
    Fecha desde() const;
    Fecha hasta() const;
    int enDias() const;
  private:
    Fecha _desde;
    Fecha _hasta;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : _desde(desde), _hasta(hasta) {

}

Fecha Intervalo::desde() const {
    return _desde;
}

Fecha Intervalo::hasta() const {
    return _hasta;
}

int Intervalo::enDias() const {
    int res = 0;
    if (_desde.anio() == _hasta.anio()){
        if (_desde.mes() == _hasta.mes()){
            res = _hasta.dia()-_desde.dia();          // mismo Anio y mes
        } else {                                                           // mismo Anio, distinto Mes
            res = diasEnMes(_desde.anio(), _desde.mes()) - _desde.dia();    // sumo los dias del primer mes de Desde
            for (Mes m = _desde.mes() + 1; m < _hasta.mes(); m++) {         // sumo los dias de los meses en el medio
                res += diasEnMes(_desde.anio(), m);
            }
            res += _hasta.dia();                                            // sumo los dias del ultimo mes
        }
    } else {                                                           // distinto Anio, distinto Mes
        res = diasEnMes(_desde.anio(), _desde.mes()) - _desde.dia();    // sumo los dias del primer mes de Desde
        for (Mes m = _desde.mes() + 1; m <= 12; m++) {                  // sumo todos los dias hasta el fin del anio
            res += diasEnMes(_desde.anio(), m);
        }

        for (Anio a = _desde.anio() + 1; a < _hasta.anio(); a++) {      // sumo todos los dias en los anios del medio
            for (Mes m = 1; m <= 12; m++) {
                res += diasEnMes(_desde.anio(), m);
            }
        }

        for (Mes m = 1; m < _hasta.mes(); m++) {                        // sumo los dias del ultimo anio (no ultimo mes)
            res += diasEnMes(_hasta.anio(), m);
        }
        res += _hasta.dia();                                            // sumo los dias del ultimo mes del ultimo anio
    }
    return res;
}
