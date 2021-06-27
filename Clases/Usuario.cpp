#include "Usuario.h"

Usuario::Usuario()
{
    clases = new OrderedDictionary;
}

Usuario::~Usuario()
{
}

Usuario::Usuario(string nombre, string email, string contrasenia, string urlImgPerfil)
{
    clases = new OrderedDictionary;
    this->nombre = nombre;
    this->email = email;
    this->contrasenia = contrasenia;
    this->urlImgPerfil = urlImgPerfil;
}

string Usuario::getNombre() const
{
    return nombre;
}

string Usuario::getEmail() const
{
    return email;
}

string Usuario::getUrlImgPerfil() const
{
    return urlImgPerfil;
}

string Usuario::getContrasenia() const
{
    return contrasenia;
}

IDictionary *Usuario::getClases() const
{
    return clases;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}

void Usuario::setUrlImgPerfil(string urlImgPerfil)
{
    this->urlImgPerfil = urlImgPerfil;
}

void Usuario::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}

void Usuario::setClases(IDictionary *clases)
{
    this->clases = clases;
}

IDictionary *Usuario::getDatosMensajes(int numeroClase) const {}

void Usuario::agregarClase(Clase *c)
{
    IKey *k = new Integer(c->getNumeroClase());
    clases->add(k, c);
}

IDictionary *Usuario::getDatosClasesEnVivo() const
{
    IDictionary *datosClases = new OrderedDictionary;
    IIterator *it = clases->getIterator();
    Clase *c;
    IKey *k;
    for (it; it->hasCurrent(); it->next())
    {
        c = dynamic_cast<Clase *>(it->getCurrent());
        if (c->estaEnVivo())
        {
            k = new Integer(c->getNumeroClase());
            datosClases->add(k, c->getDatosClase());
        }
    }
    return datosClases;
    delete it;
}

Clase *Usuario::getClase(int numeroClase) const {}

DtClase *Usuario::getDatosClase(int numeroClase) const
{
    IKey *k = new Integer(numeroClase);
    DtClase *dvCls = dynamic_cast<Clase *>(clases->find(k))->getDatosClase();
    delete k;
    return dvCls;
}

IDictionary *Usuario::getDatosClases(string codigoAsignatura) const {}

void Usuario::removerClases(string codigoAsignatura)
{
    IIterator *it = clases->getIterator();
    Clase *c;
    ICollection *numeroClases = new List;
    for (it; it->hasCurrent(); it->next())
    {
        c = dynamic_cast<Clase *>(it->getCurrent());
        if (c->getCodigoAsignatura() == codigoAsignatura)
        {
            numeroClases->add(new Integer(c->getNumeroClase()));
        }
    }
    delete it;
    it = numeroClases->getIterator();
    for (it; it->hasCurrent(); it->next())
    {
        numeroClases->remove(it->getCurrent());
    }
    delete it, numeroClases;
}
