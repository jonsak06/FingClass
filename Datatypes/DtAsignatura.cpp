#include "DtAsignatura.h"

DtAsignatura::DtAsignatura() {
}

DtAsignatura::~DtAsignatura() {
}

DtAsignatura::DtAsignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo) {
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
}

DtAsignatura::DtAsignatura(string codigoAsignatura, string nombreAsignatura) {
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
}

DtAsignatura::DtAsignatura(string codigoAsignatura, string nombreAsignatura, float tiempoTotalDictado) {
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->tiempoTotalDictado = tiempoTotalDictado;
}

string DtAsignatura::getCodigoAsignatura() const {
    return codigoAsignatura;
}

string DtAsignatura::getNombreAsignatura() const {
    return nombreAsignatura;
}

bool DtAsignatura::tieneTeorico() const {
    return teorico;
}

bool DtAsignatura::tienePractico() const {
    return practico;
}

bool DtAsignatura::tieneMonitoreo() const {
    return monitoreo;
}

float DtAsignatura::getTiempoTotalDictado() const {
    return tiempoTotalDictado;
}
