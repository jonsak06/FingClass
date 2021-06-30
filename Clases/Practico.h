#ifndef PRACTICO_H
#define PRACTICO_H

#include "Clase.h"
#include "../Datatypes/DtPractico.h"

class Practico : public Clase
{
private:
public:
    Practico();
    Practico(int, string, FechaHora);

    DtClase *getDatosClase() const;
};

#endif
