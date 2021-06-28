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
    return new DtTeorico(getNumeroClase(), getNombreClase(), getFechaHoraComienzo(), getCodigoAsignatura());
}

void Teorico::finalizarClase() {
    Reloj &reloj = Reloj::getInstance();
    IIterator* it = getAsistenciasEnVivo()->getIterator();
    AsistenciaEnVivo *asisVivo;
    for(it; it->hasCurrent(); it->next()) {
        asisVivo = dynamic_cast<AsistenciaEnVivo*>(it->getCurrent());
        if (asisVivo->getFechaHoraFin() == nullptr)
        {
            asisVivo->setFechaHoraFin(reloj.getFechaHoraActual());
        }
        cantAsistentes++;
    }
    setEnVivo(false);
    setUrlGrabacion(generarUrlGrabacion());
    setFechaHoraFinalizacion(*reloj.getFechaHoraActual());
    delete it;
}