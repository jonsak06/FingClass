#include "Monitoreo.h"

Monitoreo::Monitoreo() {
}

Monitoreo::Monitoreo(string nombre, int numero, DtFechaHora fechaHoraComienzo) : Clase(nombre, numero, fechaHoraComienzo) {
}

ColEstudiantes Monitoreo::getEstudiantesHabilitados() const {
    return estudiantesHabilitados;
}

void Monitoreo::setEstudiantesHabilitados(ColEstudiantes estudiantesHabilitados) {
    this->estudiantesHabilitados = estudiantesHabilitados;
}