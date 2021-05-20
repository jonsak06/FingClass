#ifndef MONITOREO_H
#define MONITOREO_H

#include "Clase.h"

class Monitoreo : public Clase
{
private:
    ColEstudiantes estudiantesHabilitados; //???
public:
    Monitoreo();
    Monitoreo(string, int, DtFechaHora);
    ColEstudiantes getEstudiantesHabilitados() const;
    void setEstudiantesHabilitados(ColEstudiantes);
};

#endif
