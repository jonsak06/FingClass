#include "Clase.h"

Clase::Clase() {
}

Clase::~Clase() {
}

Clase::Clase(string nombre, int numero, DtFechaHora fechaHoraComienzo) {
    this->nombre = nombre;
    this->numero = numero;
    this->fechaHoraComienzo = fechaHoraComienzo;
}

string Clase::getNombre() const {
    return nombre;
}

int Clase::getNumero() const {
    return numero;
}

DtFechaHora Clase::getFechaHoraComienzo() const {
    return fechaHoraComienzo;
}

bool Clase::getEnVivo() const {
    return enVivo;
}

string Clase::getUrlGrabacion() const {
    return urlGrabacion;
}

DtFechaHora Clase::getFechaHoraFinalizacion() const {
    return fechaHoraFinalizacion;
}

void Clase::setNombre(string nombre) {
    this->nombre = nombre;
}

void Clase::setNumero(int numero) {
    this->numero = numero;
}

void Clase::setFechaHoraComienzo(DtFechaHora fechaHoraComienzo) {
    this->fechaHoraComienzo = fechaHoraComienzo;
}

void Clase::setEnVivo(bool enVivo) {
    this->enVivo = enVivo;
}

void Clase::setUrlGrabacion(string urlGrabacion) {
    this->urlGrabacion = urlGrabacion;
}

void Clase::setFechaHoraFinalizacion(DtFechaHora) {
    this->fechaHoraFinalizacion = fechaHoraFinalizacion;
}
