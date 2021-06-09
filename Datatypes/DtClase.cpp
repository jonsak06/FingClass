#include "DtClase.h"

DtClase::DtClase() {
    enVivo = true;
}

DtClase::~DtClase() {
}

DtClase::DtClase(string nombre, int numero, FechaHora fechaHoraComienzo) {
    this->nombre = nombre;
    this->numero = numero;
    this->fechaHoraComienzo = fechaHoraComienzo;
    enVivo = true;
}

DtClase::DtClase(string nombre, int numero, FechaHora fechaHoraComienzo, bool enVivo, string urlGrabacion,
                FechaHora fechaHoraFinalizacion, float promedioTiempoAsistenciaEnDiferido) {
    this->nombre = nombre;
    this->numero = numero;
    this->fechaHoraComienzo = fechaHoraComienzo;
    this->enVivo = enVivo;
    this->urlGrabacion = urlGrabacion;
    this->fechaHoraFinalizacion = fechaHoraFinalizacion;
    this->promedioTiempoAsistenciaEnDiferido = promedioTiempoAsistenciaEnDiferido;
}

string DtClase::getNombre() const {
    return nombre;
}

int DtClase::getNumero() const {
    return numero;
}

FechaHora DtClase::getFechaHoraComienzo() const {
    return fechaHoraComienzo;
}

bool DtClase::estaEnVivo() const {
    return enVivo;
}

string DtClase::getUrlGrabacion() const {
    return urlGrabacion;
}

FechaHora DtClase::getFechaHoraFinalizacion() const {
    return fechaHoraFinalizacion;
}

float DtClase::getPromedioTiempoAsistenciaEnDiferido() const {
    return promedioTiempoAsistenciaEnDiferido;
}