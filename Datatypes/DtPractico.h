#ifndef DTPRACTICO_H
#define DTPRACTICO_H

#include "DtClase.h"
#include "../ICollection/interfaces/IDictionary.h"

class DtPractico : public DtClase
{
private:
    string tipoClase = "practico";

public:
    DtPractico();
    DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string codigoAsignatura);
    DtPractico(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo, string nombreDocente, double promedioTiempoAsistencia);
    string getTipoClase() const;
    void mostrarInfo(ostream &);
};

#endif
