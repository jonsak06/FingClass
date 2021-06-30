#ifndef DTCLASE_H
#define DTCLASE_H

#include "../Datatypes/FechaHora.h"
#include "../ICollection/interfaces/ICollection.h"
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
    double promedioTiempoAsistencia;
    string codigoAsignatura;
    string nombreDocente;

public:
    DtClase();
    virtual ~DtClase() = 0;
    DtClase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtClase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string nombreDocente, double promedioTiempoAsistencia);
    int getNumeroClase() const;
    string getNombreClase() const;
    FechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    FechaHora getFechaHoraFinalizacion() const;
    double getPromedioTiempoAsistencia() const;
    string getCodigoAsignatura() const;
    string getNombreDocente() const;
    virtual void mostrarInfo(ostream &) = 0;
    friend ostream &operator<<(ostream &, DtClase *);
};

#endif
