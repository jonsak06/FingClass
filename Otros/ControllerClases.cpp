#include "ControllerClases.h"

ControllerClases& ControllerClases::getInstance() {
    static ControllerClases* controller = new ControllerClases();
    return *controller;
}
//CU inicio de clase
vector <DtAsignatura> ControllerClases::listarAsignaturasAsignadas(string email) {}
int ControllerClases::crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo) {}
vector <DtEstudiante> ControllerClases::listarEstudiantesInscriptos() {}
void ControllerClases::habilitarEstudiante(string cedula) {}
DtClase* ControllerClases::obtenerInfoClase() {}
void ControllerClases::confirmarInicioClase() {}
void ControllerClases::cancelarInicioClase() {}
//CU finalizacion de clase
vector <DtClase> ControllerClases::listarClasesEnVivo(string email) {}
DtClase* ControllerClases::seleccionarClase(int numeroClase) {}
void ControllerClases::confirmarFinalizacionClase() {}
void ControllerClases::cancelarFinalizacionClase() {}
//CU envio de mensaje
vector <DtClase> ControllerClases::listarClasesEnVivoParticipando(string email) {}
vector <DtMensaje> ControllerClases::listarMensajes(int numeroClase) {}
void ControllerClases::responderMensaje(int idMensaje, string mensaje) {}
void ControllerClases::escribirMensaje(string mensaje) {}
void ControllerClases::enviarMensaje() {}
void ControllerClases::cancelarMensaje() {}
//CU AsistenciaEnDiferido en vivo
vector <DtAsignatura> ControllerClases::listarAsignaturasCursando(string cedula) {}
vector <DtClase*> ControllerClases::listarClasesEnVivoHabilitado(string codigoAsignatura) {}
void ControllerClases::confirmarAsistenciaEnDiferido() {}
void ControllerClases::cancelarAsistenciaEnDiferido() {}
//CU reproduccion en diferido
vector <DtClase*> ControllerClases::listarClasesEnDiferido(string codigoAsignatura) {}
vector <DtMensaje> ControllerClases::confirmarReproduccion() {}
void ControllerClases::cancelarReproduccion() {}
//CU listado de clases
vector <DtClase*> ControllerClases::listarClases(string codigoAsignatura) {}
//CU tiempo de dictado
vector <DtAsignatura> ControllerClases::listarAsignaturas() {}
//CU tiempo AsistenciaEnDiferido 
vector <DtClase*> ControllerClases::listarClasesDictadas(string codigoAsignatura) {}