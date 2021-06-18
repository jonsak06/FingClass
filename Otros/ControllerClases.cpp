#include "ControllerClases.h"

ControllerClases& ControllerClases::getInstance() {
    static ControllerClases* controller = new ControllerClases();
    return *controller;
}
//CU inicio de clase
IDictionary* ControllerClases::listarAsignaturasAsignadas(string email) {}
TipoClase ControllerClases::crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo) {}
IDictionary* ControllerClases::listarEstudiantesInscriptos() {}
void ControllerClases::habilitarEstudiante(string cedula) {}
DtClase* ControllerClases::obtenerInfoClase() {}
void ControllerClases::confirmarInicioClase() {}
void ControllerClases::cancelarInicioClase() {}
//CU finalizacion de clase
IDictionary* ControllerClases::listarClasesEnVivo(string email) {}
DtClase* ControllerClases::seleccionarClaseDocente(int numeroClase) {}
void ControllerClases::confirmarFinalizacionClase() {}
void ControllerClases::cancelarFinalizacionClase() {}
//CU envio de mensaje
IDictionary* ControllerClases::listarClasesEnVivoParticipando(string email) {}
IDictionary* ControllerClases::listarMensajes(int numeroClase) {}
void ControllerClases::responderMensaje(int idMensaje, string mensaje) {}
void ControllerClases::escribirMensaje(string mensaje) {}
void ControllerClases::enviarMensaje() {}
void ControllerClases::cancelarMensaje() {}
//CU AsistenciaEnDiferido en vivo
IDictionary* ControllerClases::listarAsignaturasCursando(string cedula) {}
IDictionary* ControllerClases::listarClasesEnVivoHabilitado(string codigoAsignatura) {}
DtClase* ControllerClases::seleccionarClase(int numeroClase) {}
void ControllerClases::confirmarAsistencia() {}
void ControllerClases::cancelarAsistencia() {}
//CU reproduccion en diferido
IDictionary* ControllerClases::listarClasesEnDiferido(string codigoAsignatura) {}
IDictionary* ControllerClases::confirmarReproduccion() {}
void ControllerClases::cancelarReproduccion() {}
//CU listado de clases
IDictionary* ControllerClases::listarClases(string codigoAsignatura) {}
//CU tiempo de dictado
IDictionary* ControllerClases::listarAsignaturas() {}
//CU tiempo AsistenciaEnDiferido 
//IDictionary* ControllerClases::listarAsignaturasAsignadas(string email) {}
IDictionary* ControllerClases::listarClasesDictadas(string codigoAsignatura) {}

void ControllerClases::cargarDatosClases() {}