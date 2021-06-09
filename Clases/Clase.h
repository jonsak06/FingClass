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
#include <vector>
#include <string>

using namespace std;

class Asignatura;

class Clase
{
private:
    string nombreClase;
    int numeroClase;
    FechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    FechaHora fechaHoraFinalizacion;
    float promedioTiempoAsistenciaEnDiferido;
    vector<AsistenciaEnDiferido> asistenciasEnDiferido;
    vector<AsistenciaEnVivo> asistenciasEnVivo;
    vector<Mensaje> mensajes;
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
    vector<AsistenciaEnDiferido> getAsistenciasEnDiferido() const;
    vector<AsistenciaEnVivo> getAsistenciasEnVivo() const;
    vector<Mensaje> getMensajes() const;
    Asignatura* getAsignatura() const;
    void setNombreClase(string);
    void setNumeroClase(int);
    void setFechaHoraComienzo(FechaHora);
    void setEnVivo(bool);
    void setUrlGrabacion(string);
    void setFechaHoraFinalizacion(FechaHora);
    void setPromedioTiempoAsistenciaEnDiferido(float);
    void setAsistenciasEnDiferido(vector<AsistenciaEnDiferido>);
    void setAsistenciasEnVivo(vector<AsistenciaEnVivo>);
    void setMensajes(vector<Mensaje>);
    void setAsignatura(Asignatura*);
    //operaciones DCD
    virtual DtClase* getDatosClase() const = 0;
    void finalizarClase();
    void setInicioAsistenciaEnDiferido(Estudiante);
    vector<DtMensaje> getDatosMensajes() const;
    string getCodigoAsignatura() const;
    void eliminarAsistencias();
    void eliminarMensajes();
};

#endif
