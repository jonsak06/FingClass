#include "Asignatura.h"

Asignatura::Asignatura()
{
    clases = new OrderedDictionary;
    estudiantesInscriptos = new OrderedDictionary;
    tiempoTotalDictado = 0;
}

Asignatura::~Asignatura()
{
    delete estudiantesInscriptos;
}

Asignatura::Asignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo, double tiempoTotalDictado)
{
    clases = new OrderedDictionary;
    estudiantesInscriptos = new OrderedDictionary;
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
    this->tiempoTotalDictado = tiempoTotalDictado;
}

Asignatura::Asignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo)
{
    clases = new OrderedDictionary;
    estudiantesInscriptos = new OrderedDictionary;
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
    tiempoTotalDictado = 0;
}

string Asignatura::getCodigoAsignatura() const
{
    return codigoAsignatura;
}

string Asignatura::getNombreAsignatura() const
{
    return nombreAsignatura;
}

bool Asignatura::tieneTeorico() const
{
    return teorico;
}

bool Asignatura::tienePractico() const
{
    return practico;
}

bool Asignatura::tieneMonitoreo() const
{
    return monitoreo;
}

double Asignatura::getTiempoTotalDictado() const
{
    return tiempoTotalDictado;
}

IDictionary *Asignatura::getEstudiantesInscriptos() const
{
    return estudiantesInscriptos;
}

IDictionary *Asignatura::getClases() const
{
    return clases;
}

void Asignatura::setCodigoAsignatura(string)
{
    this->codigoAsignatura = codigoAsignatura;
}

void Asignatura::setNombreAsignatura(string)
{
    this->nombreAsignatura = nombreAsignatura;
}

void Asignatura::setTeorico(bool teorico)
{
    this->teorico = teorico;
}

void Asignatura::setPractico(bool practico)
{
    this->practico = practico;
}

void Asignatura::setMonitoreo(bool monitoreo)
{
    this->monitoreo = monitoreo;
}

void Asignatura::setTiempoTotalDictado(double tiempoTotalDictado)
{
    this->tiempoTotalDictado = tiempoTotalDictado;
}

void Asignatura::setEstudiantesInscriptos(IDictionary *estudiantesInscriptos)
{
    this->estudiantesInscriptos = estudiantesInscriptos;
}

void Asignatura::setClases(IDictionary *clases)
{
    this->clases = clases;
}

DtAsignatura *Asignatura::getDatosAsignatura()
{
    calcularTiempoTotalDictado();
    DtAsignatura *dvAsig = new DtAsignatura(codigoAsignatura, nombreAsignatura, teorico, practico, monitoreo, tiempoTotalDictado);
    tiempoTotalDictado = 0;
    return dvAsig;
}

Clase *Asignatura::iniciarClase(DtClase *dvCls) const
{
    Clase *c;
    if (dynamic_cast<DtTeorico *>(dvCls) != nullptr)
    {
        c = new Teorico(dvCls->getNumeroClase(), dvCls->getNombreClase(), dvCls->getFechaHoraComienzo());
    }
    else
    {
        c = new Practico(dvCls->getNumeroClase(), dvCls->getNombreClase(), dvCls->getFechaHoraComienzo());
    }
    c->setCodigoAsignatura(dvCls->getCodigoAsignatura());
    IKey *k = new Integer(c->getNumeroClase());
    clases->add(k, c);
    return c;
}

Clase *Asignatura::iniciarClase(DtClase *dvCls, IDictionary *habilitados) const
{
    Clase *c = new Monitoreo(dvCls->getNumeroClase(), dvCls->getNombreClase(), dvCls->getFechaHoraComienzo(), habilitados);
    c->setCodigoAsignatura(dvCls->getCodigoAsignatura());
    IKey *k = new Integer(c->getNumeroClase());
    clases->add(k, c);
    return c;
}

IDictionary *Asignatura::getDatosClasesEnDiferido() const
{
    IDictionary *datosClases = new OrderedDictionary;
    IIterator *it = clases->getIterator();
    IKey *k;
    Clase *c;
    IDictionary *habilitados = new OrderedDictionary;
    for (it; it->hasCurrent(); it->next())
    {
        c = dynamic_cast<Clase *>(it->getCurrent());
        if (!c->estaEnVivo())
        {
            k = new Integer(c->getNumeroClase());
            datosClases->add(k, c->getDatosClase());
        }
    }
    delete it;
    return datosClases;
}

