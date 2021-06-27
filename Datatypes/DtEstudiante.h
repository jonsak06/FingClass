#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include "DtUsuario.h"
#include <iostream>

class DtEstudiante : public DtUsuario
{
private:
    string cedula;
public:
    DtEstudiante();
    DtEstudiante(string, string, string, string, string);
    DtEstudiante(string, string);
    string getCedula() const;
    string getNombreInstituto() const;
    void mostrarInfo(ostream&);
};

#endif
