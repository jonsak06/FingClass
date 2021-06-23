#ifndef ASIGNACION_H
#define ASIGNACION_H

#include "../Otros/TipoClase.h"
#include "Asignatura.h"
#include "../Datatypes/DtAsignatura.h"
#include "../ICollection/interfaces/ICollectible.h"

class Asignacion : public ICollectible
{
private:
    TipoClase rolDictado;
    Asignatura asignatura;
public:
    Asignacion();
    ~Asignacion();
    Asignacion(Asignatura, TipoClase);
    TipoClase getRolDictado() const;
    Asignatura getAsignatura() const;
    void setRolDictado(TipoClase);
    void setAsignatura(Asignatura);
    //operaciones DCD
    string getCodigoAsignatura() const;
    DtAsignatura getDatosAsignatura() const;
};

#endif