#include "HandlerAsignaturas.h"

HandlerAsignaturas& HandlerAsignaturas::getInstance() {
    static HandlerAsignaturas* hndlrAsig = new HandlerAsignaturas();
    return *hndlrAsig;
}

ICollection* HandlerAsignaturas::getDatosAsignaturas() const {}
Asignatura HandlerAsignaturas::getAsignatura(string codigoAsignatura) {}
ICollection* HandlerAsignaturas::getDatosAsignaturasNoInscripto() const {}
void HandlerAsignaturas::agregarAsignatura(DtAsignatura dvAsig) {}
ICollection* HandlerAsignaturas::getDatosAsignaturasCursando(string cedula) const {}
ICollection* HandlerAsignaturas::listarClasesEnVivoHabilitado(string cedula, string codigoAsignatura) const {}
void HandlerAsignaturas::removerAsignatura(Asignatura a) {}
void HandlerAsignaturas::eliminarAsignatura(Asignatura a) {}