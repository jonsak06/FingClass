#include "Reloj.h"

Reloj::Reloj()
{
    fechaHoraActual = new FechaHora(27, 6, 21, 16, 0, 0);
}

Reloj &Reloj::getInstance()
{
    static Reloj *reloj = new Reloj();
    return *reloj;
}

FechaHora *Reloj::getFechaHoraActual() const
{
    return fechaHoraActual;
}

void Reloj::setFechaHoraActual(FechaHora *fechaHoraActual)
{
    this->fechaHoraActual = fechaHoraActual;
}