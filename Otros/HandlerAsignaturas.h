#ifndef HANDLERASIGNATURAS_H
#define HANDLERASIGNATURAS_H

#include "../Clases/Asignatura.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/String.h"
#include "../Otros/TipoClase.h"

class HandlerAsignaturas
{
private:
    HandlerAsignaturas();
    HandlerAsignaturas(const HandlerAsignaturas&) = delete;
    HandlerAsignaturas& operator=(const HandlerAsignaturas&) = delete;
    HandlerAsignaturas(HandlerAsignaturas&&) = delete;
    HandlerAsignaturas& operator=(HandlerAsignaturas&&) = delete;
    IDictionary* asignaturas;
public:
    static HandlerAsignaturas& getInstance();

    //operaciones DCD
    IDictionary* getDatosAsignaturas();
    IDictionary* getDatosAsignaturasConTiempoDictado();
    Asignatura getAsignatura(string codigoAsignatura);
    IDictionary* getDatosAsignaturasNoInscripto(string cedula);
    void agregarAsignatura(DtAsignatura* dvAsig);
    IDictionary* getDatosAsignaturasCursando(string cedula);
    IDictionary* listarClasesEnVivoHabilitado(string cedula, string codigoAsignatura);
    void eliminarAsignatura(string codigoAsignatura);
    bool tieneClaseDe(string codigoAsignatura, TipoClase tipoClase);
};

#endif