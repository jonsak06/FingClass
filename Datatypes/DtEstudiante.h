#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include "DtUsuario.h"

class DtEstudiante : public DtUsuario
{
private:
    string cedula;
public:
    DtEstudiante();
    DtEstudiante(string, string, string, string, string);
    string getCedula() const;
};

#endif
