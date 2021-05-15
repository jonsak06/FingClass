#ifndef CLASE_H
#define CLASE_H

#include "../Datatypes/DtFechaHora.h"
#include <string>

using namespace std;

class Clase
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
    Clase();
    virtual ~Clase() = 0;
    Clase(string, int, DtFechaHora);
    string getNombre() const;
    int getNumero() const;
    DtFechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    DtFechaHora getFechaHoraFinalizacion() const;
    float getPromedioTiempoAsistencia() const;
    void setNombre(string);
    void setNumero(int);
    void setFechaHoraComienzo(DtFechaHora);
    void setEnVivo(bool);
    void setUrlGrabacion(string);
    void setFechaHoraFinalizacion(DtFechaHora);
    void setPromedioTiempoAsistencia(float);
};

#endif
