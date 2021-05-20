#include "Asistencia.h"

Asistencia::Asistencia() {
}

Asistencia::~Asistencia() {
}

Asistencia::Asistencia(Estudiante* estudiante, Clase* clase) {
    this->estudiante = estudiante;
    this->clase = clase;
}

Estudiante* Asistencia::getEstudiante() const {
    return estudiante;
}

Clase* Asistencia::getClase() const {
    return clase;
}

ColFechaHora Asistencia::getFechaHoraInicio() const {
    return fechaHoraInicio;
}

ColFechaHora Asistencia::getFechaHoraFin() const {
    return fechaHoraFin;
}

void Asistencia::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void Asistencia::setClase(Clase* clase) {
    this->clase = clase;
}

void Asistencia::setFechaHoraInicio(ColFechaHora fechaHoraInicio) {
    this->fechaHoraInicio = fechaHoraInicio;
}

void Asistencia::setFechaHoraFin(ColFechaHora fechaHoraFin) {
    this->fechaHoraFin = fechaHoraFin;
}
