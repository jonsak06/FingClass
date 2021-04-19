#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario
{
private:
    string nombre;
    string email;
    string urlImgPerfil;
public:
    Usuario();
    ~Usuario();
    Usuario(string, string, string);
    string getNombre() const;
    string getEmail() const;
    string getUrlImgPerfil() const;
    void setNombre(string);
    void setEmail(string);
    void setUrlImgPerfil(string);
};

#endif
