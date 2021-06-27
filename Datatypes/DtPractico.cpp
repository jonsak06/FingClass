#include "DtPractico.h"

DtPractico::DtPractico() {

}

DtPractico::DtPractico(int numeroClase, string nombreClase) : DtClase(numeroClase, nombreClase) {

}

DtPractico::DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura) 
                    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura) {

}

DtPractico::DtPractico(int numeroClase, string nombreClase, ICollection* docentes) : DtClase(numeroClase, nombreClase, docentes) {

}

DtPractico::DtPractico(int numeroClase, string nombreClase, float promedioTiempoAsistencia) 
                    : DtClase(numeroClase, nombreClase, promedioTiempoAsistencia) {

}

string DtPractico::getTipoClase() const {
    return tipoClase;
}

void DtPractico::mostrarInfo(ostream&) {
    FechaHora *fh = new FechaHora(getFechaHoraComienzo());
    cout << endl;
    cout << "Numero: " << getNumeroClase() << endl;
    cout << "Nombre: " << getNombreClase() << endl;
    cout << "Codigo de asignatura: " << getCodigoAsignatura() << endl;
    cout << "Fecha y hora de comienzo: " << fh << endl;
    delete fh;
}