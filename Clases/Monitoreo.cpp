#include "Monitoreo.h"

Monitoreo::Monitoreo() {
}

Monitoreo::Monitoreo(int numero, string nombre, FechaHora fechaHoraComienzo, IDictionary* habilitados) 
                    : Clase(numero, nombre, fechaHoraComienzo) {
    estudiantesHabilitados = habilitados;
}

IDictionary* Monitoreo::getEstudiantesHabilitados() {
    return estudiantesHabilitados;
}

void Monitoreo::setEstudiantesHabilitados(IDictionary* habilitados) {
    estudiantesHabilitados = habilitados;
}

DtMonitoreo* Monitoreo::getDatosClase() const {}