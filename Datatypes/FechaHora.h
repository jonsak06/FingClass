#ifndef FECHAHORA_H
#define FECHAHORA_H

class FechaHora
{
private:
    int dia, mes, anio, hora, minuto, segundo;
public:
    FechaHora();
    ~FechaHora();
    FechaHora(int, int, int, int, int, int);
};

#endif
