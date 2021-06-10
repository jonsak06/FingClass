#include "Docente.h"

Docente::Docente() {
}

Docente::Docente(string nombre, string email, string urlImgPerfil, string contrasenia, string nombreInstituto) : Usuario(nombre, email, urlImgPerfil, contrasenia) {
    this->nombreInstituto = nombreInstituto;
}

string Docente::getNombreInstituto() const {
    return nombreInstituto;
}

IDictionary* Docente::getClasesIniciadas() const {
    return clasesIniciadas;
}

ICollection* Docente::getAsignaciones() const {
    return asignaciones;
}

void Docente::setNombreInstituto(string) {
    this->nombreInstituto = nombreInstituto;
}

void Docente::setClasesIniciadas(IDictionary* clasesIniciadas) {
    this->clasesIniciadas = clasesIniciadas;
}

void Docente::setAsignaciones(ICollection* asignaciones) {
    this->asignaciones = asignaciones;
}

DtDocente Docente::getDatosDocente() const {}
bool Docente::comprobarAsignacion(string) const {}
void Docente::asignarAsignatura(Asignatura, TipoClase) {}
ICollection* Docente::getDatosAsignaturas() const {}
TipoClase Docente::getRolDictado(string) const {}
void Docente::agregarClase(Clase*) {}
IDictionary* Docente::getDatosClasesEnVivo(string) const {}
DtClase* Docente::getDatosClase() const {}
void Docente::finalizarClase(int) {}
ICollection* Docente::getDatosClases(string) const {}
void Docente::removerClasesYAsignacion(string) {}