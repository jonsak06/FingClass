#ifndef MONITOREO_H
#define MONITOREO_H

#include "Clase.h"

class Monitoreo : public Clase
{
private:
    Estudiante estudiantesHabilitados[14]; //???
public:
    Monitoreo();
    Monitoreo(string, int, DtFechaHora);
    Estudiante* getEstudiantesHabilitados();
    void setEstudiantesHabilitados(Estudiante*);
};

#endif
