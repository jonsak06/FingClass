#ifndef MENSAJE_H
#define MENSAJE_H

#include "../Datatypes/DtFechaHora.h"
#include "Usuario.h"
#include "Clase.h"
#include <string>

using namespace std;

class Mensaje
{
private:
    int idMensaje;
    string mensaje;
    DtFechaHora fechaHoraEnvio;
    Usuario* usuario;
    Clase* clase;
public:
    Mensaje();
    ~Mensaje();
    Mensaje(int, string, DtFechaHora);
    int getIdMensaje() const;
    string getMensaje() const;
    DtFechaHora getFechaHoraEnvio() const;
    Usuario* getUsuario() const;
    Clase* getClase() const;
    void setIdMensaje(int);
    void setMensaje(string);
    void setFechaHoraEnvio(DtFechaHora);
    void setUsuario(Usuario*);
    void setClase(Clase*);
};

#endif
