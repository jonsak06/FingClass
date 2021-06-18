#ifndef CONTROLLERCLASES_H
#define CONTROLLERCLASES_H

#include "../Clases/Docente.h"
#include "../Clases/Estudiante.h"
#include "../Clases/Asignatura.h"
#include "../Clases/Clase.h"
#include "IClases.h"

class ControllerClases : public IClases
{
private:
    ControllerClases() = default;
    ControllerClases(const ControllerClases&) = delete;
    ControllerClases& operator=(const ControllerClases&) = delete;
    ControllerClases(ControllerClases&&) = delete;
    ControllerClases& operator=(ControllerClases&&) = delete;
    Docente* docActual;
    Estudiante* estActual;
    IDictionary* habilitados;
    Asignatura* asigActual;
    Clase* clsActual;
public:
    static ControllerClases& getInstance();

    //CU inicio de clase
    IDictionary* listarAsignaturasAsignadas(string email);
    TipoClase crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo);
    IDictionary* listarEstudiantesInscriptos();
    void habilitarEstudiante(string cedula);
    DtClase* obtenerInfoClase();
    void confirmarInicioClase();
    void cancelarInicioClase();

    //CU finalizacion de clase
    IDictionary* listarClasesEnVivo(string email);
    DtClase* seleccionarClaseDocente(int numeroClase);
    void confirmarFinalizacionClase();
    void cancelarFinalizacionClase();

    //CU envio de mensaje
    IDictionary* listarClasesEnVivoParticipando(string email);
    IDictionary* listarMensajes(int numeroClase);
    void responderMensaje(int idMensaje, string mensaje);
    void escribirMensaje(string mensaje);
    void enviarMensaje();
    void cancelarMensaje();

    //CU Asistencia en vivo
    IDictionary* listarAsignaturasCursando(string cedula);
    IDictionary* listarClasesEnVivoHabilitado(string codigoAsignatura);
    DtClase* seleccionarClase(int numeroClase);
    void confirmarAsistencia();
    void cancelarAsistencia();

    //CU reproduccion en diferido
    //IDictionary* listarAsignaturasCursando(string cedula);
    IDictionary* listarClasesEnDiferido(string codigoAsignatura);
    //DtClase* seleccionarClase(int numeroClase);
    IDictionary* confirmarReproduccion();
    void cancelarReproduccion();

    //CU listado de clases
    //IDictionary* listarAsignaturasAsignadas(string email);
    IDictionary* listarClases(string codigoAsignatura);

    //CU tiempo de dictado
    IDictionary* listarAsignaturas();

    //CU tiempo Asistencia
    //IDictionary* listarAsignaturasAsignadas(string email);
    IDictionary* listarClasesDictadas(string codigoAsignatura);

    void cargarDatosClases();
};


#endif
