#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
#include "../Datatypes/DtEstudiante.h"
#include "../Datatypes/DtAsignatura.h"

class Estudiante : public Usuario
{
private:
    string cedula;
public:
    Estudiante();
    Estudiante(string, string, string, string, string);
    string getCedula() const;
    void setCedula(string);

    //operaciones DCD
    DtEstudiante* getDatosUsuario() const;
};

#endif
