#ifndef TEORICO_H
#define TEORICO_H

#include "Clase.h"

class Teorico : public Clase
{
private:
    int cantAsistentes;
public:
    Teorico();
    Teorico(string, int, DtFechaHora);
    int getCantAsistentes() const;
    void setCantAsistentes(int);
};

#endif
