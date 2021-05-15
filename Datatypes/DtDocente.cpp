#include "DtDocente.h"

DtDocente::DtDocente() {
}

DtDocente::DtDocente(string nombre, string email, string urlImgPerfil, string contrasenia, string nombreInstituto)
                     : DtUsuario(nombre, email, urlImgPerfil, contrasenia) {
    this->nombreInstituto = nombreInstituto;
}

DtDocente::DtDocente(string nombre, string email, string urlImgPerfil, string contrasenia, string nombreInstituto, 
                    TipoClase rolDictado) : DtUsuario(nombre, email, urlImgPerfil, contrasenia) {
    this->nombreInstituto = nombreInstituto;
    this->rolDictado = rolDictado;
}

string DtDocente::getNombreInstituto() const {
    return nombreInstituto;
}
