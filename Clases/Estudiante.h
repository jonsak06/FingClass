#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
#include "Asignatura.h"
#include "../Datatypes/DtEstudiante.h"
#include "../Datatypes/DtAsignatura.h"

class Asignatura;

class Estudiante : public Usuario
{
private:
    string cedula;
    IDictionary* asignaturas;
public:
    Estudiante();
    Estudiante(string, string, string, string, string);
    string getCedula() const;
    IDictionary* getAsignaturas() const;
    void setCedula(string);
    void setAsignaturas(IDictionary*);
    //operaciones DCD
    DtEstudiante* getDatosUsuario() const;
    bool comprobarInscripcion(string);
    ICollection* getDatosAsignaturas() const;
    void removerAsignatura(string);
};

#endif
