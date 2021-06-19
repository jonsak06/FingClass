#ifndef HANDLERASIGNATURAS_H
#define HANDLERASIGNATURAS_H

#include "../Clases/Asignatura.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/String.h"

class HandlerAsignaturas
{
private:
    HandlerAsignaturas() = default;
    HandlerAsignaturas(const HandlerAsignaturas&) = delete;
    HandlerAsignaturas& operator=(const HandlerAsignaturas&) = delete;
    HandlerAsignaturas(HandlerAsignaturas&&) = delete;
    HandlerAsignaturas& operator=(HandlerAsignaturas&&) = delete;
    IDictionary* asignaturas = new OrderedDictionary;
public:
    static HandlerAsignaturas& getInstance();

    //operaciones DCD
    IDictionary* getDatosAsignaturas() const;
    Asignatura getAsignatura(string codigoAsignatura);
    IDictionary* getDatosAsignaturasNoInscripto() const;
    void agregarAsignatura(DtAsignatura* dvAsig);
    IDictionary* getDatosAsignaturasCursando(string cedula) const;
    IDictionary* listarClasesEnVivoHabilitado(string cedula, string codigoAsignatura) const;
    void removerAsignatura(Asignatura a);
    void eliminarAsignatura(Asignatura a);
};

#endif