#include "ControllerClases.h"

ControllerClases& ControllerClases::getInstance() {
    static ControllerClases* controller = new ControllerClases();
    return *controller;
}
//CU inicio de clase
ICollection* ControllerClases::listarAsignaturasAsignadas(string email) {}
int ControllerClases::crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo) {}
ICollection* ControllerClases::listarEstudiantesInscriptos() {}
void ControllerClases::habilitarEstudiante(string cedula) {}
DtClase* ControllerClases::obtenerInfoClase() {}
void ControllerClases::confirmarInicioClase() {}
void ControllerClases::cancelarInicioClase() {}
//CU finalizacion de clase
ICollection* ControllerClases::listarClasesEnVivo(string email) {}
DtClase* ControllerClases::seleccionarClase(int numeroClase) {}
void ControllerClases::confirmarFinalizacionClase() {}
void ControllerClases::cancelarFinalizacionClase() {}
//CU envio de mensaje
ICollection* ControllerClases::listarClasesEnVivoParticipando(string email) {}
ICollection* ControllerClases::listarMensajes(int numeroClase) {}
void ControllerClases::responderMensaje(int idMensaje, string mensaje) {}
void ControllerClases::escribirMensaje(string mensaje) {}
void ControllerClases::enviarMensaje() {}
void ControllerClases::cancelarMensaje() {}
//CU AsistenciaEnDiferido en vivo
ICollection* ControllerClases::listarAsignaturasCursando(string cedula) {}
ICollection* ControllerClases::listarClasesEnVivoHabilitado(string codigoAsignatura) {}
void ControllerClases::confirmarAsistenciaEnDiferido() {}
void ControllerClases::cancelarAsistenciaEnDiferido() {}
//CU reproduccion en diferido
ICollection* ControllerClases::listarClasesEnDiferido(string codigoAsignatura) {}
ICollection* ControllerClases::confirmarReproduccion() {}
void ControllerClases::cancelarReproduccion() {}
//CU listado de clases
ICollection* ControllerClases::listarClases(string codigoAsignatura) {}
//CU tiempo de dictado
ICollection* ControllerClases::listarAsignaturas() {}
//CU tiempo AsistenciaEnDiferido 
ICollection* ControllerClases::listarClasesDictadas(string codigoAsignatura) {}