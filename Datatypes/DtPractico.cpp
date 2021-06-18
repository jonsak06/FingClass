#include "DtPractico.h"

DtPractico::DtPractico() {

}

DtPractico::DtPractico(int numeroClase, string nombreClase) : DtClase(numeroClase, nombreClase) {

}

DtPractico::DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura) 
                    : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura) {

}

DtPractico::DtPractico(int numeroClase, string nombreClase, IDictionary* docentes) : DtClase(numeroClase, nombreClase, docentes) {

}

DtPractico::DtPractico(int numeroClase, string nombreClase, float promedioTiempoAsistencia) 
                    : DtClase(numeroClase, nombreClase, promedioTiempoAsistencia) {

}

string DtPractico::getTipoClase() const {
    return tipoClase;
}
