#ifndef CONTROLLERASIGNATURASUSUARIOS_H
#define CONTROLLERASIGNATURASUSUARIOS_H

#include "../Clases/Docente.h"
#include "../Clases/Estudiante.h"
#include "../Clases/Asignatura.h"
#include "../Clases/Clase.h"
#include "IClases.h"

class ControllerClases : public IClases
{
private:
    Docente* docActual;
    Estudiante* estActual;
    vector <Estudiante> habilitados;
    Asignatura* asigActual;
    Clase* clsActual;
public:
    ControllerClases(/* args */);
    ~ControllerClases();
    //CU inicio de clase
    vector <DtAsignatura> listarAsignaturasAsignadas(string email);
    int crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo);
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
    //CU AsistenciaEnDiferido en vivo
    vector <DtAsignatura> listarAsignaturasCursando(string cedula);
    vector <DtClase*> listarClasesEnVivoHabilitado(string codigoAsignatura);
    void confirmarAsistenciaEnDiferido();
    void cancelarAsistenciaEnDiferido();
    //CU reproduccion en diferido
    vector <DtClase*> listarClasesEnDiferido(string codigoAsignatura);
    vector <DtMensaje> confirmarReproduccion();
    void cancelarReproduccion();
    //CU listado de clases
    vector <DtClase*> listarClases(string codigoAsignatura);
    //CU tiempo de dictado = listarAsignaturas()
    //CU tiempo AsistenciaEnDiferido 
    vector <DtClase*> listarClasesDictadas(string codigoAsignatura);
};


#endif
