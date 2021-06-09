#include "Mensaje.h"

Mensaje::Mensaje() {
}

Mensaje::~Mensaje() {
}

Mensaje::Mensaje(int idMensaje, string mensaje, FechaHora fechaHoraEnvio) {
    this->idMensaje = idMensaje;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = fechaHoraEnvio;
}

int Mensaje::getIdMensaje() const{
    return idMensaje;
}

string Mensaje::getMensaje() const{
    return mensaje;
}

FechaHora Mensaje::getFechaHoraEnvio() const {
    return fechaHoraEnvio;
}

Usuario* Mensaje::getUsuario() const {
    return usuario;
}

void Mensaje::setIdMensaje(int idMensaje) {
    this->idMensaje = idMensaje;
}

void Mensaje::setMensaje(string mensaje) {
    this->mensaje = mensaje;
}

void Mensaje::setFechaHoraEnvio(FechaHora fechaHoraEnvio) {
    this->fechaHoraEnvio = fechaHoraEnvio;
}

void Mensaje::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

DtMensaje Mensaje::getDatosMensaje() const {}