#ifndef RELOJ_H
#define RELOJ_H

#include "../Datatypes/FechaHora.h"

class Reloj
{
private:
    Reloj() = default;
    Reloj(const Reloj&) = delete;
    Reloj& operator=(const Reloj&) = delete;
    Reloj(Reloj&&) = delete;
    Reloj& operator=(Reloj&&) = delete;
    FechaHora *fechaHoraActual;
public:
    static Reloj& getInstance();
    FechaHora* getFechaHoraActual() const;
    void setFechaHoraActual(FechaHora*);
};


#endif