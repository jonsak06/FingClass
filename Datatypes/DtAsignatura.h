#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include "../ICollection/interfaces/ICollectible.h"
#include <string>
#include <iostream>

using namespace std;

class DtAsignatura : public ICollectible
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
    DtAsignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo);
    DtAsignatura(string codigoAsignatura, string nombreAsignatura);
    DtAsignatura(string codigoAsignatura, string nombreAsignatura, float tiempoTotalDictado);
    string getCodigoAsignatura() const;
    string getNombreAsignatura() const;
    bool tieneTeorico() const;
    bool tienePractico() const;
    bool tieneMonitoreo() const;
    float getTiempoTotalDictado() const;
    void mostrarInfo(ostream&);
    friend ostream& operator<<(ostream&, DtAsignatura*);
};

#endif