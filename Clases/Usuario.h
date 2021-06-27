#ifndef USUARIO_H
#define USUARIO_H

#include "Clase.h"
#include "../Datatypes/DtUsuario.h"
#include "../Datatypes/DtClase.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/Integer.h"
#include <iostream>
#include <string>

using namespace std;

class Usuario : public ICollectible
{
private:
    string nombre;
    string email;
    string urlImgPerfil;
    string contrasenia;
    IDictionary* clases;
public:
    Usuario();
    virtual ~Usuario() = 0;
    Usuario(string, string, string, string);
    string getNombre() const;
    string getEmail() const;
    string getUrlImgPerfil() const;
    string getContrasenia() const;
    IDictionary* getClases() const;
    void setNombre(string);
    void setEmail(string);
    void setUrlImgPerfil(string);
    void setContrasenia(string);
    void setClases(IDictionary*);

    //operaciones DCD
    virtual DtUsuario* getDatosUsuario() const = 0;
    IDictionary* getDatosMensajes(int numeroClase) const;
    void agregarClase(Clase* c);
    IDictionary* getDatosClasesEnVivo() const;
    Clase* getClase(int numeroClase) const;
    DtClase* getDatosClase(int numeroClase) const;
    IDictionary* getDatosClases(string codigoAsignatura) const;
    void removerClases(string codigoAsignatura);
};

#endif
