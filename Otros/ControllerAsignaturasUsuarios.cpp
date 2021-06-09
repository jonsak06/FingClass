#include "ControllerAsignaturasUsuarios.h"

ControllerAsignaturasUsuarios::ControllerAsignaturasUsuarios() {}
ControllerAsignaturasUsuarios::~ControllerAsignaturasUsuarios() {}
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
vector <DtAsignatura> ControllerAsignaturasUsuarios::listarAsignaturas() {}
vector <DtDocente> ControllerAsignaturasUsuarios::listarDocentesSinAsignar(string codigoAsignatura) {}
void ControllerAsignaturasUsuarios::seleccionarDocente(string email, TipoClase rolDictado) {}
void ControllerAsignaturasUsuarios::confirmarAsignacion() {}
void ControllerAsignaturasUsuarios::cancelarAsignacion() {}
//CU inscripcion a asignaturas
vector <DtAsignatura> ControllerAsignaturasUsuarios::listarAsignaturasNoInscripto(string cedula) {}
void ControllerAsignaturasUsuarios::seleccionarAsignatura(string codigoAsignatura) {}
void ControllerAsignaturasUsuarios::confirmarInscripcion() {}
void ControllerAsignaturasUsuarios::cancelarInscripcion() {}
//CU eliminar asignatura
void ControllerAsignaturasUsuarios::confirmarEliminacion() {}
void ControllerAsignaturasUsuarios::cancelarEliminacion() {}