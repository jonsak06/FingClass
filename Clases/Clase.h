#ifndef CLASE_H
#define CLASE_H

#include "Docente.h"
#include "../Datatypes/DtFechaHora.h"

class Clase
{
private:
    string nombre;
    int numero;
    DtFechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    DtFechaHora fechaHoraFinalizacion;
public:
    Clase();
    ~Clase();
    Clase(string, int, DtFechaHora);
    string getNombre() const;
    int getNumero() const;
    DtFechaHora getFechaHoraComienzo() const;
    bool getEnVivo() const;
    string getUrlGrabacion() const;
    DtFechaHora getFechaHoraFinalizacion() const;
    void setNombre(string);
    void setNumero(int);
    void setFechaHoraComienzo(DtFechaHora);
    void setEnVivo(bool);
    void setUrlGrabacion(string);
    void setFechaHoraFinalizacion(DtFechaHora);
};

#endif
