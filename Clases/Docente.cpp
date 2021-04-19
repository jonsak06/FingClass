#include "Docente.h"

Docente::Docente() {
}

Docente::~Docente() {
}

Docente::Docente(string nombre, string email, string urlImgPerfil, string nombreInstituto) : Usuario(nombre, email, urlImgPerfil) {
    this->nombreInstituto = nombreInstituto;
}


string Docente::getNombreInstituto() const {
    return nombreInstituto;
}

void Docente::setNombreInstituto(string) {
    this->nombreInstituto = nombreInstituto;
}
