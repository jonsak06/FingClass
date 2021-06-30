#ifndef DTTEORICO_H
#define DTTEORICO_H

#include "DtClase.h"

class DtTeorico : public DtClase
{
private:
    int cantAsistentes;
    string tipoClase = "teorico";

public:
    DtTeorico();
    DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string docente, double promedioTiempoAsistencia, int cantAsistentes);
    int getCantAsistentes() const;
    string getTipoClase() const;
    void mostrarInfo(ostream &);
};

#endif
