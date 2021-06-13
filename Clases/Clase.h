#ifndef CLASE_H
#define CLASE_H

#include "../Datatypes/FechaHora.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"
#include "Estudiante.h"
#include "AsistenciaEnDiferido.h"
#include "AsistenciaEnVivo.h"
#include "Mensaje.h"
#include "Asignatura.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include <string>

using namespace std;

class Asignatura;
// class AsistenciaEnVivo;
// class AsistenciaEnDiferido;
// class Mensaje;
// class Estudiante;
class Usuario;

class Clase : public ICollectible
{
private:
    string nombreClase;
    int numeroClase;
    FechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    FechaHora fechaHoraFinalizacion;
    float promedioTiempoAsistenciaEnDiferido;
    ICollection* asistenciasEnDiferido;
    ICollection* asistenciasEnVivo;
    IDictionary* mensajes;
    Asignatura* asignatura;
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
    float getPromedioTiempoAsistenciaEnDiferido() const;
    ICollection* getAsistenciasEnDiferido() const;
    ICollection* getAsistenciasEnVivo() const;
    IDictionary* getMensajes() const;
    Asignatura* getAsignatura() const;
    void setNombreClase(string);
    void setNumeroClase(int);
    void setFechaHoraComienzo(FechaHora);
    void setEnVivo(bool);
    void setUrlGrabacion(string);
    void setFechaHoraFinalizacion(FechaHora);
    void setPromedioTiempoAsistenciaEnDiferido(float);
    void setAsistenciasEnDiferido(ICollection*);
    void setAsistenciasEnVivo(ICollection*);
    void setMensajes(IDictionary*);
    void setAsignatura(Asignatura*);

    //operaciones DCD
    virtual DtClase* getDatosClase() const = 0;
    void finalizarClase();
    void setInicioAsistenciaEnDiferido(Estudiante e);
    ICollection* getDatosMensajes() const;
    string getCodigoAsignatura() const;
    void eliminarAsistencias();
    void eliminarMensajes();
    Mensaje getMensaje(int idMensaje) const;
    void enviarMensaje(Usuario* u, string mensaje);
    void responderMensaje(Usuario* u, Mensaje m, string mensaje);
    void marcarAsistenciaVivo(Estudiante e);
    void marcarAsistenciaDif(Estudiante e);
};

#endif
