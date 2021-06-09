#ifndef ICLASES_H
#define ICLASES_H

#include "../Datatypes/DtDocente.h"
#include "../Datatypes/DtEstudiante.h"
#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"

class IClases
{
public:
    IClases(/* args */) {}
    virtual ~IClases() {}
    virtual vector <DtAsignatura> listarAsignaturasAsignadas(string email) = 0;
    virtual int crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo) = 0;
    virtual vector <DtEstudiante> listarEstudiantesInscriptos() = 0;
    virtual void habilitarEstudiante(string cedula) = 0;
    virtual DtClase* obtenerInfoClase() = 0;
    virtual void confirmarInicioClase() = 0;
    virtual void cancelarInicioClase() = 0;
    //CU finalizacion de clase
    virtual vector <DtClase> listarClasesEnVivo(string email) = 0;
    virtual DtClase* seleccionarClase(int numeroClase) = 0;
    virtual void confirmarFinalizacionClase() = 0;
    virtual void cancelarFinalizacionClase() = 0;
    //CU envio de mensaje
    virtual vector <DtClase> listarClasesEnVivoParticipando(string email) = 0;
    virtual vector <DtMensaje> listarMensajes(int numeroClase) = 0;
    virtual void responderMensaje(int idMensaje, string mensaje) = 0;
    virtual void escribirMensaje(string mensaje) = 0;
    virtual void enviarMensaje() = 0;
    virtual void cancelarMensaje() = 0;
    //CU AsistenciaEnDiferido en vivo
    virtual vector <DtAsignatura> listarAsignaturasCursando(string cedula) = 0;
    virtual vector <DtClase*> listarClasesEnVivoHabilitado(string codigoAsignatura) = 0;
    virtual void confirmarAsistenciaEnDiferido() = 0;
    virtual void cancelarAsistenciaEnDiferido() = 0;
    //CU reproduccion en diferido
    virtual vector <DtClase*> listarClasesEnDiferido(string codigoAsignatura) = 0;
    virtual vector <DtMensaje> confirmarReproduccion() = 0;
    virtual void cancelarReproduccion() = 0;
    //CU listado de clases
    virtual vector <DtClase*> listarClases(string codigoAsignatura) = 0;
    //CU tiempo de dictado = listarAsignaturas()
    //CU tiempo AsistenciaEnDiferido 
    virtual vector <DtClase*> listarClasesDictadas(string codigoAsignatura) = 0;
};

#endif
