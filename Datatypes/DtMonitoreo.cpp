#include "DtMonitoreo.h"

DtMonitoreo::DtMonitoreo()
{
    estudiantes = new List;
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura)
{
    estudiantes = new List;
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
    cout << endl;
    cout << "Numero: " << getNumeroClase() << endl;
    cout << "Nombre: " << getNombreClase() << endl;
    cout << "Docente: " << getNombreDocente() << endl;
    if (!getEstudiantes()->isEmpty())
    {
        cout << "Estudiantes habilitados:\n";
        IIterator *it = getEstudiantes()->getIterator();
        String *nomEst;
        for (it; it->hasCurrent(); it->next())
        {
            nomEst = dynamic_cast<String *>(it->getCurrent());
            cout << "    " << nomEst->getValue() << endl;
        }
    }
}