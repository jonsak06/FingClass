#include "AsistenciaEnDiferido.h"
#include "Estudiante.h"

AsistenciaEnDiferido::AsistenciaEnDiferido()
{
    fechaHoraInicio = new List;
    fechaHoraFin = new List;
}

AsistenciaEnDiferido::~AsistenciaEnDiferido()
{
    delete fechaHoraFin, fechaHoraInicio;
}

AsistenciaEnDiferido::AsistenciaEnDiferido(Estudiante *estudiante, FechaHora *fh)
{
    fechaHoraInicio = new List;
    fechaHoraFin = new List;
    this->estudiante = estudiante;
    fechaHoraInicio->add(fh);
}

Estudiante *AsistenciaEnDiferido::getEstudiante() const
{
    return estudiante;
}

ICollection *AsistenciaEnDiferido::getFechaHoraInicio() const
{
    return fechaHoraInicio;
}

ICollection *AsistenciaEnDiferido::getFechaHoraFin() const
{
    return fechaHoraFin;
}

void AsistenciaEnDiferido::setEstudiante(Estudiante *estudiante)
{
    this->estudiante = estudiante;
}

void AsistenciaEnDiferido::setFechaHoraInicio(ICollection *fechaHoraInicio)
{
    this->fechaHoraInicio = fechaHoraInicio;
}

void AsistenciaEnDiferido::setFechaHoraFin(ICollection *fechaHoraFin)
{
    this->fechaHoraFin = fechaHoraFin;
}

bool AsistenciaEnDiferido::comprobarAsistencia(string cedula) const
{
    return cedula == estudiante->getCedula();
}

void AsistenciaEnDiferido::agregarFechaHoraInicio(FechaHora *fh)
{
    fechaHoraInicio->add(fh);
}

void AsistenciaEnDiferido::agregarFechaHoraFin(FechaHora *fh)
{
    fechaHoraFin->add(fh);
}