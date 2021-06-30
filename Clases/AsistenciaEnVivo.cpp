#include "AsistenciaEnVivo.h"
#include "Estudiante.h"

AsistenciaEnVivo::AsistenciaEnVivo()
{
}

AsistenciaEnVivo::~AsistenciaEnVivo()
{
    delete fechaHoraFin, fechaHoraInicio;
    estudiante = nullptr;
}

AsistenciaEnVivo::AsistenciaEnVivo(Estudiante *estudiante, FechaHora *fh)
{
    this->estudiante = estudiante;
    this->fechaHoraInicio = fh;
}

Estudiante *AsistenciaEnVivo::getEstudiante() const
{
    return estudiante;
}

FechaHora *AsistenciaEnVivo::getFechaHoraInicio() const
{
    return fechaHoraInicio;
}

FechaHora *AsistenciaEnVivo::getFechaHoraFin() const
{
    return fechaHoraFin;
}

void AsistenciaEnVivo::setEstudiante(Estudiante *estudiante)
{
    this->estudiante = estudiante;
}

void AsistenciaEnVivo::setFechaHoraInicio(FechaHora *fechaHoraInicio)
{
    this->fechaHoraInicio = fechaHoraInicio;
}

void AsistenciaEnVivo::setFechaHoraFin(FechaHora *fechaHoraFin)
{
    this->fechaHoraFin = fechaHoraFin;
}

bool AsistenciaEnVivo::comprobarAsistencia(string cedula) const
{
    return cedula == estudiante->getCedula();
}

double AsistenciaEnVivo::getTiempoAsistido() const
{
    return (fechaHoraFin->getHora() * 60 + fechaHoraFin->getMinuto()) - (fechaHoraInicio->getHora() * 60 + fechaHoraInicio->getMinuto());
}