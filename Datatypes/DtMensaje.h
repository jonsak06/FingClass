#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "../Datatypes/DtFechaHora.h"
#include <string>

using namespace std;

class DtMensaje
{
private:
    int idMensaje;
    string mensaje;
    DtFechaHora fechaHoraEnvio;
public:
    DtMensaje();
    ~DtMensaje();
    DtMensaje(int, string, DtFechaHora);
    int getIdMensaje() const;
    string getMensaje() const;
    DtFechaHora getFechaHoraEnvio() const;
};

#endif
