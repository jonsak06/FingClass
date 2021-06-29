#ifndef DTMONITOREO_H
#define DTMONITOREO_H

#include "DtClase.h"
#include "../ICollection/interfaces/IDictionary.h"

class DtMonitoreo : public DtClase
{
private:
    ICollection* estudiantes;
    string tipoClase = "monitoreo";
public:
    DtMonitoreo();
    DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtMonitoreo(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string nombreDocente, double promedioTiempoAsistencia, ICollection* estudiantes);
    ICollection* getEstudiantes() const;
    string getTipoClase() const;
    void mostrarInfo(ostream&);
};

#endif
