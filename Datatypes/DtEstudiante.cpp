#include "DtEstudiante.h"

DtEstudiante::DtEstudiante() {
}

DtEstudiante::DtEstudiante(string nombre, string email, string urlImgPerfil, string contrasenia, string cedula) : DtUsuario(nombre, email, urlImgPerfil, contrasenia) {
    this->cedula = cedula;
}

string DtEstudiante::getCedula() const {
    return cedula;
}
