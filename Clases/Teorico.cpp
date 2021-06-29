#include "Teorico.h"

Teorico::Teorico()
{
    cantAsistentes = 0;
}

Teorico::Teorico(int numero, string nombre, FechaHora fechaHoraComienzo) : Clase(numero, nombre, fechaHoraComienzo)
{
    cantAsistentes = 0;
}

int Teorico::getCantAsistentes() const
{
    return cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes)
{
    this->cantAsistentes = cantAsistentes;
}

DtClase *Teorico::getDatosClase() const
{
    return new DtTeorico(getNumeroClase(), getNombreClase(), getFechaHoraComienzo(), getNombreDocente(), getPromedioTiempoAsistencia(), getCantAsistentes());
}

void Teorico::finalizarClase()
{
    Clase::finalizarClase();
    cantAsistentes = getAsistenciasEnVivo()->getSize();
}