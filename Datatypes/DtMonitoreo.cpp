#include "DtMonitoreo.h"

DtMonitoreo::DtMonitoreo()
{
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura)
{
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string nombreDocente, double promedioTiempoAsistencia, ICollection *estudiantes)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, nombreDocente, promedioTiempoAsistencia)
{
    this->estudiantes = estudiantes;
}

ICollection *DtMonitoreo::getEstudiantes() const
{
    return estudiantes;
}

string DtMonitoreo::getTipoClase() const
{
    return tipoClase;
}

void DtMonitoreo::mostrarInfo(ostream &)
{
    FechaHora *fh = new FechaHora(getFechaHoraComienzo());
    cout << endl;
    cout << "Numero: " << getNumeroClase() << endl;
    cout << "Nombre: " << getNombreClase() << endl;
    cout << "Fecha y hora de comienzo: " << fh << endl;
    delete fh;
}