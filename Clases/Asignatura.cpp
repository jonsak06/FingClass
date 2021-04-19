#include "Asignatura.h"

Asignatura::Asignatura() {
}

Asignatura::~Asignatura() {
}

Asignatura::Asignatura(string codigo, string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

string Asignatura::getCodigo() const {
    return codigo;
}

string Asignatura::getNombre() const {
    return nombre;
}

void Asignatura::setCodigo(string) {
    this->codigo = codigo;
}

void Asignatura::setNombre(string) {
    this->nombre = nombre;
}
