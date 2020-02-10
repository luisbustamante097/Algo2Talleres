#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes() : _conns() {
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (registrado(id)){
        delete _conns[id];
    }
    ConexionJugador* jugador = new ConexionJugador(ip);
    this->_conns[id] = jugador;
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes() {
    delete _conns[0];
    delete _conns[1];
    delete _conns[2];
    delete _conns[3];
    for(Proxy* p : _proxys){
        delete p;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

#if EJ != 6
Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* conJugador = new Proxy(_conns[id]);
    this->_proxys.push_back(conJugador);
    return  conJugador;
}
#else
Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* conJugador = new Proxy(&(this->_conns[id]));
    this->_proxys.push_back(conJugador);
    return  conJugador;
}
#endif
