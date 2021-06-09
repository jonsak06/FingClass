#include "Monitoreo.h"

Monitoreo::Monitoreo() {
}

Monitoreo::Monitoreo(string nombre, int numero, FechaHora fechaHoraComienzo, vector<Estudiante> habilitados) 
                    : Clase(nombre, numero, fechaHoraComienzo) {
    estudiantesHabilitados = habilitados;
}

vector<Estudiante> Monitoreo::getEstudiantesHabilitados() {
    return estudiantesHabilitados;
}

void Monitoreo::setEstudiantesHabilitados(vector<Estudiante> habilitados) {
    estudiantesHabilitados = habilitados;
}

DtMonitoreo* Monitoreo::getDatosClase() const {}