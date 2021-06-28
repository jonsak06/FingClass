#include "Clase.h"

Clase::Clase()
{
    asistenciasEnDiferido = new List;
    asistenciasEnVivo = new List;
    mensajes = new OrderedDictionary;
    enVivo = true;
}

Clase::~Clase()
{
    delete asistenciasEnVivo, asistenciasEnDiferido, mensajes;
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

float Clase::getPromedioTiempoAsistenciaEnDiferido() const
{
    return promedioTiempoAsistenciaEnDiferido;
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

void Clase::setPromedioTiempoAsistenciaEnDiferido(float promedioTiempoAsistenciaEnDiferido)
{
    this->promedioTiempoAsistenciaEnDiferido = promedioTiempoAsistenciaEnDiferido;
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
    enVivo = false;
    urlGrabacion = generarUrlGrabacion();
    fechaHoraFinalizacion = *reloj.getFechaHoraActual();
    delete it;
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
    IIterator *it = asistenciasEnVivo->getIterator();
    AsistenciaEnVivo *asVivo;
    while (!asistenciasEnVivo->isEmpty())
    {
        asVivo = dynamic_cast<AsistenciaEnVivo *>(it->getCurrent());
        asistenciasEnVivo->remove(asVivo);
        delete asVivo;
        it->next();
    }
    AsistenciaEnDiferido *asDif;
    while (!asistenciasEnDiferido->isEmpty())
    {
        asDif = dynamic_cast<AsistenciaEnDiferido *>(it->getCurrent());
        asistenciasEnDiferido->remove(asDif);
        delete asDif;
        it->next();
    }
    delete it;
}

void Clase::eliminarMensajes()
{
    IIterator *it = mensajes->getIterator();
    Mensaje *m;
    IKey *k;
    while (!mensajes->isEmpty())
    {
        m = dynamic_cast<Mensaje *>(it->getCurrent());
        k = new Integer(m->getIdMensaje());
        mensajes->remove(k);
        delete m, k;
    }
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
    FechaHora * fh = reloj.getFechaHoraActual();
    // IIterator *it = asistenciasEnVivo->getIterator();
    bool yaAsistio = comprobarAsistenciaEnVivo(cedula);
    AsistenciaEnVivo* asisVivo;

    // while (it->hasCurrent() && yaAsistio)
    // {
    //     asisVivo = dynamic_cast<AsistenciaEnVivo*>(it->getCurrent());
    //     if (asisVivo->comprobarAsistencia(cedula))
    //     {
    //         yaAsistio = false;
    //     }
    //     it->next();
    // }
    if (!yaAsistio)
    {
        asisVivo = new AsistenciaEnVivo(e, fh);
        asistenciasEnVivo->add(asisVivo);
    }
}

void Clase::marcarAsistenciaDif(Estudiante *e) {}

string Clase::generarUrlGrabacion() const
{
    string direccion = "http://fingclass.edu.uy/clases/videos/";
    string extension = ".mp4";
    return direccion + nombreClase + extension;
}

bool Clase::comprobarAsistenciaEnVivo(string cedula) {
    IIterator *it = asistenciasEnVivo->getIterator();
    bool yaAsistio = false;
    AsistenciaEnVivo* asisVivo;
    while (it->hasCurrent() && !yaAsistio)
    {
        asisVivo = dynamic_cast<AsistenciaEnVivo*>(it->getCurrent());
        if (asisVivo->comprobarAsistencia(cedula))
        {
            yaAsistio = true;
        }
        it->next();
    }
    delete it;
    return yaAsistio;
}