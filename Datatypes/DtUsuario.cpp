#include "DtUsuario.h"

DtUsuario::DtUsuario() {
}

DtUsuario::~DtUsuario() {
}

DtUsuario::DtUsuario(string nombre, string email, string contrasenia, string urlImgPerfil) {
    this->nombre = nombre;
    this->email = email;
    this->contrasenia = contrasenia;
    this->urlImgPerfil = urlImgPerfil;
}

DtUsuario::DtUsuario(string nombre, string email) {
    this->nombre = nombre;
    this->email = email;
}

DtUsuario::DtUsuario(string nombre) {
    this->nombre = nombre;
}

string DtUsuario::getNombre() const {
    return nombre;
}

string DtUsuario::getEmail() const {
    return email;
}

string DtUsuario::getContrasenia() const {
    return contrasenia;
}

string DtUsuario::getUrlImgPerfil() const {
    return urlImgPerfil;
}
