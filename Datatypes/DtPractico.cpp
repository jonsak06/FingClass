#include "DtPractico.h"

DtPractico::DtPractico()
{
}

DtPractico::DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura)
{
}

DtPractico::DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string nombreDocente, double promedioTiempoAsistencia)
    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, nombreDocente, promedioTiempoAsistencia)
{
}

string DtPractico::getTipoClase() const
{
    return tipoClase;
}

void DtPractico::mostrarInfo(ostream &)
{
    cout << endl;
    cout << "Numero: " << getNumeroClase() << endl;
    cout << "Nombre: " << getNombreClase() << endl;
}