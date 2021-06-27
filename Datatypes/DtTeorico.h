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
    DtTeorico(int numeroClase, string nombreClase);
    DtTeorico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtTeorico(int numeroClase, string nombreClase, ICollection* docentes, int cantAsistentes);
    DtTeorico(int numeroClase, string nombreClase, float promedioTiempoAsistencia);
    int getCantAsistentes() const;
    string getTipoClase() const;
    void mostrarInfo(ostream&);
};

#endif
