#include "Asignatura.h"

Asignatura::Asignatura() {
}

Asignatura::~Asignatura() {
}

Asignatura::Asignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo) {
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
}

string Asignatura::getCodigoAsignatura() const {
    return codigoAsignatura;
}

string Asignatura::getNombreAsignatura() const {
    return nombreAsignatura;
}

bool Asignatura::tieneTeorico() const {
    return teorico;
}

bool Asignatura::tienePractico() const {
    return practico;
}

bool Asignatura::tieneMonitoreo() const {
    return monitoreo;
}

float Asignatura::getTiempoTotalDictado() const {
    return tiempoTotalDictado;
}

IDictionary* Asignatura::getEstudiantesInscriptos() const {
    return estudiantesInscriptos;
}

IDictionary* Asignatura::getClases() const {
    return clases;
}

void Asignatura::setCodigoAsignatura(string) {
    this->codigoAsignatura = codigoAsignatura;
}

void Asignatura::setNombreAsignatura(string) {
    this->nombreAsignatura = nombreAsignatura;
}

void Asignatura::setTeorico(bool teorico) {
    this->teorico = teorico;
}

void Asignatura::setPractico(bool practico) {
    this->practico = practico;
}

void Asignatura::setMonitoreo(bool monitoreo) {
    this->monitoreo = monitoreo;
}

void Asignatura::setTiempoTotalDictado(float tiempoTotalDictado) {
    this->tiempoTotalDictado = tiempoTotalDictado;
}

void Asignatura::setEstudiantesInscriptos(IDictionary* estudiantesInscriptos) {
    this->estudiantesInscriptos = estudiantesInscriptos;
}

void Asignatura::setClases(IDictionary* clases) {
    this->clases = clases;
}

DtAsignatura Asignatura::getDatosAsignatura() const {}
Clase* Asignatura::iniciarClase(DtClase*, IDictionary*) const {} //ver si no da problema el const
IDictionary* Asignatura::getDatosClasesEnDiferido() const {}
IDictionary* Asignatura::reproducirClase(int, Estudiante) const {}
void Asignatura::eliminarClases() {}
Clase* Asignatura::getClase(int numeroClase) const {}
bool Asignatura::comprobarInscripcionEstudiante(string cedula) const {}
void Asignatura::inscribirEstudiante(Estudiante e) {}
IDictionary* Asignatura::getDatosEstudiantesInscriptos() const {}
IDictionary* Asignatura::getDatosClasesEnVivoHabilitado(string cedula) const {}
DtClase* Asignatura::getDatosClase(int numeroClase) const {} 
Clase* Asignatura::asistirClase(int numeroClase, Estudiante e) const {}