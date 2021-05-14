#include "Asignacion.h"

Asignacion::Asignacion() {
}

Asignacion::~Asignacion() {
}

Asignacion::Asignacion(Docente* docente, Asignatura* asignatura, TipoClase rolDictado) {
    this->docente = docente;
    this->asignatura = asignatura;
    this->rolDictado = rolDictado;
}

TipoClase Asignacion::getRolDictado() const {
    return rolDictado;
}

Docente* Asignacion::getDocente() const {
    return docente;
}

Asignatura* Asignacion::getAsignatura() const {
    return asignatura;
}

void Asignacion::setRolDictado(TipoClase rolDictado) {
    this->rolDictado = rolDictado;
}

void Asignacion::setDocente(Docente* docente) {
    this->docente = docente;
}

void Asignacion::setAsignatura(Asignatura* asignatura) {
    this->asignatura = asignatura;
}