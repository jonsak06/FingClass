#include "Asignacion.h"

Asignacion::Asignacion()
{
}

Asignacion::~Asignacion()
{
}

Asignacion::Asignacion(Asignatura *asignatura, TipoClase rolDictado)
{
    this->asignatura = asignatura;
    this->rolDictado = rolDictado;
}

TipoClase Asignacion::getRolDictado() const
{
    return rolDictado;
}
Asignatura *Asignacion::getAsignatura() const
{
    return asignatura;
}

void Asignacion::setRolDictado(TipoClase rolDictado)
{
    this->rolDictado = rolDictado;
}

void Asignacion::setAsignatura(Asignatura *asignatura)
{
    this->asignatura = asignatura;
}

string Asignacion::getCodigoAsignatura()
{
    return asignatura->getCodigoAsignatura();
}

DtAsignatura *Asignacion::getDatosAsignatura() const
{
    return asignatura->getDatosAsignatura();
}