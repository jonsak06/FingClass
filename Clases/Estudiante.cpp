#include "Estudiante.h"

Estudiante::Estudiante() {
}

Estudiante::Estudiante(string nombre, string email, string urlImgPerfil, string contrasenia, string cedula) : Usuario(nombre, email, urlImgPerfil, contrasenia) {
    this->cedula = cedula;
}

string Estudiante::getCedula() const {
    return cedula;
}

IDictionary* Estudiante::getAsignaturas() const {
    return asignaturas;
}

void Estudiante::setCedula(string) {
    this->cedula = cedula;
}

void Estudiante::setAsignaturas(IDictionary* asignaturas) {
    this->asignaturas = asignaturas;
}

DtEstudiante* Estudiante::getDatosUsuario() const {}
bool Estudiante::comprobarInscripcion(string) {}
ICollection* Estudiante::getDatosAsignaturas() const {}
void Estudiante::removerAsignatura(string) {}