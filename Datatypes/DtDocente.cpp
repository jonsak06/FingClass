#include "DtDocente.h"

DtDocente::DtDocente() {
}

DtDocente::DtDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto)
                    : DtUsuario(nombre, email, contrasenia, urlImgPerfil) {
    this->nombreInstituto = nombreInstituto;
}

DtDocente::DtDocente(string nombre, string email) : DtUsuario(nombre, email) {
    
}

string DtDocente::getNombreInstituto() const {
    return nombreInstituto;
}
