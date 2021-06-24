#ifndef MENSAJE_H
#define MENSAJE_H

#include "../Datatypes/FechaHora.h"
#include "../Datatypes/DtMensaje.h"
#include <string>

using namespace std;

class Usuario;

class Mensaje : public ICollectible
{
private:
    int idMensaje;
    string mensaje;
    FechaHora fechaHoraEnvio;
    Usuario* usuario;
public:
    Mensaje();
    ~Mensaje();
    Mensaje(int, string, FechaHora);
    int getIdMensaje() const;
    string getMensaje() const;
    FechaHora getFechaHoraEnvio() const;
    Usuario* getUsuario() const;
    void setIdMensaje(int);
    void setMensaje(string);
    void setFechaHoraEnvio(FechaHora);
    void setUsuario(Usuario*);

    //operaciones DCD
    DtMensaje getDatosMensaje() const;
};

#endif
