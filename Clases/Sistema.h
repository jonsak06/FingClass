#ifndef SISTEMA_H
#define SISTEMA_H

#include "Asignacion.h"
#include "Asignatura.h"
#include "Asistencia.h"
#include "Docente.h"
#include "Estudiante.h"
#include "Teorico.h"
#include "Practico.h"
#include "Monitoreo.h"
#include "Mensaje.h"
#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtEstudiante.h"
#include "../Datatypes/DtDocente.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"

class Sistema
{
private:
    /* data */
public:
    Sistema();
    ~Sistema();
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
    //CU inicio de clase
    vector <DtAsignatura> listarAsignaturasAsignadas(string email);
    int crearDatosClase(string codigoAsignatura, string nombreClase, DtFechaHora fechaHoraComienzo);
    vector <DtEstudiante> listarEstudiantesInscriptos();
    void habilitarEstudiante(string cedula);
    DtClase* obtenerInfoClase();
    void confirmarInicioClase();
    void cancelarInicioClase();
    //CU finalizacion de clase
    vector <DtClase> listarClasesEnVivo(string email);
    DtClase* seleccionarClase(int numeroClase);
    void confirmarFinalizacionClase();
    void cancelarFinalizacionClase();
    //CU envio de mensaje
    vector <DtClase> listarClasesEnVivoParticipando(string email);
    vector <DtMensaje> listarMensajes(int numeroClase);
    void responderMensaje(int idMensaje, string mensaje);
    void escribirMensaje(string mensaje);
    void enviarMensaje();
    void cancelarMensaje();
    //CU asistencia en vivo
    vector <DtAsignatura> listarAsignaturasCursando(string cedula);
    vector <DtClase*> listarClasesEnVivoHabilitado(string codigoAsignatura);
    void confirmarAsistencia();
    void cancelarAsistencia();
    //CU reproduccion en diferido
    vector <DtClase*> listarClasesEnDiferido(string codigoAsignatura);
    vector <DtMensaje> confirmarReproduccion();
    void cancelarReproduccion();
    //CU listado de clases
    vector <DtClase*> listarClases(string codigoAsignatura);
    //CU tiempo de dictado = listarAsignaturas()
    //CU tiempo asistencia 
    vector <DtClase*> listarClasesDictadas(string codigoAsignatura);
    //CU eliminar asignatura
    void confirmarEliminacion();
    void cancelarEliminacion();

};

#endif
