#include "DtClase.h"

DtClase::DtClase() {
    promedioTiempoAsistencia = 0;
}

DtClase::~DtClase() {
}

DtClase::DtClase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
    this->fechaHoraComienzo = fechaHoraComienzo;
    this->codigoAsignatura = codigoAsignatura;
    promedioTiempoAsistencia = 0;
}

DtClase::DtClase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string nombreDocente, double promedioTiempoAsistencia) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
    this->fechaHoraComienzo = fechaHoraComienzo;
    this->nombreDocente = nombreDocente;
    this->promedioTiempoAsistencia = promedioTiempoAsistencia;
}

string DtClase::getNombreClase() const {
    return nombreClase;
}

int DtClase::getNumeroClase() const {
    return numeroClase;
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

double DtClase::getPromedioTiempoAsistencia() const {
    return promedioTiempoAsistencia;
}

string DtClase::getCodigoAsignatura() const {
    return codigoAsignatura;
}

string DtClase::getNombreDocente() const {
    return nombreDocente;
}

ostream& operator<<(ostream& salida, DtClase* u) {
    u->mostrarInfo(salida);
    return salida;
}