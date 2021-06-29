#include "DtTeorico.h"

DtTeorico::DtTeorico()
{
}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura)
{
}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string docente, double promedioTiempoAsistencia, int cantAsistentes)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, docente, promedioTiempoAsistencia)
{
    this->cantAsistentes = cantAsistentes;
}

int DtTeorico::getCantAsistentes() const
{
    return cantAsistentes;
}

string DtTeorico::getTipoClase() const
{
    return tipoClase;
}

void DtTeorico::mostrarInfo(ostream &)
{
    FechaHora *fh = new FechaHora(getFechaHoraComienzo());
    cout << endl;
    cout << "Numero: " << getNumeroClase() << endl;
    cout << "Nombre: " << getNombreClase() << endl;
    cout << "Fecha y hora de comienzo: " << fh << endl;
    delete fh;
}