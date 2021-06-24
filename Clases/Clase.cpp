#include "Clase.h"

Clase::Clase() {
    enVivo = true;
}

Clase::~Clase() {
}

Clase::Clase(int numeroClase, string nombreClase, FechaHora fechaHoraComienzo) {
    this->numeroClase = numeroClase;
    this->nombreClase = nombreClase;
    this->fechaHoraComienzo = fechaHoraComienzo;
    enVivo = true;
}

string Clase::getNombreClase() const {
    return nombreClase;
}

int Clase::getNumeroClase() const {
    return numeroClase;
}

FechaHora Clase::getFechaHoraComienzo() const {
    return fechaHoraComienzo;
}

bool Clase::estaEnVivo() const {
    return enVivo;
}

string Clase::getUrlGrabacion() const {
    return urlGrabacion;
}

FechaHora Clase::getFechaHoraFinalizacion() const {
    return fechaHoraFinalizacion;
}

float Clase::getPromedioTiempoAsistenciaEnDiferido() const {
    return promedioTiempoAsistenciaEnDiferido;
}

ICollection* Clase::getAsistenciasEnDiferido() const {
    return asistenciasEnDiferido;
}

ICollection* Clase::getAsistenciasEnVivo() const {
    return asistenciasEnVivo;
}

IDictionary* Clase::getMensajes() const {
    return mensajes;
}

Asignatura* Clase::getAsignatura() const {
    return asignatura;
}

void Clase::setNombreClase(string nombreClase) {
    this->nombreClase = nombreClase;
}

void Clase::setNumeroClase(int numeroClase) {
    this->numeroClase = numeroClase;
}

void Clase::setFechaHoraComienzo(FechaHora fechaHoraComienzo) {
    this->fechaHoraComienzo = fechaHoraComienzo;
}

void Clase::setEnVivo(bool enVivo) {
    this->enVivo = enVivo;
}

void Clase::setUrlGrabacion(string urlGrabacion) {
    this->urlGrabacion = urlGrabacion;
}

void Clase::setFechaHoraFinalizacion(FechaHora) {
    this->fechaHoraFinalizacion = fechaHoraFinalizacion;
}

void Clase::setPromedioTiempoAsistenciaEnDiferido(float promedioTiempoAsistenciaEnDiferido) {
    this->promedioTiempoAsistenciaEnDiferido = promedioTiempoAsistenciaEnDiferido;
}

void Clase::setAsistenciasEnDiferido(ICollection* asistenciasEnDiferido) {
    this->asistenciasEnDiferido = asistenciasEnDiferido;
}

void Clase::setAsistenciasEnVivo(ICollection* asistenciasEnVivo) {
    this->asistenciasEnVivo = asistenciasEnVivo;
}

void Clase::setMensajes(IDictionary* mensajes) {
    this->mensajes = mensajes;
}

void Clase::setAsignatura(Asignatura* asignatura) {
    this->asignatura = asignatura;
}

void Clase::finalizarClase() {}
void Clase::setInicioAsistenciaEnDiferido(Estudiante* e) {}
IDictionary* Clase::getDatosMensajes() const {}
string Clase::getCodigoAsignatura() const {}

void Clase::eliminarAsistencias() {
    IIterator* it = asistenciasEnVivo->getIterator();
    AsistenciaEnVivo* asVivo;
    while(!asistenciasEnVivo->isEmpty()) {
        asVivo = dynamic_cast<AsistenciaEnVivo*>(it->getCurrent());
        asistenciasEnVivo->remove(asVivo);
        delete asVivo;
        it->next();
    }
    AsistenciaEnDiferido* asDif;
    while(!asistenciasEnDiferido->isEmpty()) {
        asDif = dynamic_cast<AsistenciaEnDiferido*>(it->getCurrent());
        asistenciasEnDiferido->remove(asDif);
        delete asDif;
        it->next();
    }
    delete it;
}

void Clase::eliminarMensajes() {
    IIterator* it = mensajes->getIterator();
    Mensaje *m;
    IKey* k;
    while(!mensajes->isEmpty()) {
        m = dynamic_cast<Mensaje*>(it->getCurrent());
        k = new Integer(m->getIdMensaje());
        mensajes->remove(k);
        delete m, k;
    }
}

Mensaje Clase::getMensaje(int idMensaje) const {}
void Clase::enviarMensaje(Usuario* u, string mensaje) {}
void Clase::responderMensaje(Usuario* u, Mensaje m, string mensaje) {}
void Clase::marcarAsistenciaVivo(Estudiante* e) {}
void Clase::marcarAsistenciaDif(Estudiante* e) {}