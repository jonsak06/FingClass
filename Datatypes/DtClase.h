#ifndef DTCLASE_H
#define DTCLASE_H

#include "../Datatypes/FechaHora.h"
#include "../ICollection/interfaces/IDictionary.h"
#include <string>

using namespace std;

class DtClase : public ICollectible
{
private:
    int numeroClase;
    string nombreClase;
    FechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    FechaHora fechaHoraFinalizacion;
    float promedioTiempoAsistencia;
    string codigoAsignatura;
    IDictionary* docentes; //nombre de docentes que la dictaron
public:
    DtClase();
    virtual ~DtClase() = 0;
    DtClase(int numeroClase, string nombreClase);
    DtClase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtClase(int numeroClase, string nombreClase, IDictionary* docentes);
    DtClase(int numeroClase, string nombreClase, float promedioTiempoAsistencia);
    int getNumeroClase() const;
    string getNombreClase() const;
    FechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    FechaHora getFechaHoraFinalizacion() const;
    float getPromedioTiempoAsistencia() const;
    string getCodigoAsignatura() const;
    IDictionary* getDocentes() const;
};

#endif
