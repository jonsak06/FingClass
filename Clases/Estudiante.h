#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
#include "Asignatura.h"
#include "../Datatypes/DtEstudiante.h"
#include "../Datatypes/DtAsignatura.h"
#include <vector>

class Asignatura;

class Estudiante : public Usuario
{
private:
    string cedula;
    vector<Asignatura> asignaturas;
public:
    Estudiante();
    Estudiante(string, string, string, string, string);
    string getCedula() const;
    vector<Asignatura> getAsignaturas() const;
    void setCedula(string);
    void setAsignaturas(vector<Asignatura>);
    //operaciones DCD
    DtEstudiante* getDatosUsuario() const;
    bool comprobarInscripcion(string);
    vector<DtAsignatura> getDatosAsignaturas() const;
    void removerAsignatura(string);
};

#endif
