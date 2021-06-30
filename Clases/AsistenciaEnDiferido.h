#ifndef ASISTENCIAENDIFERIDO_H
#define ASISTENCIAENDIFERIDO_H

#include "../Datatypes/FechaHora.h"
#include "../ICollection/interfaces/ICollection.h"
#include <string>

class Estudiante;

using namespace std;

class AsistenciaEnDiferido : public ICollectible
{
private:
    Estudiante *estudiante;
    ICollection *fechaHoraInicio;
    ICollection *fechaHoraFin;

public:
    AsistenciaEnDiferido();
    ~AsistenciaEnDiferido();
    AsistenciaEnDiferido(Estudiante *, FechaHora *);
    Estudiante *getEstudiante() const;
    ICollection *getFechaHoraInicio() const;
    ICollection *getFechaHoraFin() const;
    void setEstudiante(Estudiante *);
    void setFechaHoraInicio(ICollection *);
    void setFechaHoraFin(ICollection *);

    bool comprobarAsistencia(string cedula) const;
    void agregarFechaHoraInicio(FechaHora *fh);
};

#endif