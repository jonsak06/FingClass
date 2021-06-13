#include "FechaHora.h"

FechaHora::FechaHora() {
}

FechaHora::~FechaHora() {
}

FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

int FechaHora::getDia() const {
    return dia;
}

int FechaHora::getMes() const {
    return mes;
}

int FechaHora::getAnio() const {
    return anio;
}

int FechaHora::getHora() const {
    return hora;
}

int FechaHora::getMinuto() const {
    return minuto;
}

int FechaHora::getSegundo() const {
    return minuto;
}
