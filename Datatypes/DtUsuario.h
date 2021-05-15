#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>

using namespace std;

class DtUsuario
{
private:
    string nombre;
    string email;
    string urlImgPerfil;
    string contrasenia;
public:
    DtUsuario();
    virtual ~DtUsuario() = 0;
    DtUsuario(string, string, string, string);
    string getNombre() const;
    string getEmail() const;
    string getUrlImgPerfil() const;
    string getContrasenia() const;
};

#endif
