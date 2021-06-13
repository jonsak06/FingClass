#ifndef TEORICO_H
#define TEORICO_H

#include "Clase.h"
#include "../Datatypes/DtTeorico.h"

class Teorico : public Clase
{
private:
    int cantAsistentes;
public:
    Teorico();
    Teorico(int, string, FechaHora);
    int getCantAsistentes() const;
    void setCantAsistentes(int);
    
    //operaciones DCD
    DtTeorico* getDatosClase() const;
};

#endif
