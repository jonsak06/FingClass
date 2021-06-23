#ifndef HANDLERUSUARIOS_H
#define HANDLERUSUARIOS_H

#include "../Clases/Docente.h"
#include "../ICollection/String.h"
#include "../ICollection/collections/OrderedDictionary.h"

class HandlerUsuarios
{
private:
    HandlerUsuarios();
    HandlerUsuarios(const HandlerUsuarios &) = delete;
    HandlerUsuarios &operator=(const HandlerUsuarios &) = delete;
    HandlerUsuarios(HandlerUsuarios &&) = delete;
    HandlerUsuarios &operator=(HandlerUsuarios &&) = delete;
    IDictionary *usuarios;

public:
    static HandlerUsuarios &getInstance();

    //operaciones DCD
    IDictionary *getDatosDocentesSinAsignar(string codigoAsignatura);
    Docente getDocente(string email);
    Estudiante getEstudiante(string cedula);
    Usuario *getUsuario(string email);
    void agregarUsuario(DtUsuario *dvUsr);
    void removerClasesYAsignacionDocentes(string codigoAsignatura);
    void removerClasesEstudiantes(string codigoAsignatura);
};

#endif