#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "../Datatypes/FechaHora.h"
#include <string>

using namespace std;

class DtMensaje
{
private:
    int idMensaje;
    string mensaje;
    FechaHora fechaHoraEnvio;
public:
    DtMensaje();
    ~DtMensaje();
    DtMensaje(int, string, FechaHora);
    int getIdMensaje() const;
    string getMensaje() const;
    FechaHora getFechaHoraEnvio() const;
};

#endif
