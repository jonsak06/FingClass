#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include "../ICollection/interfaces/ICollectible.h"
#include <string>

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
    DtAsignatura(string, string, bool teorico, bool practico, bool monitoreo, float tiempoTotalDictado);
    string getCodigoAsignatura() const;
    string getNombreAsignatura() const;
    bool tieneTeorico() const;
    bool tienePractico() const;
    bool tieneMonitoreo() const;
    float getTiempoTotalDictado() const;
};

#endif