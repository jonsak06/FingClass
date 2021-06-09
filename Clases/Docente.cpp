#include "Docente.h"

Docente::Docente() {
}

Docente::Docente(string nombre, string email, string urlImgPerfil, string contrasenia, string nombreInstituto) : Usuario(nombre, email, urlImgPerfil, contrasenia) {
    this->nombreInstituto = nombreInstituto;
}

string Docente::getNombreInstituto() const {
    return nombreInstituto;
}

vector<Clase*> Docente::getClasesIniciadas() const {
    return clasesIniciadas;
}

vector<Asignacion> Docente::getAsignaciones() const {
    return asignaciones;
}

void Docente::setNombreInstituto(string) {
    this->nombreInstituto = nombreInstituto;
}

void Docente::setClasesIniciadas(vector<Clase*> clasesIniciadas) {
    this->clasesIniciadas = clasesIniciadas;
}

void Docente::setAsignaciones(vector<Asignacion> asignaciones) {
    this->asignaciones = asignaciones;
}

DtDocente Docente::getDatosDocente() const {}
bool Docente::comprobarAsignacion(string) const {}
void Docente::asignarAsignatura(Asignatura, TipoClase) {}
vector<DtAsignatura> Docente::getDatosAsignaturas() const {}
TipoClase Docente::getRolDictado(string) const {}
void Docente::agregarClase(Clase*) {}
vector<Clase*> Docente::getDatosClasesEnVivo(string) const {}
DtClase* Docente::getDatosClase() const {}
void Docente::finalizarClase(int) {}
vector<DtClase*> Docente::getDatosClases(string) const {}
void Docente::removerClasesYAsignacion(string) {}