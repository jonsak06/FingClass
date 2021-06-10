#ifndef DTCLASE_H
#define DTCLASE_H

#include "../Datatypes/FechaHora.h"
#include <string>

using namespace std;

class DtClase : public ICollectible
{
private:
    string nombre;
    int numero;
    FechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    FechaHora fechaHoraFinalizacion;
    float promedioTiempoAsistenciaEnDiferido;
public:
    DtClase();
    virtual ~DtClase() = 0;
    DtClase(string, int, FechaHora);
    DtClase(string, int, FechaHora, bool, string, FechaHora, float);
    string getNombre() const;
    int getNumero() const;
    FechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    FechaHora getFechaHoraFinalizacion() const;
    float getPromedioTiempoAsistenciaEnDiferido() const;
};

#endif
