#include "Docente.h"

Docente::Docente() {
}

Docente::Docente(string nombre, string email, string urlImgPerfil, string contrasenia, string nombreInstituto) : Usuario(nombre, email, urlImgPerfil, contrasenia) {
    this->nombreInstituto = nombreInstituto;
}


string Docente::getNombreInstituto() const {
    return nombreInstituto;
}

void Docente::setNombreInstituto(string) {
    this->nombreInstituto = nombreInstituto;
}
