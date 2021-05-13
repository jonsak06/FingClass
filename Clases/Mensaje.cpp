#include "Mensaje.h"

Mensaje::Mensaje() {
}

Mensaje::~Mensaje() {
}

Mensaje::Mensaje(int idMensaje, string mensaje, DtFechaHora fechaHoraEnvio) {
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

DtFechaHora Mensaje::getFechaHoraEnvio() const {
    return fechaHoraEnvio;
}

void Mensaje::setIdMensaje(int idMensaje) {
    this->idMensaje = idMensaje;
}

void Mensaje::setMensaje(string mensaje) {
    this->mensaje = mensaje;
}

void Mensaje::setFechaHoraEnvio(DtFechaHora fechaHoraEnvio) {
    this->fechaHoraEnvio = fechaHoraEnvio;
}