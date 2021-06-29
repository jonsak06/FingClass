#include "Monitoreo.h"
#include "Estudiante.h"

Monitoreo::Monitoreo()
{
}

Monitoreo::~Monitoreo()
{
    delete estudiantesHabilitados;
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
    ICollection *nombresEstudiantes = new List;
    IIterator *it = estudiantesHabilitados->getIterator();
    Estudiante *e;
    for (it; it->hasCurrent(); it->next())
    {
        e = dynamic_cast<Estudiante *>(it->getCurrent());
        nombresEstudiantes->add(new String(e->getNombre()));
    }
    delete it;
    return new DtMonitoreo(getNumeroClase(), getNombreClase(), getFechaHoraComienzo(), getNombreDocente(), getPromedioTiempoAsistencia(), nombresEstudiantes);
}

bool Monitoreo::estaHabilitado(string cedula)
{
    IKey *k = new String(cedula);
    bool habilitado = estudiantesHabilitados->member(k);
    delete k;
    return habilitado;
}
