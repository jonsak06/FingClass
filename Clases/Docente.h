#ifndef DOCENTE_H
#define DOCENTE_H

#include "Usuario.h"
#include "Asignatura.h"
#include "Asignacion.h"
#include "../Datatypes/DtDocente.h"
#include "../Otros/TipoClase.h"
#include "../ICollection/collections/List.h"

// class Asignatura;

class Docente : public Usuario
{
private:
    string nombreInstituto;
    ICollection* asignaciones;
public:
    Docente();
    Docente(string, string, string, string, string);
    string getNombreInstituto() const;
    ICollection* getAsignaciones() const;
    void setNombreInstituto(string);
    void setAsignaciones(ICollection*);

    //operaciones DCD
    DtDocente* getDatosUsuario() const;
    bool comprobarAsignacion(string codigoAsignatura) const;
    void asignarAsignatura(Asignatura* a, TipoClase rolDictado);
    IDictionary* getDatosAsignaturas() const;
    TipoClase getRolDictado(string codigoAsignatura) const;
    void finalizarClase(int numeroClase);
    void removerAsignacion(string codigoAsignatura);
};

#endif
