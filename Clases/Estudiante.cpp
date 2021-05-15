#include "Estudiante.h"

Estudiante::Estudiante() {
}

Estudiante::Estudiante(string nombre, string email, string urlImgPerfil, string contrasenia, string cedula) : Usuario(nombre, email, urlImgPerfil, contrasenia) {
    this->cedula = cedula;
}

string Estudiante::getCedula() const {
    return cedula;
}

void Estudiante::setCedula(string) {
    this->cedula = cedula;
}
