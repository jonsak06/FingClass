#include "FechaHora.h"

FechaHora::FechaHora()
{
}

FechaHora::~FechaHora()
{
}

FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

int FechaHora::getDia() const
{
    return dia;
}

int FechaHora::getMes() const
{
    return mes;
}

int FechaHora::getAnio() const
{
    return anio;
}

int FechaHora::getHora() const
{
    return hora;
}

int FechaHora::getMinuto() const
{
    return minuto;
}

int FechaHora::getSegundo() const
{
    return segundo;
}

void FechaHora::mostrarInfo(ostream &)
{
    cout << endl;
    cout << "   Fecha: " << getDia() << "/" << getMes() << "/" << getAnio() << endl;
    cout << "   Hora: " << getHora() << ":" << getMinuto() << ":" << getSegundo() << endl;
}

ostream &operator<<(ostream &salida, FechaHora *fh)
{
    fh->mostrarInfo(salida);
    return salida;
}