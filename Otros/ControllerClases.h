#ifndef CONTROLLERCLASES_H
#define CONTROLLERCLASES_H

#include "../Clases/Docente.h"
#include "../Clases/Estudiante.h"
#include "../Clases/Asignatura.h"
#include "../Clases/Clase.h"
#include "../Datatypes/DtTeorico.h"
#include "../Datatypes/DtPractico.h"
#include "../Datatypes/DtMonitoreo.h"
#include "IClases.h"
#include "HandlerAsignaturas.h"
#include "HandlerUsuarios.h"
#include "Reloj.h"

class ControllerClases : public IClases
{
private:
    ControllerClases();
    ControllerClases(const ControllerClases &) = delete;
    ControllerClases &operator=(const ControllerClases &) = delete;
    ControllerClases(ControllerClases &&) = delete;
    ControllerClases &operator=(ControllerClases &&) = delete;
    Docente *docActual;
    Estudiante *estActual;
    Usuario *usrActual;
    IDictionary *habilitados;
    Asignatura *asigActual;
    Clase *clsActual;
    DtClase *claseNueva;
    int numeroClase;
    int idMensaje;
    int *numeroClaseActual;
    string *mensaje;
    Mensaje *msjActual;

public:
    static ControllerClases &getInstance();

    //CU inicio de clase
    IDictionary *listarAsignaturasAsignadas(string email);
    TipoClase crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo);
    IDictionary *listarEstudiantesInscriptos();
    void habilitarEstudiante(string cedula);
    DtClase *obtenerInfoClase();
    void confirmarInicioClase();
    void cancelarInicioClase();

    //CU finalizacion de clase
    IDictionary *listarClasesEnVivo(string email);
    DtClase *seleccionarClaseDocente(int numeroClase);
    void confirmarFinalizacionClase();
    void cancelarFinalizacionClase();

    //CU envio de mensaje
    IDictionary *listarClasesEnVivoParticipando(string email);
    IDictionary *listarMensajes(int numeroClase);
    void responderMensaje(int idMensaje, string mensaje);
    void escribirMensaje(string mensaje);
    void enviarMensaje();
    void cancelarMensaje();

    //CU Asistencia en vivo
    IDictionary *listarAsignaturasCursando(string cedula);
    IDictionary *listarClasesEnVivoHabilitado(string codigoAsignatura);
    DtClase *seleccionarClase(int numeroClase);
    void confirmarAsistencia();
    void cancelarAsistencia();

    //CU reproduccion en diferido
    //IDictionary* listarAsignaturasCursando(string cedula);
    IDictionary *listarClasesEnDiferido(string codigoAsignatura);
    //DtClase* seleccionarClase(int numeroClase);
    IDictionary *confirmarReproduccion();
    void cancelarReproduccion();

    //CU listado de clases
    //IDictionary* listarAsignaturasAsignadas(string email);
    IDictionary *listarClases(string codigoAsignatura);

    //CU tiempo de dictado
    IDictionary *listarAsignaturas();

    //CU tiempo Asistencia
    //IDictionary* listarAsignaturasAsignadas(string email);
    // IDictionary *listarClases(string codigoAsignatura);

    void finalizarReproduccion(string cedula, string codigoAsignatura, int numeroClase);
    void cargarDatosClases();
};

#endif
