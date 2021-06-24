#include "Asignatura.h"

Asignatura::Asignatura()
{
    clases = new OrderedDictionary;
    tiempoTotalDictado = 0;
}

Asignatura::~Asignatura()
{
}

Asignatura::Asignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo, float tiempoTotalDictado)
{
    clases = new OrderedDictionary;
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

float Asignatura::getTiempoTotalDictado() const
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

void Asignatura::setTiempoTotalDictado(float tiempoTotalDictado)
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

DtAsignatura *Asignatura::getDatosAsignatura() const
{
    return new DtAsignatura(codigoAsignatura, nombreAsignatura, teorico, practico, monitoreo, tiempoTotalDictado);
}

DtAsignatura *Asignatura::getDatosConTiempoDictado() const
{
    return new DtAsignatura(nombreAsignatura, tiempoTotalDictado);
}

Clase *Asignatura::iniciarClase(DtClase *, IDictionary *) const {}
IDictionary *Asignatura::getDatosClasesEnDiferido() const {}
IDictionary *Asignatura::reproducirClase(int, Estudiante) const {}

void Asignatura::eliminarClases()
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
    while (!clases->isEmpty())
    {
        c = dynamic_cast<Clase *>(it->getCurrent());
        k = new Integer(c->getNumeroClase());
        clases->remove(k);
        delete c, k;
        it->next();
    }
}

Clase *Asignatura::getClase(int numeroClase) const {}
bool Asignatura::comprobarInscripcionEstudiante(string cedula) const {}
void Asignatura::inscribirEstudiante(Estudiante e) {}
IDictionary *Asignatura::getDatosEstudiantesInscriptos() const {}
IDictionary *Asignatura::getDatosClasesEnVivoHabilitado(string cedula) const {}
DtClase *Asignatura::getDatosClase(int numeroClase) const {}
Clase *Asignatura::asistirClase(int numeroClase, Estudiante e) const {}