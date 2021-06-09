#include "DtDocente.h"

DtDocente::DtDocente() {
}

DtDocente::DtDocente(string nombre, string email, string urlImgPerfil, string nombreInstituto)
                     : DtUsuario(nombre, email, urlImgPerfil) {
    this->nombreInstituto = nombreInstituto;
}

DtDocente::DtDocente(string nombre, string email, string urlImgPerfil, string nombreInstituto, 
                    TipoClase rolDictado) : DtUsuario(nombre, email, urlImgPerfil) {
    this->nombreInstituto = nombreInstituto;
    this->rolDictado = rolDictado;
}

string DtDocente::getNombreInstituto() const {
    return nombreInstituto;
}
