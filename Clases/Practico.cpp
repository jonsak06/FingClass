#include "Practico.h"

Practico::Practico() {
}

Practico::Practico(string nombre, int numero, FechaHora fechaHoraComienzo) : Clase(nombre, numero, fechaHoraComienzo) {
}

DtPractico* Practico::getDatosClase() const {}