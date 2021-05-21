#include "Monitoreo.h"

Monitoreo::Monitoreo() {
}

Monitoreo::Monitoreo(string nombre, int numero, DtFechaHora fechaHoraComienzo) : Clase(nombre, numero, fechaHoraComienzo) {
}

Estudiante* Monitoreo::getEstudiantesHabilitados() {
    return estudiantesHabilitados;
}

void Monitoreo::setEstudiantesHabilitados(Estudiante* estudiantesHabilitados) {
    // hacer
}