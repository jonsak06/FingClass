#ifndef USUARIO_H
#define USUARIO_H

#include "../Datatypes/DtUsuario.h"
#include <string>

using namespace std;

class Usuario
{
private:
    string nombre;
    string email;
    string urlImgPerfil;
    string contrasenia;
public:
    Usuario();
    virtual ~Usuario() = 0;
    Usuario(string, string, string, string);
    string getNombre() const;
    string getEmail() const;
    string getUrlImgPerfil() const;
    string getContrasenia() const;
    void setNombre(string);
    void setEmail(string);
    void setUrlImgPerfil(string);
    void setContrasenia(string);
    //operaciones DCD
    virtual DtUsuario* getDatosUsuario() const = 0;
};

#endif
