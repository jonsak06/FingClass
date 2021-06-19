#include "HandlerUsuarios.h"

HandlerUsuarios& HandlerUsuarios::getInstance() {
    static HandlerUsuarios* hndlrUsr = new HandlerUsuarios();
    return *hndlrUsr;
}

IDictionary* HandlerUsuarios::getDatosDocentesSinAsignar(string codigoAsignatura) const {}
Docente HandlerUsuarios::getDocente(string email) const {} 
Estudiante HandlerUsuarios::getEstudiante(string cedula) const {}
Usuario* HandlerUsuarios::getUsuario(string email) const {}

void HandlerUsuarios::crearUsuario(DtUsuario* dvUsr) {
    Usuario* u;
    IKey* k;
    if (dynamic_cast<DtEstudiante*>(dvUsr) == nullptr)
    {
        u = new Docente(dvUsr->getNombre(), dvUsr->getEmail(), dvUsr->getUrlImgPerfil(), dvUsr->getContrasenia(), dvUsr->getNombreInstituto());
        k = new String(dvUsr->getEmail());
    } else {
        u = new Estudiante(dvUsr->getNombre(), dvUsr->getEmail(), dvUsr->getUrlImgPerfil(), dvUsr->getContrasenia(), dvUsr->getCedula());
        k = new String(dvUsr->getCedula());
    }
    usuarios->add(k,u);
}

void HandlerUsuarios::removerClasesYAsignacionDocentes(string codigoAsignatura) {}
void HandlerUsuarios::removerClasesEstudiantes(string codigoAsignatura) {}