#ifndef ASISTENCIAENDIFERIDO_H
#define ASISTENCIAENDIFERIDO_H

#include "../Datatypes/FechaHora.h"
#include "Estudiante.h"
#include "../ICollection/interfaces/ICollection.h"

using namespace std;

class Estudiante;

class AsistenciaEnDiferido : public ICollectible
{
private:
    Estudiante* estudiante;
    ICollection* fechaHoraInicio;
    ICollection* fechaHoraFin;
public:
    AsistenciaEnDiferido();
    ~AsistenciaEnDiferido();
    AsistenciaEnDiferido(Estudiante*);
    Estudiante* getEstudiante() const;
    ICollection* getFechaHoraInicio() const;
    ICollection* getFechaHoraFin() const;
    void setEstudiante(Estudiante*);
    void setFechaHoraInicio(ICollection*);
    void setFechaHoraFin(ICollection*);

    //operaciones DCD
    bool comprobarAsistencia(string cedula);
};

#endif