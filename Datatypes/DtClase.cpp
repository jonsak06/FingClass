#include "DtClase.h"

DtClase::DtClase() {
    enVivo = true;
}

DtClase::~DtClase() {
}

DtClase::DtClase(string nombre, int numero, DtFechaHora fechaHoraComienzo) {
    this->nombre = nombre;
    this->numero = numero;
    this->fechaHoraComienzo = fechaHoraComienzo;
    enVivo = true;
}

DtClase::DtClase(string nombre, int numero, DtFechaHora fechaHoraComienzo, bool enVivo, string urlGrabacion,
                DtFechaHora fechaHoraFinalizacion, float promedioTiempoAsistencia) {
    this->nombre = nombre;
    this->numero = numero;
    this->fechaHoraComienzo = fechaHoraComienzo;
    this->enVivo = enVivo;
    this->urlGrabacion = urlGrabacion;
    this->fechaHoraFinalizacion = fechaHoraFinalizacion;
    this->promedioTiempoAsistencia = promedioTiempoAsistencia;
}

string DtClase::getNombre() const {
    return nombre;
}

int DtClase::getNumero() const {
    return numero;
}

DtFechaHora DtClase::getFechaHoraComienzo() const {
    return fechaHoraComienzo;
}

bool DtClase::estaEnVivo() const {
    return enVivo;
}

string DtClase::getUrlGrabacion() const {
    return urlGrabacion;
}

DtFechaHora DtClase::getFechaHoraFinalizacion() const {
    return fechaHoraFinalizacion;
}

float DtClase::getPromedioTiempoAsistencia() const {
    return promedioTiempoAsistencia;
}