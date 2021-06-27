#include "DtTeorico.h"

DtTeorico::DtTeorico() {

}

DtTeorico::DtTeorico(int numeroClase, string nombreClase) : DtClase(numeroClase, nombreClase) {

}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
                    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura) {

}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, ICollection* docentes, int cantAsistentes) 
                    : DtClase(numeroClase, nombreClase, docentes) {
    this->cantAsistentes = cantAsistentes;
}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, float promedioTiempoAsistencia) 
                    : DtClase(numeroClase, nombreClase, promedioTiempoAsistencia)  {

}

int DtTeorico::getCantAsistentes() const {
    return cantAsistentes;
}

string DtTeorico::getTipoClase() const {
    return tipoClase;
}

void DtTeorico::mostrarInfo(ostream&) {
    FechaHora *fh = new FechaHora(getFechaHoraComienzo());
    cout << endl;
    cout << "Numero: " << getNumeroClase() << endl;
    cout << "Nombre: " << getNombreClase() << endl;
    cout << "Codigo de asignatura: " << getCodigoAsignatura() << endl;
    cout << "Fecha y hora de comienzo: " << fh << endl;
    delete fh;
}