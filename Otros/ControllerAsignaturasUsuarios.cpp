#include "ControllerAsignaturasUsuarios.h"

ControllerAsignaturasUsuarios& ControllerAsignaturasUsuarios::getInstance() {
    static ControllerAsignaturasUsuarios* controller = new ControllerAsignaturasUsuarios();
    return *controller;
}

//CU Alta usuario
void ControllerAsignaturasUsuarios::agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto) {
    dvUsr = new DtDocente(nombre, email, contrasenia, urlImgPerfil, nombreInstituto);
}

void ControllerAsignaturasUsuarios::agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula) {
    dvUsr = new DtEstudiante(nombre, email, contrasenia, urlImgPerfil, cedula);
}

void ControllerAsignaturasUsuarios::confirmarAltaUsuario() {
    HandlerUsuarios& hndlrUsr = HandlerUsuarios::getInstance();
    hndlrUsr.agregarUsuario(dvUsr);
    delete dvUsr;
}

void ControllerAsignaturasUsuarios::cancelarAltaUsuario() {
    delete dvUsr;
}

//CU Alta asignatura
DtAsignatura* ControllerAsignaturasUsuarios::agregarAsignatura(string nombreAsignatura, string codigoAsignatura, bool teorico, bool practico, bool monitoreo) {
    dvAsig = new DtAsignatura(nombreAsignatura, codigoAsignatura, teorico, practico, monitoreo);
    return dvAsig;
}
void ControllerAsignaturasUsuarios::confirmarAltaAsignatura() {
    HandlerAsignaturas& hndlrAsig = HandlerAsignaturas::getInstance();
    hndlrAsig.agregarAsignatura(dvAsig);
    delete dvAsig;
}
void ControllerAsignaturasUsuarios::cancelarAltaAsignatura() {
    delete dvAsig;
}

//CU asignacion docente a asignatura
IDictionary* ControllerAsignaturasUsuarios::listarAsignaturas() {}
IDictionary* ControllerAsignaturasUsuarios::listarDocentesSinAsignar(string codigoAsignatura) {}
void ControllerAsignaturasUsuarios::seleccionarDocente(string email, TipoClase rolDictado) {}
void ControllerAsignaturasUsuarios::confirmarAsignacion() {}
void ControllerAsignaturasUsuarios::cancelarAsignacion() {}
//CU inscripcion a asignaturas
IDictionary* ControllerAsignaturasUsuarios::listarAsignaturasNoInscripto(string cedula) {}
void ControllerAsignaturasUsuarios::seleccionarAsignatura(string codigoAsignatura) {}
void ControllerAsignaturasUsuarios::confirmarInscripcion() {}
void ControllerAsignaturasUsuarios::cancelarInscripcion() {}
//CU eliminar asignatura
void ControllerAsignaturasUsuarios::confirmarEliminacion() {}
void ControllerAsignaturasUsuarios::cancelarEliminacion() {}

void ControllerAsignaturasUsuarios::cargarDatosAsigUsr() {}