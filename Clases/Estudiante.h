#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"

class Estudiante : public Usuario
{
private:
    string cedula;
public:
    Estudiante();
    Estudiante(string, string, string, string, string);
    string getCedula() const;
    void setCedula(string);
};

#endif