IDictionary *Asignatura::reproducirClase(int numeroClase, Estudiante *e) const
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase *>(clases->find(k));
    delete k;
    c->marcarAsistenciaDif(e, e->getCedula());
    return c->getDatosMensajes();
}

void Asignatura::eliminarClases()
{
    if (!clases->isEmpty())
    {
        IIterator *it = clases->getIterator();
        Clase *c;
        for (it; it->hasCurrent(); it->next())
        {
            c = dynamic_cast<Clase *>(it->getCurrent());
            c->eliminarAsistencias();
            c->eliminarMensajes();
        }
        delete it;
        it = clases->getIterator();
        IKey *k;
        for (it; it->hasCurrent(); it->next())
        {
            c = dynamic_cast<Clase *>(it->getCurrent());
            k = new Integer(c->getNumeroClase());
            clases->remove(k);
            delete c, k;
        }
        delete it;
    }
}

Clase *Asignatura::getClase(int numeroClase) const
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase *>(clases->find(k));
    delete k;
    return c;
}

bool Asignatura::comprobarInscripcionEstudiante(string cedula) const
{
    IKey *k = new String(cedula);
    bool inscripto = estudiantesInscriptos->find(k) != NULL;
    delete k;
    return inscripto;
}

void Asignatura::inscribirEstudiante(Estudiante *e)
{
    IKey *k = new String(e->getCedula());
    estudiantesInscriptos->add(k, e);
}

IDictionary *Asignatura::getDatosEstudiantesInscriptos() const
{
    IDictionary *datosEstudiantes = new OrderedDictionary;
    IIterator *it = estudiantesInscriptos->getIterator();
    DtEstudiante *dvEst;
    IKey *k;
    for (it; it->hasCurrent(); it->next())
    {
        dvEst = dynamic_cast<Estudiante *>(it->getCurrent())->getDatosUsuario();
        k = new String(dvEst->getCedula());
        datosEstudiantes->add(k, dvEst);
    }
    delete it;
    return datosEstudiantes;
}

IDictionary *Asignatura::getDatosClasesEnVivoHabilitado(string cedula) const
{
    IDictionary *datosClases = new OrderedDictionary;
    IKey *k = new String(cedula);
    if (estudiantesInscriptos->find(k) != nullptr)
    {
        delete k;
        IIterator *it = clases->getIterator();
        Clase *c;
        Monitoreo *m;
        IDictionary *habilitados = new OrderedDictionary;
        for (it; it->hasCurrent(); it->next())
        {
            c = dynamic_cast<Clase *>(it->getCurrent());
            if (c->comprobarAsistenciaEnVivo(cedula))
            {
                continue;
            }

            m = dynamic_cast<Monitoreo *>(c);
            if (m != nullptr && m->estaEnVivo())
            {
                if (m->estaHabilitado(cedula))
                {
                    k = new Integer(m->getNumeroClase());
                    datosClases->add(k, m->getDatosClase());
                    continue;
                }
            }
            else if (c->estaEnVivo())
            {
                k = new Integer(c->getNumeroClase());
                datosClases->add(k, c->getDatosClase());
            }
        }
        delete it;
    }
    return datosClases;
}

DtClase *Asignatura::getDatosClase(int numeroClase) const
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase *>(clases->find(k));
    delete k;
    return c->getDatosClase();
}

Clase *Asignatura::asistirClase(int numeroClase, Estudiante *e, string cedula) const
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase *>(clases->find(k));
    delete k;
    c->marcarAsistenciaVivo(e, cedula);
    return c;
}

void Asignatura::calcularTiempoTotalDictado()
{
    IIterator *it = clases->getIterator();
    Clase *c;
    for (it; it->hasCurrent(); it->next())
    {
        c = dynamic_cast<Clase *>(it->getCurrent());
        if (!c->estaEnVivo())
        {
            tiempoTotalDictado += c->getTiempoDictado();
        }
    }
    delete it;
}

void Asignatura::finalizarReproduccion(string cedula, int numeroClase)
{
    IKey *k = new Integer(numeroClase);
    Clase *c = dynamic_cast<Clase*>(clases->find(k));
    delete k;
    c->finalizarReproduccion(cedula);
}