#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::~Usuario() {
}

Usuario::Usuario(string nombre, string email, string urlImgPerfil, string contrasenia) {
    this->nombre = nombre;
    this->email = email;
    this->urlImgPerfil = urlImgPerfil;
    this->contrasenia = contrasenia;
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

string Usuario::getContrasenia() const {
    return contrasenia;
}

IDictionary* Usuario::getClases() const {
    return clases;
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

void Usuario::setContrasenia(string contrasenia) {
    this->contrasenia = contrasenia;
}

void Usuario::setClases(IDictionary* clases) {
    this->clases = clases;
}

IDictionary* Usuario::getDatosMensajes(int numeroClase) const {}
void Usuario::agregarClase(Clase* c) {}
IDictionary* Usuario::getDatosClasesEnVivo() const {}
Clase* Usuario::getClase(int numeroClase) const {}
DtClase* Usuario::getDatosClase(int numeroClase) const {}
IDictionary* Usuario::getDatosClasesEnVivo(string email) const {}
IDictionary* Usuario::getDatosClases(string codigoAsignatura) const {}
void Usuario::removerClases(string codigoAsignatura) {}
