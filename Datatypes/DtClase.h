#ifndef DTCLASE_H
#define DTCLASE_H

#include "../Datatypes/DtFechaHora.h"
#include <string>

using namespace std;

class DtClase
{
private:
    string nombre;
    int numero;
    DtFechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    DtFechaHora fechaHoraFinalizacion;
    float promedioTiempoAsistencia;
public:
    DtClase();
    virtual ~DtClase() = 0;
    DtClase(string, int, DtFechaHora);
    DtClase(string, int, DtFechaHora, bool, string, DtFechaHora, float);
    string getNombre() const;
    int getNumero() const;
    DtFechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    DtFechaHora getFechaHoraFinalizacion() const;
    float getPromedioTiempoAsistencia() const;
};

#endif
