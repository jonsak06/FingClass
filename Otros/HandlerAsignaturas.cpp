#include "HandlerAsignaturas.h"

HandlerAsignaturas::HandlerAsignaturas()
{
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
    for (it; it->hasCurrent(); it->next())
    {
        a = dynamic_cast<Asignatura *>(it->getCurrent());
        DtAsignatura *dvAsig = a->getDatosAsignatura();
        k = new String(a->getCodigoAsignatura());
        datosAsignaturas->add(k, dvAsig);
    }
    delete it;
    return datosAsignaturas;
}

Asignatura *HandlerAsignaturas::getAsignatura(string codigoAsignatura)
{
    IKey *k = new String(codigoAsignatura);
    Asignatura *a = dynamic_cast<Asignatura *>(asignaturas->find(k));
    delete k;
    return a;
}

IDictionary *HandlerAsignaturas::getDatosAsignaturasNoInscripto(string cedula)
{
    IDictionary *datosAsignaturas = new OrderedDictionary;
    IIterator *it = asignaturas->getIterator();
    IKey *k;
    Asignatura *a;
    DtAsignatura *dvAsig;
    for (it; it->hasCurrent(); it->next())
    {
        a = dynamic_cast<Asignatura *>(it->getCurrent());
        if (!a->comprobarInscripcionEstudiante(cedula))
        {
            dvAsig = a->getDatosAsignatura();
            k = new String(a->getCodigoAsignatura());
            datosAsignaturas->add(k, dvAsig);
        }
    }
    delete it;
    return datosAsignaturas;
}

void HandlerAsignaturas::agregarAsignatura(DtAsignatura *dvAsig)
{
    IKey *k = new String(dvAsig->getCodigoAsignatura());
    Asignatura *a = new Asignatura(dvAsig->getCodigoAsignatura(), dvAsig->getNombreAsignatura(), dvAsig->tieneTeorico(), dvAsig->tienePractico(), dvAsig->tieneMonitoreo());
    asignaturas->add(k, a);
}

IDictionary *HandlerAsignaturas::getDatosAsignaturasCursando(string cedula)
{
    IDictionary *datosAsignaturas = new OrderedDictionary;
    IIterator *it = asignaturas->getIterator();
    IKey *k;
    Asignatura *a;
    DtAsignatura *dvAsig;
    for (it; it->hasCurrent(); it->next())
    {
        a = dynamic_cast<Asignatura *>(it->getCurrent());
        if (a->comprobarInscripcionEstudiante(cedula))
        {
            dvAsig = a->getDatosAsignatura();
            k = new String(a->getCodigoAsignatura());
            datosAsignaturas->add(k, dvAsig);
        }
    }
    delete it;
    return datosAsignaturas;
}

void HandlerAsignaturas::eliminarAsignatura(string codigoAsignatura)
{
    IKey *k = new String(codigoAsignatura);
    asignaturas->remove(k);
    delete k;
}

bool HandlerAsignaturas::tieneClaseDe(string codigoAsignatura, TipoClase tipoClase)
{
    IKey *k = new String(codigoAsignatura);
    Asignatura *a = dynamic_cast<Asignatura *>(asignaturas->find(k));
    delete k;
    if (tipoClase == teorico)
    {
        return a->tieneTeorico();
    }
    else if (tipoClase == practico)
    {
        return a->tienePractico();
    }
    else
    {
        return a->tieneMonitoreo();
    }
}