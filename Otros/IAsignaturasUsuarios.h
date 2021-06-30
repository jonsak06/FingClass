#ifndef IASIGNATURASUSUARIOS_H
#define IASIGNATURASUSUARIOS_H

#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtDocente.h"

class IAsignaturasUsuarios
{
public:
    IAsignaturasUsuarios() {}
    virtual ~IAsignaturasUsuarios() {}
    virtual void agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto) = 0;
    virtual void agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarAltaUsuario() = 0;
    virtual DtAsignatura *agregarAsignatura(string nombreAsignatura, string codigoAsignatura, bool teorico, bool practico, bool monitoreo) = 0;
    virtual void confirmarAltaAsignatura() = 0;
    virtual void cancelarAltaAsignatura() = 0;
    virtual IDictionary *listarAsignaturas() = 0;
    virtual IDictionary *listarDocentesSinAsignar(string codigoAsignatura) = 0;
    virtual void seleccionarDocente(string email, TipoClase rolDictado) = 0;
    virtual void confirmarAsignacion() = 0;
    virtual void cancelarAsignacion() = 0;
    virtual void dejarDeAsignarDocentes() = 0;
    virtual IDictionary *listarAsignaturasNoInscripto(string cedula) = 0;
    virtual void seleccionarAsignatura(string codigoAsignatura) = 0;
    virtual void confirmarInscripcion() = 0;
    virtual void cancelarInscripcion() = 0;
    virtual void confirmarEliminacion() = 0;
    virtual void cancelarEliminacion() = 0;

    virtual bool tieneClaseDe(string, TipoClase) = 0;
    virtual void cargarDatosAsigUsr() = 0;
    virtual IDictionary *listarEstudiantes() = 0;
    virtual IDictionary *listarDocentes() = 0;
    virtual bool existeUsuario(string clave) = 0;
    virtual bool confirmarPassword(string clave, string password) = 0;
};

#endif
