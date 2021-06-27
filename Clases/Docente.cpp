#include "Docente.h"

Docente::Docente()
{
    asignaciones = new List;
}

Docente::Docente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto) : Usuario(nombre, email, contrasenia, urlImgPerfil)
{
    asignaciones = new List;
    this->nombreInstituto = nombreInstituto;
}

string Docente::getNombreInstituto() const
{
    return nombreInstituto;
}

ICollection *Docente::getAsignaciones() const
{
    return asignaciones;
}

void Docente::setNombreInstituto(string)
{
    this->nombreInstituto = nombreInstituto;
}

void Docente::setAsignaciones(ICollection *asignaciones)
{
    this->asignaciones = asignaciones;
}

DtDocente *Docente::getDatosUsuario() const
{
    return new DtDocente(getNombre(), getEmail(), getContrasenia(), getUrlImgPerfil(), nombreInstituto);
}

bool Docente::comprobarAsignacion(string codigoAsignatura) const
{
    IIterator *it = asignaciones->getIterator();
    bool estaAsignado = false;
    while (!estaAsignado && it->hasCurrent())
    {
        Asignacion *agn = dynamic_cast<Asignacion *>(it->getCurrent());
        estaAsignado = agn->getCodigoAsignatura() == codigoAsignatura;
        it->next();
    }
    delete it;
    return estaAsignado;
}

void Docente::asignarAsignatura(Asignatura *a, TipoClase rolDictado)
{
    Asignacion *agn = new Asignacion(*a, rolDictado);
    asignaciones->add(agn);
}

IDictionary *Docente::getDatosAsignaturas() const
{
    IDictionary *datosAsignaturas = new OrderedDictionary;
    IIterator *it = asignaciones->getIterator();
    IKey *k;
    Asignacion *agn;
    DtAsignatura *dvAsig;
    for (it; it->hasCurrent(); it->next())
    {
        agn = dynamic_cast<Asignacion *>(it->getCurrent());
        k = new String(agn->getCodigoAsignatura());
        dvAsig = agn->getDatosAsignatura();
        datosAsignaturas->add(k, dvAsig);
    }
    delete it, k;
    return datosAsignaturas;
}

TipoClase Docente::getRolDictado(string codigoAsignatura) const
{
    IIterator *it = asignaciones->getIterator();
    Asignacion *agn;
    TipoClase rol;
    for (it; it->hasCurrent(); it->next())
    {
        agn = dynamic_cast<Asignacion *>(it->getCurrent());
        if (agn->getCodigoAsignatura() == codigoAsignatura)
        {
            rol = agn->getRolDictado();
            break;
        }
    }
    delete it;
    return rol;
}

void Docente::finalizarClase(int numeroClase)
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase*>(getClases()->find(k));
    c->finalizarClase();
    delete k;
}

void Docente::removerAsignacion(string codigoAsignatura)
{
    IIterator *it = asignaciones->getIterator();
    Asignacion *agn;
    for (it; it->hasCurrent(); it->next())
    {
        if (dynamic_cast<Asignacion *>(it->getCurrent())->getCodigoAsignatura() == codigoAsignatura)
        {
            agn = dynamic_cast<Asignacion *>(it->getCurrent());
            break;
        }
    }
    asignaciones->remove(agn);
    delete it, agn;
}