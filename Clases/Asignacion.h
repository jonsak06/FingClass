#ifndef ASIGNACION_H
#define ASIGNACION_H

#include "Asignatura.h"
#include "../Otros/TipoClase.h"
#include "../Datatypes/DtAsignatura.h"
#include "../ICollection/interfaces/ICollectible.h"

class Asignacion : public ICollectible
{
private:
    TipoClase rolDictado;
    Asignatura *asignatura;

public:
    Asignacion();
    ~Asignacion();
    Asignacion(Asignatura *, TipoClase);
    TipoClase getRolDictado() const;
    Asignatura *getAsignatura() const;
    void setRolDictado(TipoClase);
    void setAsignatura(Asignatura *);
    
    string getCodigoAsignatura();
    DtAsignatura *getDatosAsignatura() const;
};

#endif