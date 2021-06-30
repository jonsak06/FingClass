#include "DtMensaje.h"

DtMensaje::DtMensaje()
{
    idMensajeRespondido = 0;
}

DtMensaje::~DtMensaje()
{
}

DtMensaje::DtMensaje(int idMensaje, string mensaje, FechaHora fechaHoraEnvio, int idMensajeRespondido)
{
    this->idMensaje = idMensaje;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = fechaHoraEnvio;
    this->idMensajeRespondido = idMensajeRespondido;
}

DtMensaje::DtMensaje(int idMensaje, string mensaje, FechaHora fechaHoraEnvio)
{
    this->idMensaje = idMensaje;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = fechaHoraEnvio;
}

int DtMensaje::getIdMensaje() const
{
    return idMensaje;
}

string DtMensaje::getMensaje() const
{
    return mensaje;
}

FechaHora DtMensaje::getFechaHoraEnvio() const
{
    return fechaHoraEnvio;
}

void DtMensaje::mostrarInfo(ostream &)
{
    FechaHora *fh = new FechaHora(fechaHoraEnvio);
    cout << endl;
    cout << "Id: " << idMensaje << endl;
    if (idMensajeRespondido != 0)
    {
        cout << "Respuesta de: " << idMensajeRespondido << endl;
    }
    cout << "Fecha y hora de envio: " << fh;
    cout << "Mensaje: " << mensaje << endl;
    delete fh;
}

ostream &operator<<(ostream &salida, DtMensaje *dvMsj)
{
    dvMsj->mostrarInfo(salida);
    return salida;
}