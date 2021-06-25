#ifndef FECHAHORA_H
#define FECHAHORA_H

#include "../ICollection/interfaces/ICollectible.h"
#include <iostream>

using namespace std;

class FechaHora : public ICollectible
{
private:
    int dia, mes, anio, hora, minuto, segundo;
public:
    FechaHora();
    ~FechaHora();
    FechaHora(int, int, int, int, int, int);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;
    void mostrarInfo(ostream&);
    friend ostream& operator<<(ostream&, FechaHora*);
};

#endif
