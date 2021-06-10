#ifndef MONITOREO_H
#define MONITOREO_H

#include "Clase.h"
#include "../Datatypes/DtMonitoreo.h"

class Monitoreo : public Clase
{
private:
    IDictionary* estudiantesHabilitados;
public:
    Monitoreo();
    Monitoreo(string, int, FechaHora, IDictionary*);
    IDictionary* getEstudiantesHabilitados();
    void setEstudiantesHabilitados(IDictionary*);
    //operaciones DCD
    DtMonitoreo* getDatosClase() const;
};

#endif
