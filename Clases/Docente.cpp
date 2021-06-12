#include "Docente.h"

Docente::Docente() {
}

Docente::Docente(string nombre, string email, string urlImgPerfil, string contrasenia, string nombreInstituto) : Usuario(nombre, email, urlImgPerfil, contrasenia) {
    this->nombreInstituto = nombreInstituto;
}

string Docente::getNombreInstituto() const {
    return nombreInstituto;
}

ICollection* Docente::getAsignaciones() const {
    return asignaciones;
}

void Docente::setNombreInstituto(string) {
    this->nombreInstituto = nombreInstituto;
}

void Docente::setAsignaciones(ICollection* asignaciones) {
    this->asignaciones = asignaciones;
}

DtDocente* Docente::getDatosUsuario() const {}
bool Docente::comprobarAsignacion(string codigoAsignatura) const {}
void Docente::asignarAsignatura(Asignatura a, TipoClase rolDictado) {}
ICollection* Docente::getDatosAsignaturas() const {}
TipoClase Docente::getRolDictado(string codigoAsignatura) const {}
void Docente::finalizarClase(int numeroClase) {}
void Docente::removerAsignacion(string codigoAsignatura) {}