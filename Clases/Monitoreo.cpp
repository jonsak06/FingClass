#include "Monitoreo.h"

Monitoreo::Monitoreo() {
}

Monitoreo::Monitoreo(string nombre, int numero, FechaHora fechaHoraComienzo, IDictionary* habilitados) 
                    : Clase(nombre, numero, fechaHoraComienzo) {
    estudiantesHabilitados = habilitados;
}

IDictionary* Monitoreo::getEstudiantesHabilitados() {
    return estudiantesHabilitados;
}

void Monitoreo::setEstudiantesHabilitados(IDictionary* habilitados) {
    estudiantesHabilitados = habilitados;
}

DtMonitoreo* Monitoreo::getDatosClase() const {}