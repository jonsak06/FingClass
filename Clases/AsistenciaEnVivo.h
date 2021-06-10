#ifndef ASISTENCIAENVIVO_H
#define ASISTENCIAENVIVO_H

#include "../Datatypes/FechaHora.h"
#include "Estudiante.h"

using namespace std;

class Estudiante;

class AsistenciaEnVivo : public ICollectible
{
private:
    Estudiante* estudiante;
    FechaHora fechaHoraInicio;
    FechaHora fechaHoraFin;
public:
    AsistenciaEnVivo();
    ~AsistenciaEnVivo();
    AsistenciaEnVivo(Estudiante*);
    Estudiante* getEstudiante() const;
    FechaHora getFechaHoraInicio() const;
    FechaHora getFechaHoraFin() const;
    void setEstudiante(Estudiante*);
    void setFechaHoraInicio(FechaHora);
    void setFechaHoraFin(FechaHora);
};

#endif