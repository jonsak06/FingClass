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

vector<DtFechaHora> Asistencia::getFechaHoraInicio() const {
    return fechaHoraInicio;
}

vector<DtFechaHora> Asistencia::getFechaHoraFin() const {
    return fechaHoraFin;
}

void Asistencia::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void Asistencia::setClase(Clase* clase) {
    this->clase = clase;
}

void Asistencia::setFechaHoraInicio(vector<DtFechaHora> fechaHoraInicio) {
    this->fechaHoraInicio = fechaHoraInicio;
}

void Asistencia::setFechaHoraFin(vector<DtFechaHora> fechaHoraFin) {
    this->fechaHoraFin = fechaHoraFin;
}
