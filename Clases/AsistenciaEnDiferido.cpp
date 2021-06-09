#include "AsistenciaEnDiferido.h"

AsistenciaEnDiferido::AsistenciaEnDiferido() {
}

AsistenciaEnDiferido::~AsistenciaEnDiferido() {
}

AsistenciaEnDiferido::AsistenciaEnDiferido(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

Estudiante* AsistenciaEnDiferido::getEstudiante() const {
    return estudiante;
}

vector<FechaHora> AsistenciaEnDiferido::getFechaHoraInicio() const {
    return fechaHoraInicio;
}

vector<FechaHora> AsistenciaEnDiferido::getFechaHoraFin() const {
    return fechaHoraFin;
}

void AsistenciaEnDiferido::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void AsistenciaEnDiferido::setFechaHoraInicio(vector<FechaHora> fechaHoraInicio) {
    this->fechaHoraInicio = fechaHoraInicio;
}

void AsistenciaEnDiferido::setFechaHoraFin(vector<FechaHora> fechaHoraFin) {
    this->fechaHoraFin = fechaHoraFin;
}

bool AsistenciaEnDiferido::comprobarAsistencia(string cedula) {}