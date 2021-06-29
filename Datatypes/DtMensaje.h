#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "../Datatypes/FechaHora.h"
#include <string>

using namespace std;

class DtMensaje : public ICollectible
{
private:
    int idMensaje;
    string mensaje;
    FechaHora fechaHoraEnvio;
    int idMensajeRespondido;
public:
    DtMensaje();
    ~DtMensaje();
    DtMensaje(int, string, FechaHora, int);
    DtMensaje(int, string, FechaHora);
    int getIdMensaje() const;
    string getMensaje() const;
    FechaHora getFechaHoraEnvio() const;
    void mostrarInfo(ostream&);
    friend ostream& operator<<(ostream&, DtMensaje*);
};

#endif
