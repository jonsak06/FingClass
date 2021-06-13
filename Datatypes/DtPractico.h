#ifndef DTPRACTICO_H
#define DTPRACTICO_H

#include "DtClase.h"

class DtPractico : public DtClase
{
private:
    string tipoClase = "practico";
public:
    DtPractico();
    DtPractico(int numeroClase, string nombreClase);
    DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtPractico(int numeroClase, string nombreClase, ICollection* docentes);
    DtPractico(int numeroClase, string nombreClase, float promedioTiempoAsistencia);
    string getTipoClase() const;
};

#endif
