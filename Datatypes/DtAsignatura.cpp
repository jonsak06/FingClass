#include "DtAsignatura.h"

DtAsignatura::DtAsignatura() {
}

DtAsignatura::~DtAsignatura() {
}

DtAsignatura::DtAsignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo,
                            float tiempoTotalDictado) {
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
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
