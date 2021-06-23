#ifndef IASIGNATURASUSUARIOS_H
#define IASIGNATURASUSUARIOS_H

#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtDocente.h"

class IAsignaturasUsuarios
{
public:
    IAsignaturasUsuarios(/* args */) {}
    virtual ~IAsignaturasUsuarios() {}
    //CU Alta usuario
    virtual void agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto) = 0;
    virtual void agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarAltaUsuario() = 0;
    //CU Alta asignatura
    virtual DtAsignatura* agregarAsignatura(string nombreAsignatura, string codigoAsignatura, bool teorico, bool practico, bool monitoreo) = 0;
    virtual void confirmarAltaAsignatura() = 0;
    virtual void cancelarAltaAsignatura() = 0;
    //CU asignacion docente a asignatura
    virtual IDictionary* listarAsignaturas() = 0;
    virtual IDictionary* listarDocentesSinAsignar(string codigoAsignatura) = 0;
    virtual void seleccionarDocente(string email, TipoClase rolDictado) = 0;
    virtual void confirmarAsignacion() = 0;
    virtual void cancelarAsignacion() = 0;
    virtual void dejarDeAsignarDocentes() = 0;
    //CU inscripcion a asignaturas
    virtual IDictionary* listarAsignaturasNoInscripto(string cedula) = 0;
    virtual void seleccionarAsignatura(string codigoAsignatura) = 0;
    virtual void confirmarInscripcion() = 0;
    virtual void cancelarInscripcion() = 0;
    //CU eliminar asignatura
    virtual void confirmarEliminacion() = 0;
    virtual void cancelarEliminacion() = 0;

    virtual bool tieneClaseDe(string, TipoClase) = 0;
    virtual void cargarDatosAsigUsr() = 0;
};

#endif
