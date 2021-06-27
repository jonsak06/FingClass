#include "DtMonitoreo.h"

DtMonitoreo::DtMonitoreo()
{
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase) : DtClase(numeroClase, nombreClase)
{
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura)
{
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, ICollection *docentes, ICollection *estudiantes)
    : DtClase(numeroClase, nombreClase, docentes)
{
    this->estudiantes = estudiantes;
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, float promedioTiempoAsistencia)
    : DtClase(numeroClase, nombreClase, promedioTiempoAsistencia)
{
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
    cout << "Codigo de asignatura: " << getCodigoAsignatura() << endl;
    cout << "Fecha y hora de comienzo: " << fh << endl;
    delete fh;
}