#include "DtEstudiante.h"

DtEstudiante::DtEstudiante() {
}

DtEstudiante::DtEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula) : DtUsuario(nombre, email, contrasenia, urlImgPerfil) {
    this->cedula = cedula;
}

DtEstudiante::DtEstudiante(string nombre, string cedula) : DtUsuario(nombre) {
    this->cedula = cedula;
}

string DtEstudiante::getCedula() const {
    return cedula;
}
