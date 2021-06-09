#include "DtUsuario.h"

DtUsuario::DtUsuario() {
}

DtUsuario::~DtUsuario() {
}

DtUsuario::DtUsuario(string nombre, string email, string urlImgPerfil) {
    this->nombre = nombre;
    this->email = email;
    this->urlImgPerfil = urlImgPerfil;
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
