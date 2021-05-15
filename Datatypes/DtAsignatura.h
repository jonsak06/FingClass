#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include <string>

using namespace std;

class DtAsignatura
{
private:
    string codigoAsignatura;
    string nombreAsignatura;
    bool teorico;
    bool practico;
    bool monitoreo;
    float tiempoTotalDictado;
public:
    DtAsignatura();
    ~DtAsignatura();
    DtAsignatura(string, string, bool teorico, bool practico, bool monitoreo, float tiempoTotalDictado);
    string getCodigoAsignatura() const;
    string getNombreAsignatura() const;
    bool tieneTeorico() const;
    bool tienePractico() const;
    bool tieneMonitoreo() const;
    float getTiempoTotalDictado() const;
};

#endif