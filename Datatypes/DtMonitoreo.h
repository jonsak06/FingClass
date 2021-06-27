#ifndef DTMONITOREO_H
#define DTMONITOREO_H

#include "DtClase.h"
#include "../ICollection/interfaces/IDictionary.h"

class DtMonitoreo : public DtClase
{
private:
    ICollection* estudiantes; //nombres de estudiantes que asistieron
    string tipoClase = "monitoreo";
public:
    DtMonitoreo();
    DtMonitoreo(int numeroClase, string nombreClase);
    DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtMonitoreo(int numeroClase, string nombreClase, ICollection* docentes, ICollection* estudiantes);
    DtMonitoreo(int numeroClase, string nombreClase, float promedioTiempoAsistencia);
    ICollection* getEstudiantes() const;
    string getTipoClase() const;
    void mostrarInfo(ostream&);
};

#endif
