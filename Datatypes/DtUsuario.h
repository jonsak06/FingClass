#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include "../ICollection/interfaces/ICollectible.h"
#include <string>

using namespace std;

class DtUsuario : public ICollectible
{
private:
    string nombre;
    string email;
    string contrasenia;
    string urlImgPerfil;
public:
    DtUsuario();
    virtual ~DtUsuario() = 0;
    DtUsuario(string, string, string, string);
    DtUsuario(string, string);
    DtUsuario(string);
    string getNombre() const;
    string getEmail() const;
    string getContrasenia() const;
    string getUrlImgPerfil() const;
    virtual string getNombreInstituto() const = 0;
    virtual string getCedula() const = 0;
    virtual void mostrarInfo(ostream&) = 0;
    friend ostream& operator<<(ostream&, DtUsuario*);
};

#endif
