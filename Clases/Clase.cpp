#include "Clase.h"

Clase::Clase()
{
    asistenciasEnDiferido = new List;
    asistenciasEnVivo = new List;
    mensajes = new OrderedDictionary;
    enVivo = true;
    promedioTiempoAsistencia = 0;
}

Clase::~Clase()
{
}

Clase::Clase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo)
{
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
    this->fechaHoraComienzo = fechaHoraComienzo;
    asistenciasEnDiferido = new List;
    asistenciasEnVivo = new List;
    mensajes = new OrderedDictionary;
    enVivo = true;
    promedioTiempoAsistencia = 0;
}

string Clase::getNombreClase() const
{
    return nombreClase;
}

int Clase::getNumeroClase() const
{
    return numeroClase;
}

FechaHora Clase::getFechaHoraComienzo() const
{
    return fechaHoraComienzo;
}

bool Clase::estaEnVivo() const
{
    return enVivo;
}

string Clase::getUrlGrabacion() const
{
    return urlGrabacion;
}

FechaHora Clase::getFechaHoraFinalizacion() const
{
    return fechaHoraFinalizacion;
}

double Clase::getPromedioTiempoAsistencia() const
{
    return promedioTiempoAsistencia;
}

ICollection *Clase::getAsistenciasEnDiferido() const
{
    return asistenciasEnDiferido;
}

ICollection *Clase::getAsistenciasEnVivo() const
{
    return asistenciasEnVivo;
}

IDictionary *Clase::getMensajes() const
{
    return mensajes;
}

string Clase::getCodigoAsignatura() const
{
    return codigoAsignatura;
}

string Clase::getNombreDocente() const
{
    return nombreDocente;
}

void Clase::setNombreClase(string nombreClase)
{
    this->nombreClase = nombreClase;
}

void Clase::setNumeroClase(int numeroClase)
{
    this->numeroClase = numeroClase;
}

void Clase::setFechaHoraComienzo(FechaHora fechaHoraComienzo)
{
    this->fechaHoraComienzo = fechaHoraComienzo;
}

void Clase::setEnVivo(bool enVivo)
{
    this->enVivo = enVivo;
}

void Clase::setUrlGrabacion(string urlGrabacion)
{
    this->urlGrabacion = urlGrabacion;
}

void Clase::setFechaHoraFinalizacion(FechaHora fechaHoraFinalizacion)
{
    this->fechaHoraFinalizacion = fechaHoraFinalizacion;
}

void Clase::setPromedioTiempoAsistencia(double promedioTiempoAsistenciao)
{
    this->promedioTiempoAsistencia = promedioTiempoAsistencia;
}

void Clase::setAsistenciasEnDiferido(ICollection *asistenciasEnDiferido)
{
    this->asistenciasEnDiferido = asistenciasEnDiferido;
}

void Clase::setAsistenciasEnVivo(ICollection *asistenciasEnVivo)
{
    this->asistenciasEnVivo = asistenciasEnVivo;
}

void Clase::setMensajes(IDictionary *mensajes)
{
    this->mensajes = mensajes;
}

void Clase::setCodigoAsignatura(string codigoAsignatura)
{
    this->codigoAsignatura = codigoAsignatura;
}

void Clase::setNombreDocente(string nombreDocente)
{
    this->nombreDocente = nombreDocente;
}

void Clase::finalizarClase()
{
    Reloj &reloj = Reloj::getInstance();
    IIterator *it = asistenciasEnVivo->getIterator();
    AsistenciaEnVivo *asisVivo;
    for (it; it->hasCurrent(); it->next())
    {
        asisVivo = dynamic_cast<AsistenciaEnVivo *>(it->getCurrent());
        if (asisVivo->getFechaHoraFin() == nullptr)
        {
            asisVivo->setFechaHoraFin(reloj.getFechaHoraActual());
        }
    }
    delete it;
    it = asistenciasEnVivo->getIterator();
    double tiempoTotalAsistido = 0;
    if (!asistenciasEnVivo->isEmpty())
    {
        for (it; it->hasCurrent(); it->next())
        {
            asisVivo = dynamic_cast<AsistenciaEnVivo *>(it->getCurrent());
            tiempoTotalAsistido += asisVivo->getTiempoAsistido();
        }
        delete it;
        promedioTiempoAsistencia = (tiempoTotalAsistido / asistenciasEnVivo->getSize());
    }
    enVivo = false;
    urlGrabacion = generarUrlGrabacion();
    fechaHoraFinalizacion = *reloj.getFechaHoraActual();
}

void Clase::setInicioAsistenciaEnDiferido(Estudiante *e) {}

IDictionary *Clase::getDatosMensajes() const
{
    IIterator *it = mensajes->getIterator();
    IDictionary *datosMensajes = new OrderedDictionary;
    IKey *k;
    Mensaje *m;
    DtMensaje *dvMsj;
    for (it; it->hasCurrent(); it->next())
    {
        m = dynamic_cast<Mensaje *>(it->getCurrent());
        k = new Integer(m->getIdMensaje());
        dvMsj = m->getDatosMensaje();
        datosMensajes->add(k, dvMsj);
    }
    delete it;
    return datosMensajes;
}

