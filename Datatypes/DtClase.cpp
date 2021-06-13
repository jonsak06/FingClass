#include "DtClase.h"

DtClase::DtClase() {
    enVivo = true;
}

DtClase::~DtClase() {
}

DtClase::DtClase(int numeroClase, string nombreClase) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
}

DtClase::DtClase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
    this->fechaHoraComienzo = fechaHoraComienzo;
    this->codigoAsignatura = codigoAsignatura;
}

DtClase::DtClase(int numeroClase, string nombreClase, ICollection* docentes) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
    this->docentes = docentes;
}

DtClase::DtClase(int numeroClase, string nombreClase, float promedioTiempoAsistencia) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
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

float DtClase::getPromedioTiempoAsistencia() const {
    return promedioTiempoAsistencia;
}

string DtClase::getCodigoAsignatura() const {
    return codigoAsignatura;
}

ICollection* DtClase::getDocentes() const {
    return docentes;
}