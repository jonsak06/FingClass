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
    delete it, k;
    return datosDocentes;
}

Docente HandlerUsuarios::getDocente(string email) {
    IKey* k = new String(email);
    Docente* d = dynamic_cast<Docente*>(usuarios->find(k));
    delete k;
    return *d;
}

Estudiante HandlerUsuarios::getEstudiante(string cedula) {}
Usuario *HandlerUsuarios::getUsuario(string email) {}

void HandlerUsuarios::agregarUsuario(DtUsuario *dvUsr)
{
    Usuario *u;
    IKey *k;
    if (dynamic_cast<DtDocente *>(dvUsr) != nullptr)
    {
        u = new Docente(dvUsr->getNombre(), dvUsr->getEmail(), dvUsr->getUrlImgPerfil(), dvUsr->getContrasenia(), dvUsr->getNombreInstituto());
        k = new String(dvUsr->getEmail());
    }
    else
    {
        u = new Estudiante(dvUsr->getNombre(), dvUsr->getEmail(), dvUsr->getUrlImgPerfil(), dvUsr->getContrasenia(), dvUsr->getCedula());
        k = new String(dvUsr->getCedula());
    }
    usuarios->add(k, u);
}

void HandlerUsuarios::removerClasesYAsignacionDocentes(string codigoAsignatura) {}
void HandlerUsuarios::removerClasesEstudiantes(string codigoAsignatura) {}