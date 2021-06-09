#ifndef MONITOREO_H
#define MONITOREO_H

#include "Clase.h"
#include "../Datatypes/DtMonitoreo.h"

class Monitoreo : public Clase
{
private:
    vector<Estudiante> estudiantesHabilitados;
public:
    Monitoreo();
    Monitoreo(string, int, FechaHora, vector<Estudiante>);
    vector<Estudiante> getEstudiantesHabilitados();
    void setEstudiantesHabilitados(vector<Estudiante>);
    //operaciones DCD
    DtMonitoreo* getDatosClase() const;
};

#endif
