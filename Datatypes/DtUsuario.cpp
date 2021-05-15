#include "DtUsuario.h"

DtUsuario::DtUsuario() {
}

DtUsuario::~DtUsuario() {
}

DtUsuario::DtUsuario(string nombre, string email, string urlImgPerfil, string contrasenia) {
    this->nombre = nombre;
    this->email = email;
    this->urlImgPerfil = urlImgPerfil;
    this->contrasenia = contrasenia;
}

string DtUsuario::getNombre() const {
    return nombre;
}

string DtUsuario::getEmail() const {
    return email;
}

string DtUsuario::getUrlImgPerfil() const {
    return urlImgPerfil;
}

string DtUsuario::getContrasenia() const {
    return contrasenia;
}
