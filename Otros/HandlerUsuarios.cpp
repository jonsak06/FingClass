#include "HandlerUsuarios.h"

HandlerUsuarios& HandlerUsuarios::getInstance() {
    static HandlerUsuarios* hndlrUsr = new HandlerUsuarios();
    return *hndlrUsr;
}

ICollection* HandlerUsuarios::getDatosDocentesSinAsignar(string codigoAsignatura) const {}
Docente HandlerUsuarios::getDocente(string email) const {} 
Estudiante HandlerUsuarios::getEstudiante(string cedula) const {}
Usuario* HandlerUsuarios::getUsuario(string email) const {}
void HandlerUsuarios::crearUsuario(DtUsuario* dvUsr) {}
void HandlerUsuarios::removerClasesYAsignacionDocentes(string codigoAsignatura) {}
void HandlerUsuarios::removerClasesEstudiantes(string codigoAsignatura) {}