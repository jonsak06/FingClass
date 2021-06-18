#include "ControllerAsignaturasUsuarios.h"

ControllerAsignaturasUsuarios& ControllerAsignaturasUsuarios::getInstance() {
    static ControllerAsignaturasUsuarios* controller = new ControllerAsignaturasUsuarios();
    return *controller;
}

//CU Alta usuario
void ControllerAsignaturasUsuarios::agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto) {}
void ControllerAsignaturasUsuarios::agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula) {}
void ControllerAsignaturasUsuarios::confirmarAltaUsuario() {}
void ControllerAsignaturasUsuarios::cancelarAltaUsuario() {}
//CU Alta asignatura
DtAsignatura ControllerAsignaturasUsuarios::agregarAsignatura(string nombreAsignatura, string codigoAsignatura, bool teorico, bool practico, bool monitoreo) {}
void ControllerAsignaturasUsuarios::confirmarAltaAsignatura() {}
void ControllerAsignaturasUsuarios::cancelarAltaAsignatura() {}
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