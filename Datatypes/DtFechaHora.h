#ifndef DTFECHAHORA_H
#define DTFECHAHORA_H

class DtFechaHora
{
private:
    int dia, mes, anio, hora, minuto, segundo;
public:
    DtFechaHora();
    ~DtFechaHora();
    DtFechaHora(int, int, int, int, int, int);
};

#endif
