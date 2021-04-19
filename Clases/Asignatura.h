#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Docente.h"

class Asignatura
{
private:
    string codigo;
    string nombre;
public:
    Asignatura();
    ~Asignatura();
    Asignatura(string, string);
    string getCodigo() const;
    string getNombre() const;
    void setCodigo(string);
    void setNombre(string);
};

#endif
