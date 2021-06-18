#include "DtTeorico.h"

DtTeorico::DtTeorico() {

}

DtTeorico::DtTeorico(int numeroClase, string nombreClase) : DtClase(numeroClase, nombreClase) {

}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura)
                    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura) {

}

DtTeorico::DtTeorico(int numeroClase, string nombreClase, IDictionary* docentes, int cantAsistentes) 
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
