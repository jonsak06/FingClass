#ifndef ASISTENCIA_H
#define ASISTENCIA_H

#include "Clase.h"
#include "Estudiante.h"
#include <vector>

using namespace std;

class Asistencia
{
private:
    Estudiante* estudiante;
    Clase* clase;
    vector<DtFechaHora> fechaHoraInicio;
    vector<DtFechaHora> fechaHoraFin;
public:
    Asistencia();
    ~Asistencia();
    Asistencia(Estudiante*, Clase*);
    Estudiante* getEstudiante() const;
    Clase* getClase() const;
    vector<DtFechaHora> getFechaHoraInicio() const;
    vector<DtFechaHora> getFechaHoraFin() const;
    void setEstudiante(Estudiante*);
    void setClase(Clase*);
    void setFechaHoraInicio(vector<DtFechaHora>);
    void setFechaHoraFin(vector<DtFechaHora>);
};

#endif