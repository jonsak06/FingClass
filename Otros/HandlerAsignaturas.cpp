#include "HandlerAsignaturas.h"

HandlerAsignaturas::HandlerAsignaturas() {
    asignaturas = new OrderedDictionary;
}

HandlerAsignaturas &HandlerAsignaturas::getInstance()
{
    static HandlerAsignaturas *hndlrAsig = new HandlerAsignaturas();
    return *hndlrAsig;
}

IDictionary *HandlerAsignaturas::getDatosAsignaturas()
{
    IDictionary *datosAsignaturas = new OrderedDictionary;
    IIterator *it = asignaturas->getIterator();
    IKey *k;
    Asignatura *a;
    for(it; it->hasCurrent(); it->next())
    {
        a = dynamic_cast<Asignatura *>(it->getCurrent());
        DtAsignatura *dvAsig = a->getDatosAsignatura();
        k = new String(a->getCodigoAsignatura());
        datosAsignaturas->add(k, dvAsig);
    }
    delete it;
    return datosAsignaturas;
}

Asignatura HandlerAsignaturas::getAsignatura(string codigoAsignatura) { // probar agregar delete k
    IKey* k = new String(codigoAsignatura);
    Asignatura* a = dynamic_cast<Asignatura*>(asignaturas->find(k));
    delete k;
    return *a;
}

IDictionary *HandlerAsignaturas::getDatosAsignaturasNoInscripto() const {}

void HandlerAsignaturas::agregarAsignatura(DtAsignatura *dvAsig)
{
    Asignatura *a = new Asignatura(dvAsig->getCodigoAsignatura(), dvAsig->getNombreAsignatura(), dvAsig->tieneTeorico(),
                                   dvAsig->tienePractico(), dvAsig->tieneMonitoreo());
    IKey *k = new String(dvAsig->getCodigoAsignatura());

    asignaturas->add(k, a);
}

IDictionary *HandlerAsignaturas::getDatosAsignaturasCursando(string cedula) const {}
IDictionary *HandlerAsignaturas::listarClasesEnVivoHabilitado(string cedula, string codigoAsignatura) const {}
void HandlerAsignaturas::removerAsignatura(Asignatura a) {}
void HandlerAsignaturas::eliminarAsignatura(Asignatura a) {}