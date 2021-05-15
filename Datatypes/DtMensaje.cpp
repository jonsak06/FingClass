#include "DtMensaje.h"

DtMensaje::DtMensaje() {
}

DtMensaje::~DtMensaje() {
}

DtMensaje::DtMensaje(int idMensaje, string mensaje, DtFechaHora fechaHoraEnvio) {
    this->idMensaje = idMensaje;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = fechaHoraEnvio;
}

int DtMensaje::getIdMensaje() const{
    return idMensaje;
}

string DtMensaje::getMensaje() const{
    return mensaje;
}

DtFechaHora DtMensaje::getFechaHoraEnvio() const {
    return fechaHoraEnvio;
}