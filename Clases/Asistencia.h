#ifndef ASISTENCIA_H
#define ASISTENCIA_H

#include "Clase.h"
#include "Estudiante.h"
#include "../Colecciones/ColFechaHora.h"

using namespace std;

class Asistencia
{
private:
    Estudiante* estudiante;
    Clase* clase;
    ColFechaHora fechaHoraInicio;
    ColFechaHora fechaHoraFin;
public:
    Asistencia();
    ~Asistencia();
    Asistencia(Estudiante*, Clase*);
    Estudiante* getEstudiante() const;
    Clase* getClase() const;
    ColFechaHora getFechaHoraInicio() const;
    ColFechaHora getFechaHoraFin() const;
    void setEstudiante(Estudiante*);
    void setClase(Clase*);
    void setFechaHoraInicio(ColFechaHora);
    void setFechaHoraFin(ColFechaHora);
};

#endif