#include "Teorico.h"

Teorico::Teorico() {
    this->cantAsistentes = 0;
}

Teorico::Teorico(string nombre, int numero, FechaHora fechaHoraComienzo) : Clase(nombre, numero, fechaHoraComienzo) {
    this->cantAsistentes = 0;
}

int Teorico::getCantAsistentes() const {
    return cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes) {
    this->cantAsistentes = cantAsistentes;
}

DtTeorico* Teorico::getDatosClase() const {}