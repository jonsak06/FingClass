#ifndef CLASE_H
#define CLASE_H

#include "AsistenciaEnVivo.h"
#include "AsistenciaEnDiferido.h"
#include "Mensaje.h"
#include "../Datatypes/FechaHora.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "../Otros/Reloj.h"
#include <string>

using namespace std;

class Estudiante;

class Clase : public ICollectible
{
private:
    string nombreClase;
    int numeroClase;
    FechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    FechaHora fechaHoraFinalizacion;
    double promedioTiempoAsistencia;
    ICollection *asistenciasEnDiferido;
    ICollection *asistenciasEnVivo;
    IDictionary *mensajes;
    string codigoAsignatura;
    string nombreDocente;

public:
    Clase();
    virtual ~Clase() = 0;
    Clase(int, string, FechaHora);
    string getNombreClase() const;
    int getNumeroClase() const;
    FechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    FechaHora getFechaHoraFinalizacion() const;
    double getPromedioTiempoAsistencia() const;
    ICollection *getAsistenciasEnDiferido() const;
    ICollection *getAsistenciasEnVivo() const;
    IDictionary *getMensajes() const;
    string getCodigoAsignatura() const;
    string getNombreDocente() const;
    void setNombreClase(string);
    void setNumeroClase(int);
    void setFechaHoraComienzo(FechaHora);
    void setEnVivo(bool);
    void setUrlGrabacion(string);
    void setFechaHoraFinalizacion(FechaHora);
    void setPromedioTiempoAsistencia(double);
    void setAsistenciasEnDiferido(ICollection *);
    void setAsistenciasEnVivo(ICollection *);
    void setMensajes(IDictionary *);
    void setCodigoAsignatura(string);
    void setNombreDocente(string);

    virtual DtClase *getDatosClase() const = 0;
    virtual void finalizarClase();
    void setInicioAsistenciaEnDiferido(Estudiante *e);
    IDictionary *getDatosMensajes() const;
    void eliminarAsistencias();
    void eliminarMensajes();
    Mensaje *getMensaje(int idMensaje) const;
    void enviarMensaje(Usuario *u, int idMensaje, string mensaje, FechaHora *fh);
    void responderMensaje(Usuario *u, int idMensaje, Mensaje *msjRespondido, string mensaje, FechaHora *fh);
    void marcarAsistenciaVivo(Estudiante *e, string cedula);
    void marcarAsistenciaDif(Estudiante *e, string cedula);
    string generarUrlGrabacion() const;
    bool comprobarAsistenciaEnVivo(string cedula);
    bool comprobarAsistenciaEnDiferido(string cedula);
    double getTiempoDictado() const;
    void finalizarReproduccion(string cedula);
};

#endif
