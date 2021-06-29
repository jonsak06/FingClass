#include "Practico.h"

Practico::Practico()
{
}

Practico::Practico(int numero, string nombre, FechaHora fechaHoraComienzo) : Clase(numero, nombre, fechaHoraComienzo)
{
}

DtClase *Practico::getDatosClase() const
{
    return new DtPractico(getNumeroClase(), getNombreClase(), getFechaHoraComienzo(), getNombreDocente(), getPromedioTiempoAsistencia());
}