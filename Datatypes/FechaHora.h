#ifndef FECHAHORA_H
#define FECHAHORA_H

#include "../ICollection/interfaces/ICollectible.h"

class FechaHora : public ICollectible
{
private:
    int dia, mes, anio, hora, minuto, segundo;
public:
    FechaHora();
    ~FechaHora();
    FechaHora(int, int, int, int, int, int);
};

#endif
