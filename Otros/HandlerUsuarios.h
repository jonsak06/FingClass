#ifndef HANDLERUSUARIOS_H
#define HANDLERUSUARIOS_H

#include "../Clases/Docente.h"

class HandlerUsuarios
{
private:
    HandlerUsuarios() = default;
    HandlerUsuarios(const HandlerUsuarios&) = delete;
    HandlerUsuarios& operator=(const HandlerUsuarios&) = delete;
    HandlerUsuarios(HandlerUsuarios&&) = delete;
    HandlerUsuarios& operator=(HandlerUsuarios&&) = delete;
    IDictionary* usuarios;
public:
    static HandlerUsuarios& getInstance();

    //operaciones DCD
    ICollection* getDatosDocentesSinAsignar(string codigoAsignatura) const;
    Docente getDocente(string email) const; 
    Estudiante getEstudiante(string cedula) const;
    Usuario* getUsuario(string email) const;
    void crearUsuario(DtUsuario* dvUsr);
    void removerClasesYAsignacionDocentes(string codigoAsignatura);
    void removerClasesEstudiantes(string codigoAsignatura);
};

#endif