#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include "DtUsuario.h"
#include "../Otros/TipoClase.h"
#include <iostream>

class DtDocente : public DtUsuario
{
private:
    string nombreInstituto;

public:
    DtDocente();
    DtDocente(string, string, string, string, string);
    DtDocente(string, string);
    string getNombreInstituto() const;
    string getCedula() const;
    void mostrarInfo(ostream &);
};

#endif
