#include "HandlerUsuarios.h"

HandlerUsuarios::HandlerUsuarios()
{
    usuarios = new OrderedDictionary;
}

HandlerUsuarios &HandlerUsuarios::getInstance()
{
    static HandlerUsuarios *hndlrUsr = new HandlerUsuarios();
    return *hndlrUsr;
}

IDictionary *HandlerUsuarios::getDatosDocentesSinAsignar(string codigoAsignatura)
{
    IDictionary *datosDocentes = new OrderedDictionary;
    IIterator *it = usuarios->getIterator();
    IKey *k;
    bool estaAsignado;
    Docente *d;
    for (it; it->hasCurrent(); it->next())
    {
        d = dynamic_cast<Docente *>(it->getCurrent());
        if (d != nullptr)
        {
            estaAsignado = d->comprobarAsignacion(codigoAsignatura);
            if (!estaAsignado)
            {
                DtDocente *dvDoc = d->getDatosUsuario();
                k = new String(d->getEmail());
                datosDocentes->add(k, dvDoc);
            }
        }
    }
    delete it;
    return datosDocentes;
}

Docente *HandlerUsuarios::getDocente(string email)
{
    IKey *k = new String(email);
    Docente *d = dynamic_cast<Docente *>(usuarios->find(k));
    delete k;
    return d;
}

Estudiante *HandlerUsuarios::getEstudiante(string cedula)
{
    IKey *k = new String(cedula);
    Estudiante *e = dynamic_cast<Estudiante *>(usuarios->find(k));
    delete k;
    return e;
}

Usuario *HandlerUsuarios::getUsuario(string emailOCedula)
{
    IKey *k = new String(emailOCedula);
    Usuario *u = dynamic_cast<Usuario *>(usuarios->find(k));
    delete k;
    return u;
}

void HandlerUsuarios::agregarUsuario(DtUsuario *dvUsr)
{
    Usuario *u;
    IKey *k;
    if (dynamic_cast<DtDocente *>(dvUsr) != nullptr)
    {
        u = new Docente(dvUsr->getNombre(), dvUsr->getEmail(), dvUsr->getContrasenia(), dvUsr->getUrlImgPerfil(), dvUsr->getNombreInstituto());
        k = new String(dvUsr->getEmail());
    }
    else
    {
        u = new Estudiante(dvUsr->getNombre(), dvUsr->getEmail(), dvUsr->getContrasenia(), dvUsr->getUrlImgPerfil(), dvUsr->getCedula());
        k = new String(dvUsr->getCedula());
    }
    usuarios->add(k, u);
}

void HandlerUsuarios::removerClasesYAsignacionDocentes(string codigoAsignatura)
{
    IIterator *it = usuarios->getIterator();
    Docente *d;
    for (it; it->hasCurrent(); it->next())
    {
        d = dynamic_cast<Docente *>(it->getCurrent());
        if (d != nullptr)
        {
            d->removerClases(codigoAsignatura);
            d->removerAsignacion(codigoAsignatura);
        }
    }
    delete it;
}

void HandlerUsuarios::removerClasesEstudiantes(string codigoAsignatura)
{
    IIterator *it = usuarios->getIterator();
    Estudiante *e;
    for (it; it->hasCurrent(); it->next())
    {
        e = dynamic_cast<Estudiante *>(it->getCurrent());
        if (e != nullptr)
        {
            e->removerClases(codigoAsignatura);
        }
    }
    delete it;
}

bool HandlerUsuarios::existeUsuario(string clave)
{
    IKey *k = new String(clave);
    bool existe = usuarios->member(k);
    delete k;
    return existe;
}

bool HandlerUsuarios::confirmarPass(string clave, string password)
{
    IKey *k = new String(clave);
    Usuario *u = dynamic_cast<Usuario *>(usuarios->find(k));
    delete k;
    return u->getContrasenia() == password;
}

IDictionary *HandlerUsuarios::getDatosEstudiantes()
{
    IIterator *it = usuarios->getIterator();
    IDictionary *estudiantes = new OrderedDictionary;
    for (it; it->hasCurrent(); it->next())
    {
        if (dynamic_cast<Estudiante *>(it->getCurrent()) != nullptr)
        {
            Estudiante *e = dynamic_cast<Estudiante *>(it->getCurrent());
            IKey *k = new String(e->getCedula());
            estudiantes->add(k, e->getDatosUsuario());
        }
    }
    delete it;
    return estudiantes;
}

IDictionary *HandlerUsuarios::getDatosDocentes()
{
    IIterator *it = usuarios->getIterator();
    IDictionary *docentes = new OrderedDictionary;
    for (it; it->hasCurrent(); it->next())
    {
        if (dynamic_cast<Docente *>(it->getCurrent()) != nullptr)
        {
            Docente *d = dynamic_cast<Docente *>(it->getCurrent());
            IKey *k = new String(d->getEmail());
            docentes->add(k, d->getDatosUsuario());
        }
    }
    delete it;
    return docentes;
}
