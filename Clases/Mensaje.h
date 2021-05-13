#ifndef MENSAJE_H
#define MENSAJE_H

#include "../Datatypes/DtFechaHora.h"
#include <string>

using namespace std;

class Mensaje
{
private:
    int idMensaje;
    string mensaje;
    DtFechaHora fechaHoraEnvio;
public:
    Mensaje();
    ~Mensaje();
    Mensaje(int, string, DtFechaHora);
    int getIdMensaje() const;
    string getMensaje() const;
    DtFechaHora getFechaHoraEnvio() const;
    void setIdMensaje(int);
    void setMensaje(string);
    void setFechaHoraEnvio(DtFechaHora);
};

#endif
