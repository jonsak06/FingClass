#include "DtMonitoreo.h"

DtMonitoreo::DtMonitoreo() {

}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase) : DtClase(numeroClase, nombreClase) {

}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura) 
                        : DtClase(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura) {

}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, IDictionary* docentes, IDictionary* estudiantes) 
                        : DtClase(numeroClase, nombreClase, docentes) {
    this->estudiantes = estudiantes;
}

DtMonitoreo::DtMonitoreo(int numeroClase, string nombreClase, float promedioTiempoAsistencia) 
                        : DtClase(numeroClase, nombreClase, promedioTiempoAsistencia) {

}

IDictionary* DtMonitoreo::getEstudiantes() const {
    return estudiantes;
}

string DtMonitoreo::getTipoClase() const {
    return tipoClase;
}
