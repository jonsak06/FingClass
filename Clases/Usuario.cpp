#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::~Usuario() {
}

Usuario::Usuario(string nombre, string email, string urlImgPerfil) {
    this->nombre = nombre;
    this->email = email;
    this->urlImgPerfil = urlImgPerfil;
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getEmail() const {
    return email;
}

string Usuario::getUrlImgPerfil() const {
    return urlImgPerfil;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

void Usuario::setEmail(string email) {
    this->email = email;
}

void Usuario::setUrlImgPerfil(string urlImgPerfil) {
    this->urlImgPerfil = urlImgPerfil;
}
