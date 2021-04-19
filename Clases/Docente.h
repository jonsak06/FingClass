#ifndef DOCENTE_H
#define DOCENTE_H

#include "Usuario.h"

class Docente : public Usuario
{
private:
    string nombreInstituto;
public:
    Docente();
    ~Docente();
    Docente(string, string, string, string);
    string getNombreInstituto() const;
    void setNombreInstituto(string);
};

#endif
