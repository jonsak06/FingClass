#ifndef ASISTENCIAENDIFERIDO_H
#define ASISTENCIAENDIFERIDO_H

#include "../Datatypes/FechaHora.h"
#include "Estudiante.h"
#include <vector>

using namespace std;

class AsistenciaEnDiferido
{
private:
    Estudiante* estudiante;
    vector<FechaHora> fechaHoraInicio;
    vector<FechaHora> fechaHoraFin;
public:
    AsistenciaEnDiferido();
    ~AsistenciaEnDiferido();
    AsistenciaEnDiferido(Estudiante*);
    Estudiante* getEstudiante() const;
    vector<FechaHora> getFechaHoraInicio() const;
    vector<FechaHora> getFechaHoraFin() const;
    void setEstudiante(Estudiante*);
    void setFechaHoraInicio(vector<FechaHora>);
    void setFechaHoraFin(vector<FechaHora>);
    //operaciones DCD
    bool comprobarAsistencia(string cedula);
};

#endif