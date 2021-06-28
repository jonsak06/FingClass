#include "AsistenciaEnDiferido.h"

AsistenciaEnDiferido::AsistenciaEnDiferido() {
}

AsistenciaEnDiferido::~AsistenciaEnDiferido() {
    delete fechaHoraFin, fechaHoraInicio;
}

AsistenciaEnDiferido::AsistenciaEnDiferido(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

Estudiante* AsistenciaEnDiferido::getEstudiante() const {
    return estudiante;
}

ICollection* AsistenciaEnDiferido::getFechaHoraInicio() const {
    return fechaHoraInicio;
}

ICollection* AsistenciaEnDiferido::getFechaHoraFin() const {
    return fechaHoraFin;
}

void AsistenciaEnDiferido::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void AsistenciaEnDiferido::setFechaHoraInicio(ICollection* fechaHoraInicio) {
    this->fechaHoraInicio = fechaHoraInicio;
}

void AsistenciaEnDiferido::setFechaHoraFin(ICollection* fechaHoraFin) {
    this->fechaHoraFin = fechaHoraFin;
}

bool AsistenciaEnDiferido::comprobarAsistencia(string cedula) const {}