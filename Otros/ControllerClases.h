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
    ICollection* listarAsignaturasAsignadas(string email);
    int crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo);
    ICollection* listarEstudiantesInscriptos();
    void habilitarEstudiante(string cedula);
    DtClase* obtenerInfoClase();
    void confirmarInicioClase();
    void cancelarInicioClase();

    //CU finalizacion de clase
    ICollection* listarClasesEnVivo(string email);
    DtClase* seleccionarClaseDocente(int numeroClase);
    void confirmarFinalizacionClase();
    void cancelarFinalizacionClase();

    //CU envio de mensaje
    ICollection* listarClasesEnVivoParticipando(string email);
    ICollection* listarMensajes(int numeroClase);
    void responderMensaje(int idMensaje, string mensaje);
    void escribirMensaje(string mensaje);
    void enviarMensaje();
    void cancelarMensaje();

    //CU Asistencia en vivo
    ICollection* listarAsignaturasCursando(string cedula);
    ICollection* listarClasesEnVivoHabilitado(string codigoAsignatura);
    DtClase* seleccionarClase(int numeroClase);
    void confirmarAsistencia();
    void cancelarAsistencia();

    //CU reproduccion en diferido
    //ICollection* listarAsignaturasCursando(string cedula);
    ICollection* listarClasesEnDiferido(string codigoAsignatura);
    //DtClase* seleccionarClase(int numeroClase);
    ICollection* confirmarReproduccion();
    void cancelarReproduccion();

    //CU listado de clases
    //ICollection* listarAsignaturasAsignadas(string email);
    ICollection* listarClases(string codigoAsignatura);

    //CU tiempo de dictado
    ICollection* listarAsignaturas();

    //CU tiempo Asistencia
    //ICollection* listarAsignaturasAsignadas(string email);
    ICollection* listarClasesDictadas(string codigoAsignatura);

    void cargarDatosClases();
};


#endif
