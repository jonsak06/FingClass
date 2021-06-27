#ifndef ASISTENCIAENVIVO_H
#define ASISTENCIAENVIVO_H

#include "../Datatypes/FechaHora.h"
#include <string>

class Estudiante;

using namespace std;

class AsistenciaEnVivo : public ICollectible
{
private:
    Estudiante* estudiante;
    FechaHora fechaHoraInicio;
    FechaHora* fechaHoraFin;
public:
    AsistenciaEnVivo();
    ~AsistenciaEnVivo();
    AsistenciaEnVivo(Estudiante*);
    Estudiante* getEstudiante() const;
    FechaHora getFechaHoraInicio() const;
    FechaHora* getFechaHoraFin() const;
    void setEstudiante(Estudiante*);
    void setFechaHoraInicio(FechaHora);
    void setFechaHoraFin(FechaHora*);

    //operaciones DCD
    bool comprobarAsistencia(string cedula) const;
};

#endif