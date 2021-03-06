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
    IClases() {}
    virtual ~IClases() {}
    virtual IDictionary *listarAsignaturasAsignadas(string email) = 0;
    virtual TipoClase crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo) = 0;
    virtual IDictionary *listarEstudiantesInscriptos() = 0;
    virtual void habilitarEstudiante(string cedula) = 0;
    virtual DtClase *obtenerInfoClase() = 0;
    virtual void confirmarInicioClase() = 0;
    virtual void cancelarInicioClase() = 0;
    virtual IDictionary *listarClasesEnVivo(string email) = 0;
    virtual DtClase *seleccionarClaseDocente(int numeroClase) = 0;
    virtual void confirmarFinalizacionClase() = 0;
    virtual void cancelarFinalizacionClase() = 0;
    virtual IDictionary *listarClasesEnVivoParticipando(string email) = 0;
    virtual IDictionary *listarMensajes(int numeroClase) = 0;
    virtual void responderMensaje(int idMensaje, string mensaje) = 0;
    virtual void escribirMensaje(string mensaje) = 0;
    virtual void enviarMensaje() = 0;
    virtual void cancelarMensaje() = 0;
    virtual IDictionary *listarAsignaturasCursando(string cedula) = 0;
    virtual IDictionary *listarClasesEnVivoHabilitado(string codigoAsignatura) = 0;
    virtual DtClase *seleccionarClase(int numeroClase) = 0;
    virtual void confirmarAsistencia() = 0;
    virtual void cancelarAsistencia() = 0;
    virtual IDictionary *listarClasesEnDiferido(string codigoAsignatura) = 0;
    virtual IDictionary *confirmarReproduccion() = 0;
    virtual void cancelarReproduccion() = 0;
    virtual IDictionary *listarClases(string codigoAsignatura) = 0;
    virtual IDictionary *listarAsignaturas() = 0;

    virtual void cargarDatosClases() = 0;
};

#endif
