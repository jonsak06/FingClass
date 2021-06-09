#ifndef CONTROLLERASIGNATURASUSUARIOS_H
#define CONTROLLERASIGNATURASUSUARIOS_H

#include "../Clases/Asignatura.h"
#include "../Clases/Docente.h"
#include "IAsignaturasUsuarios.h"

class ControllerAsignaturasUsuarios : public IAsignaturasUsuarios
{
private:
    Docente* docActual;
    Asignatura* asigActual;
public:
    ControllerAsignaturasUsuarios();
    ~ControllerAsignaturasUsuarios();
    //CU Alta usuario
    void agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto);
    void agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula);
    void confirmarAltaUsuario();
    void cancelarAltaUsuario();
    //CU Alta asignatura
    DtAsignatura agregarAsignatura(string nombreAsignatura, string codigoAsignatura, bool teorico, bool practico, bool monitoreo);
    void confirmarAltaAsignatura();
    void cancelarAltaAsignatura();
    //CU asignacion docente a asignatura
    vector <DtAsignatura> listarAsignaturas();
    vector <DtDocente> listarDocentesSinAsignar(string codigoAsignatura);
    void seleccionarDocente(string email, TipoClase rolDictado);
    void confirmarAsignacion();
    void cancelarAsignacion();
    //CU inscripcion a asignaturas
    vector <DtAsignatura> listarAsignaturasNoInscripto(string cedula);
    void seleccionarAsignatura(string codigoAsignatura);
    void confirmarInscripcion();
    void cancelarInscripcion();
    //CU eliminar asignatura
    void confirmarEliminacion();
    void cancelarEliminacion();

};

#endif
