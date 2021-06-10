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
#include <string>

using namespace std;

class Asignatura;
class AsistenciaEnVivo;
class AsistenciaEnDiferido;
class Mensaje;

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
    Clase(string, int, FechaHora);
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
    void setInicioAsistenciaEnDiferido(Estudiante);
    ICollection* getDatosMensajes() const;
    string getCodigoAsignatura() const;
    void eliminarAsistencias();
    void eliminarMensajes();
};

#endif
