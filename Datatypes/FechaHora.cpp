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