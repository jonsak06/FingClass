#include "DtEstudiante.h"

DtEstudiante::DtEstudiante() {
}

DtEstudiante::DtEstudiante(string nombre, string email, string urlImgPerfil, string cedula) : DtUsuario(nombre, email, urlImgPerfil) {
    this->cedula = cedula;
}

string DtEstudiante::getCedula() const {
    return cedula;
}
