#include "Mensaje.h"

Mensaje::Mensaje()
{
    mensajeRespondido = nullptr;
}

Mensaje::~Mensaje()
{
    usuario = nullptr;
    mensajeRespondido = nullptr;
}

Mensaje::Mensaje(Usuario *usuario, int idMensaje, Mensaje *mensajeRespondido, string mensaje, FechaHora *fh)
{
    this->usuario = usuario;
    this->idMensaje = idMensaje;
    this->mensajeRespondido = mensajeRespondido;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = *fh;
}

Mensaje::Mensaje(Usuario *usuario, int idMensaje, string mensaje, FechaHora *fh)
{
    mensajeRespondido = nullptr;
    this->usuario = usuario;
    this->idMensaje = idMensaje;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = *fh;
}

int Mensaje::getIdMensaje() const
{
    return idMensaje;
}

string Mensaje::getMensaje() const
{
    return mensaje;
}

FechaHora Mensaje::getFechaHoraEnvio() const
{
    return fechaHoraEnvio;
}

Usuario *Mensaje::getUsuario() const
{
    return usuario;
}

void Mensaje::setIdMensaje(int idMensaje)
{
    this->idMensaje = idMensaje;
}

void Mensaje::setMensaje(string mensaje)
{
    this->mensaje = mensaje;
}

void Mensaje::setFechaHoraEnvio(FechaHora fechaHoraEnvio)
{
    this->fechaHoraEnvio = fechaHoraEnvio;
}

void Mensaje::setUsuario(Usuario *usuario)
{
    this->usuario = usuario;
}

DtMensaje *Mensaje::getDatosMensaje() const
{
    if (mensajeRespondido != nullptr)
    {
        return new DtMensaje(idMensaje, mensaje, fechaHoraEnvio, mensajeRespondido->getIdMensaje());
    }
    return new DtMensaje(idMensaje, mensaje, fechaHoraEnvio);
}