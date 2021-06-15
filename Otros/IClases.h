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
    virtual ICollection* listarAsignaturasAsignadas(string email) = 0;
    virtual int crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo) = 0;
    virtual ICollection* listarEstudiantesInscriptos() = 0;
    virtual void habilitarEstudiante(string cedula) = 0;
    virtual DtClase* obtenerInfoClase() = 0;
    virtual void confirmarInicioClase() = 0;
    virtual void cancelarInicioClase() = 0;
    //CU finalizacion de clase
    virtual ICollection* listarClasesEnVivo(string email) = 0;
    virtual DtClase* seleccionarClaseDocente(int numeroClase) = 0;
    virtual void confirmarFinalizacionClase() = 0;
    virtual void cancelarFinalizacionClase() = 0;
    //CU envio de mensaje
    virtual ICollection* listarClasesEnVivoParticipando(string email) = 0;
    virtual ICollection* listarMensajes(int numeroClase) = 0;
    virtual void responderMensaje(int idMensaje, string mensaje) = 0;
    virtual void escribirMensaje(string mensaje) = 0;
    virtual void enviarMensaje() = 0;
    virtual void cancelarMensaje() = 0;
    //CU AsistenciaEnDiferido en vivo
    virtual ICollection* listarAsignaturasCursando(string cedula) = 0;
    virtual ICollection* listarClasesEnVivoHabilitado(string codigoAsignatura) = 0;
    virtual DtClase* seleccionarClase(int numeroClase) = 0;
    virtual void confirmarAsistencia() = 0;
    virtual void cancelarAsistencia() = 0;
    //CU reproduccion en diferido
    virtual ICollection* listarClasesEnDiferido(string codigoAsignatura) = 0;
    virtual ICollection* confirmarReproduccion() = 0;
    virtual void cancelarReproduccion() = 0;
    //CU listado de clases
    virtual ICollection* listarClases(string codigoAsignatura) = 0;
    //CU tiempo de dictado = listarAsignaturas()
    //CU tiempo AsistenciaEnDiferido 
    virtual ICollection* listarClasesDictadas(string codigoAsignatura) = 0;

    virtual void cargarDatosClases() = 0;
};

#endif
