#include "Reloj.h"

Reloj& Reloj::getInstance() {
    static Reloj* reloj = new Reloj();
    return *reloj;
}

FechaHora* Reloj::getFechaHoraActual() const {
    return fechaHoraActual;
}

void Reloj::setFechaHoraActual(FechaHora* fechaHoraActual) {
    this->fechaHoraActual = fechaHoraActual;
}