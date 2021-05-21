#include "Asignatura.h"

Asignatura::Asignatura() {
}

Asignatura::~Asignatura() {
}

Asignatura::Asignatura(string codigoAsignatura, string nombreAsignatura) {
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
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

vector<Docente> Asignatura::getDocentesAsignados() const {
    return docentesAsignados;
}

vector<Estudiante> Asignatura::getEstudiantesInscriptos() const {
    return estudiantesInscriptos;
}

vector<Clase*> Asignatura::getClases() const {
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

void Asignatura::setDocentesAsignados(vector<Docente> docentesAsignados) {
    this->docentesAsignados = docentesAsignados;
}

void Asignatura::setEstudiantesInscriptos(vector<Estudiante> estudiantesInscriptos) {
    this->estudiantesInscriptos = estudiantesInscriptos;
}

void Asignatura::setClases(vector<Clase*> clases) {
    this->clases = clases;
}
