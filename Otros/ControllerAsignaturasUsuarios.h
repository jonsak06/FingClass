#ifndef CONTROLLERASIGNATURASUSUARIOS_H
#define CONTROLLERASIGNATURASUSUARIOS_H

#include "../Clases/Asignatura.h"
#include "../Clases/Docente.h"
#include "IAsignaturasUsuarios.h"
#include "HandlerUsuarios.h"
#include "HandlerAsignaturas.h"

class ControllerAsignaturasUsuarios : public IAsignaturasUsuarios
{
private:
    ControllerAsignaturasUsuarios() = default;
    ControllerAsignaturasUsuarios(const ControllerAsignaturasUsuarios&) = delete;
    ControllerAsignaturasUsuarios& operator=(const ControllerAsignaturasUsuarios&) = delete;
    ControllerAsignaturasUsuarios(ControllerAsignaturasUsuarios&&) = delete;
    ControllerAsignaturasUsuarios& operator=(ControllerAsignaturasUsuarios&&) = delete;
    Docente* docActual;
    Asignatura* asigActual;
    DtUsuario* dvUsr;
    DtAsignatura* dvAsig;
public:
    static ControllerAsignaturasUsuarios& getInstance();

    //CU Alta usuario
    void agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto);
    void agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula);
    void confirmarAltaUsuario();
    void cancelarAltaUsuario();

    //CU Alta asignatura
    DtAsignatura* agregarAsignatura(string nombreAsignatura, string codigoAsignatura, bool teorico, bool practico, bool monitoreo);
    void confirmarAltaAsignatura();
    void cancelarAltaAsignatura();

    //CU asignacion docente a asignatura
    IDictionary* listarAsignaturas();
    IDictionary* listarDocentesSinAsignar(string codigoAsignatura);
    void seleccionarDocente(string email, TipoClase rolDictado);
    void confirmarAsignacion();
    void cancelarAsignacion();

    //CU inscripcion a asignaturas
    IDictionary* listarAsignaturasNoInscripto(string cedula);
    void seleccionarAsignatura(string codigoAsignatura);
    void confirmarInscripcion();
    void cancelarInscripcion();
    
    //CU eliminar asignatura
    //IDictionary* listarAsignaturas();
    //void seleccionarAsignatura(string codigoAsignatura);
    void confirmarEliminacion();
    void cancelarEliminacion();

    void cargarDatosAsigUsr();
};

#endif
