#include "AsistenciaEnVivo.h"

AsistenciaEnVivo::AsistenciaEnVivo() {
}

AsistenciaEnVivo::~AsistenciaEnVivo() {
}

AsistenciaEnVivo::AsistenciaEnVivo(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

Estudiante* AsistenciaEnVivo::getEstudiante() const {
    return estudiante;
}

FechaHora AsistenciaEnVivo::getFechaHoraInicio() const {
    return fechaHoraInicio;
}

FechaHora* AsistenciaEnVivo::getFechaHoraFin() const {
    return fechaHoraFin;
}

void AsistenciaEnVivo::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void AsistenciaEnVivo::setFechaHoraInicio(FechaHora fechaHoraInicio) {
    this->fechaHoraInicio = fechaHoraInicio;
}

void AsistenciaEnVivo::setFechaHoraFin(FechaHora* fechaHoraFin) {
    this->fechaHoraFin = fechaHoraFin;
}

bool AsistenciaEnVivo::comprobarAsistencia(string cedula) const {}
