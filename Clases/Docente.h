#ifndef DOCENTE_H
#define DOCENTE_H

#include "Usuario.h"
#include "Clase.h"
#include "Asignatura.h"
#include "Asignacion.h"
#include "../Datatypes/DtDocente.h"
#include "../Otros/TipoClase.h"

class Docente : public Usuario
{
private:
    string nombreInstituto;
    vector<Clase*> clasesIniciadas;
    vector<Asignacion> asignaciones;
public:
    Docente();
    Docente(string, string, string, string, string);
    string getNombreInstituto() const;
    vector<Clase*> getClasesIniciadas() const;
    vector<Asignacion> getAsignaciones() const;
    void setNombreInstituto(string);
    void setClasesIniciadas(vector<Clase*>);
    void setAsignaciones(vector<Asignacion>);
    //operaciones DCD
    DtDocente getDatosDocente() const;
    bool comprobarAsignacion(string) const;
    void asignarAsignatura(Asignatura, TipoClase);
    vector<DtAsignatura> getDatosAsignaturas() const;
    TipoClase getRolDictado(string) const;
    void agregarClase(Clase*);
    vector<Clase*> getDatosClasesEnVivo(string) const;
    DtClase* getDatosClase() const;
    void finalizarClase(int);
    vector<DtClase*> getDatosClases(string) const;
    void removerClasesYAsignacion(string);
};

#endif
