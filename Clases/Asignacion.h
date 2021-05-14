#ifndef ASIGNACION_H
#define ASIGNACION_H

#include "../Otros/TipoClase.h"
#include "Docente.h"
#include "Asignatura.h"

class Asignacion
{
private:
    TipoClase rolDictado;
    Docente* docente;
    Asignatura* asignatura;
public:
    Asignacion();
    ~Asignacion();
    Asignacion(Docente*, Asignatura*, TipoClase);
    TipoClase getRolDictado() const;
    Docente* getDocente() const;
    Asignatura* getAsignatura() const;
    void setRolDictado(TipoClase);
    void setDocente(Docente*);
    void setAsignatura(Asignatura*);
};

#endif