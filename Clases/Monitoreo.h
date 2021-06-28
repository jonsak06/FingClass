#ifndef MONITOREO_H
#define MONITOREO_H

#include "Clase.h"
#include "../Datatypes/DtMonitoreo.h"
#include "../ICollection/String.h"

class Monitoreo : public Clase
{
private:
    IDictionary* estudiantesHabilitados;
public:
    Monitoreo();
    Monitoreo(int, string, FechaHora, IDictionary*);
    IDictionary* getEstudiantesHabilitados();
    void setEstudiantesHabilitados(IDictionary*);
    
    //operaciones DCD
    DtClase* getDatosClase() const;
    bool estaHabilitado(string cedula);
};

#endif
