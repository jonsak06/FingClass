#include "HandlerAsignaturas.h"

HandlerAsignaturas& HandlerAsignaturas::getInstance() {
    static HandlerAsignaturas* hndlrAsig = new HandlerAsignaturas();
    return *hndlrAsig;
}

IDictionary* HandlerAsignaturas::getDatosAsignaturas() const {}
Asignatura HandlerAsignaturas::getAsignatura(string codigoAsignatura) {}
IDictionary* HandlerAsignaturas::getDatosAsignaturasNoInscripto() const {}
void HandlerAsignaturas::agregarAsignatura(DtAsignatura dvAsig) {}
IDictionary* HandlerAsignaturas::getDatosAsignaturasCursando(string cedula) const {}
IDictionary* HandlerAsignaturas::listarClasesEnVivoHabilitado(string cedula, string codigoAsignatura) const {}
void HandlerAsignaturas::removerAsignatura(Asignatura a) {}
void HandlerAsignaturas::eliminarAsignatura(Asignatura a) {}