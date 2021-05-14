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

void Asistencia::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void Asistencia::setClase(Clase* clase) {
    this->clase = clase;
}