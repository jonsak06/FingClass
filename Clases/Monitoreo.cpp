#include "Monitoreo.h"

Monitoreo::Monitoreo()
{
}

Monitoreo::Monitoreo(int numero, string nombre, FechaHora fechaHoraComienzo, IDictionary *habilitados)
    : Clase(numero, nombre, fechaHoraComienzo)
{
    estudiantesHabilitados = habilitados;
}

IDictionary *Monitoreo::getEstudiantesHabilitados()
{
    return estudiantesHabilitados;
}

void Monitoreo::setEstudiantesHabilitados(IDictionary *habilitados)
{
    estudiantesHabilitados = habilitados;
}

DtClase *Monitoreo::getDatosClase() const
{
    return new DtMonitoreo(getNumeroClase(), getNombreClase(), getFechaHoraComienzo(), getCodigoAsignatura());
}

bool Monitoreo::estaHabilitado(string cedula) {
    IKey *k = new String(cedula);
    bool habilitado = estudiantesHabilitados->member(k);
    delete k;
    return habilitado;
}
