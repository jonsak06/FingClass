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

IDictionary *Usuario::getDatosMensajes(int numeroClase) const
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase *>(clases->find(k));
    delete k;
    return c->getDatosMensajes();
}

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
    delete it;
    return datosClases;
}

Clase *Usuario::getClase(int numeroClase) const
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase *>(clases->find(k));
    delete k;
    return c;
}

DtClase *Usuario::getDatosClase(int numeroClase) const
{
    IKey *k = new Integer(numeroClase);
    DtClase *dvCls = dynamic_cast<Clase *>(clases->find(k))->getDatosClase();
    delete k;
    return dvCls;
}

IDictionary *Usuario::getDatosClases(string codigoAsignatura) const
{
    IDictionary *datosClases = new OrderedDictionary;
    IIterator *it = clases->getIterator();
    Clase *c;
    IKey *k;
    for (it; it->hasCurrent(); it->next())
    {
        c = dynamic_cast<Clase *>(it->getCurrent());
        if (c->getCodigoAsignatura() == codigoAsignatura)
        {
            k = new Integer(c->getNumeroClase());
            datosClases->add(k, c->getDatosClase());
        }
    }
    delete it;
    return datosClases;
}

void Usuario::removerClases(string codigoAsignatura)
{
    if (!clases->isEmpty())
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
        Integer *numCls;
        for (it; it->hasCurrent(); it->next())
        {
            numCls = dynamic_cast<Integer*>(it->getCurrent());
            clases->remove(numCls);
        }
        delete it, numeroClases;
    }
}
