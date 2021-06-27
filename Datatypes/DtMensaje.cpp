#include "DtMensaje.h"

DtMensaje::DtMensaje() {
}

DtMensaje::~DtMensaje() {
}

DtMensaje::DtMensaje(int idMensaje, string mensaje, FechaHora fechaHoraEnvio) {
    this->idMensaje = idMensaje;
    this->mensaje = mensaje;
    this->fechaHoraEnvio = fechaHoraEnvio;
}

int DtMensaje::getIdMensaje() const{
    return idMensaje;
}

string DtMensaje::getMensaje() const{
    return mensaje;
}

FechaHora DtMensaje::getFechaHoraEnvio() const {
    return fechaHoraEnvio;
}

void DtMensaje::mostrarInfo(ostream &)
{
    FechaHora *fh = new FechaHora(fechaHoraEnvio);
    cout << endl;
    cout << "Id: " << idMensaje << endl;
    cout << "Fecha y hora de envio: " << fh << endl;
    cout << "Mensaje: " << mensaje << endl;
    delete fh;
}

ostream &operator<<(ostream &salida, DtMensaje *dvMsj)
{
    dvMsj->mostrarInfo(salida);
    return salida;
}