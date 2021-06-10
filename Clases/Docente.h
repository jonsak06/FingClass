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
    IDictionary* clasesIniciadas;
    ICollection* asignaciones;
public:
    Docente();
    Docente(string, string, string, string, string);
    string getNombreInstituto() const;
    IDictionary* getClasesIniciadas() const;
    ICollection* getAsignaciones() const;
    void setNombreInstituto(string);
    void setClasesIniciadas(IDictionary*);
    void setAsignaciones(ICollection*);
    //operaciones DCD
    DtDocente getDatosDocente() const;
    bool comprobarAsignacion(string) const;
    void asignarAsignatura(Asignatura, TipoClase);
    ICollection* getDatosAsignaturas() const;
    TipoClase getRolDictado(string) const;
    void agregarClase(Clase*);
    IDictionary* getDatosClasesEnVivo(string) const;
    DtClase* getDatosClase() const;
    void finalizarClase(int);
    ICollection* getDatosClases(string) const;
    void removerClasesYAsignacion(string);
};

#endif
