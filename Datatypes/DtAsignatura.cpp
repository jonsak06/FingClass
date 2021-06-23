#include "DtAsignatura.h"

DtAsignatura::DtAsignatura()
{
}

DtAsignatura::~DtAsignatura()
{
}

DtAsignatura::DtAsignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo, float tiempoTotalDictado)
{
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
    this->tiempoTotalDictado = tiempoTotalDictado;
}

DtAsignatura::DtAsignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo)
{
    this->codigoAsignatura = codigoAsignatura;
    this->nombreAsignatura = nombreAsignatura;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
}

DtAsignatura::DtAsignatura(string nombreAsignatura, float tiempoTotalDictado) {
    this->nombreAsignatura = nombreAsignatura;
    this->tiempoTotalDictado = tiempoTotalDictado;
}

string DtAsignatura::getCodigoAsignatura() const
{
    return codigoAsignatura;
}

string DtAsignatura::getNombreAsignatura() const
{
    return nombreAsignatura;
}

bool DtAsignatura::tieneTeorico() const
{
    return teorico;
}

bool DtAsignatura::tienePractico() const
{
    return practico;
}

bool DtAsignatura::tieneMonitoreo() const
{
    return monitoreo;
}

float DtAsignatura::getTiempoTotalDictado() const
{
    return tiempoTotalDictado;
}

void DtAsignatura::mostrarInfo(ostream &)
{
    string teo = tieneTeorico() ? "tiene" : "no tiene";
    string pra = tienePractico() ? "tiene" : "no tiene";
    string mon = tieneMonitoreo() ? "tiene" : "no tiene";
    cout << endl;
    cout << "Codigo: " << getCodigoAsignatura() << endl;
    cout << "Nombre: " << getNombreAsignatura() << endl;
    cout << "Teorico: " << teo << endl;
    cout << "Practico: " << pra << endl;
    cout << "Monitoreo: " << mon << endl
         << endl;
}

ostream &operator<<(ostream &salida, DtAsignatura *a)
{
    a->mostrarInfo(salida);
    return salida;
}