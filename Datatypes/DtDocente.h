#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include "DtUsuario.h"
#include "../Otros/TipoClase.h"

class DtDocente : public DtUsuario
{
private:
    string nombreInstituto;
    TipoClase rolDictado;
public:
    DtDocente();
    DtDocente(string, string, string, string, string);
    DtDocente(string, string, string, string, string, TipoClase);
    string getNombreInstituto() const;
};

#endif