void Clase::eliminarAsistencias()
{
    delete asistenciasEnVivo, asistenciasEnDiferido;
}

void Clase::eliminarMensajes()
{
    IIterator *it = mensajes->getIterator();
    Mensaje *m;
    IKey *k;
    for (it; it->hasCurrent(); it->next())
    {
        m = dynamic_cast<Mensaje *>(it->getCurrent());
        k = new Integer(m->getIdMensaje());
        mensajes->remove(k);
        delete k, m;
    }
    delete it;
}

Mensaje *Clase::getMensaje(int idMensaje) const
{
    IKey *k = new Integer(idMensaje);
    Mensaje *m = dynamic_cast<Mensaje *>(mensajes->find(k));
    delete k;
    return m;
}

void Clase::enviarMensaje(Usuario *u, int idMensaje, string mensaje, FechaHora *fh)
{
    Mensaje *m = new Mensaje(u, idMensaje, mensaje, fh);
    IKey *k = new Integer(m->getIdMensaje());
    mensajes->add(k, m);
}

void Clase::responderMensaje(Usuario *u, int idMensaje, Mensaje *msjRespondido, string mensaje, FechaHora *fh)
{
    Mensaje *m = new Mensaje(u, idMensaje, msjRespondido, mensaje, fh);
    IKey *k = new Integer(m->getIdMensaje());
    mensajes->add(k, m);
}

void Clase::marcarAsistenciaVivo(Estudiante *e, string cedula)
{
    Reloj &reloj = Reloj::getInstance();
    FechaHora *fh = reloj.getFechaHoraActual();
    bool yaAsistio = comprobarAsistenciaEnVivo(cedula);
    AsistenciaEnVivo *asisVivo;
    if (!yaAsistio)
    {
        asisVivo = new AsistenciaEnVivo(e, fh);
        asistenciasEnVivo->add(asisVivo);
    }
}

void Clase::marcarAsistenciaDif(Estudiante *e, string cedula)
{
    Reloj &reloj = Reloj::getInstance();
    FechaHora *fh = reloj.getFechaHoraActual();
    bool yaAsistio = comprobarAsistenciaEnDiferido(cedula);
    AsistenciaEnDiferido *asisDif;
    if (!yaAsistio)
    {
        asisDif = new AsistenciaEnDiferido(e, fh);
        asistenciasEnDiferido->add(asisDif);
    }
    else
    {
        IIterator *it = asistenciasEnDiferido->getIterator();
        for (it; it->hasCurrent(); it->next())
        {
            asisDif = dynamic_cast<AsistenciaEnDiferido *>(it->getCurrent());
            if (asisDif->comprobarAsistencia(cedula))
            {
                asisDif->agregarFechaHoraInicio(fh);
                break;
            }
        }
        delete it;
    }
}

string Clase::generarUrlGrabacion() const
{
    string direccion = "http://fingclass.edu.uy/clases/videos/";
    string extension = ".mp4";
    return direccion + nombreClase + extension;
}

bool Clase::comprobarAsistenciaEnVivo(string cedula)
{
    IIterator *it = asistenciasEnVivo->getIterator();
    bool yaAsistio = false;
    AsistenciaEnVivo *asisVivo;
    while (it->hasCurrent() && !yaAsistio)
    {
        asisVivo = dynamic_cast<AsistenciaEnVivo *>(it->getCurrent());
        if (asisVivo->comprobarAsistencia(cedula))
        {
            yaAsistio = true;
        }
        it->next();
    }
    delete it;
    return yaAsistio;
}

bool Clase::comprobarAsistenciaEnDiferido(string cedula)
{
    IIterator *it = asistenciasEnDiferido->getIterator();
    bool yaAsistio = false;
    AsistenciaEnDiferido *asisDif;
    while (it->hasCurrent() && !yaAsistio)
    {
        asisDif = dynamic_cast<AsistenciaEnDiferido *>(it->getCurrent());
        if (asisDif->comprobarAsistencia(cedula))
        {
            yaAsistio = true;
        }
        it->next();
    }
    delete it;
    return yaAsistio;
}

double Clase::getTiempoDictado() const
{
    return (fechaHoraFinalizacion.getHora() + fechaHoraFinalizacion.getMinuto() / 60) - (fechaHoraComienzo.getHora() + fechaHoraComienzo.getMinuto() / 60);
}

void Clase::finalizarReproduccion(string cedula)
{
    Reloj &reloj = Reloj::getInstance();
    FechaHora *fh = reloj.getFechaHoraActual();
    IIterator *it = asistenciasEnDiferido->getIterator();
    AsistenciaEnDiferido *asDif;
    for(it;it->hasCurrent();it->next())
    {
        asDif = dynamic_cast<AsistenciaEnDiferido*>(it->getCurrent());
        if (asDif->comprobarAsistencia(cedula))
        {
            asDif->agregarFechaHoraFin(fh);
            break;
        }
    }
    delete it;
}