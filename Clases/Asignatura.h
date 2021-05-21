#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Docente.h"
#include "Estudiante.h"
#include "Clase.h"
#include <vector>
#include <string>

using namespace std;

class Asignatura
{
private:
    string codigoAsignatura;
    string nombreAsignatura;
    bool teorico;
    bool practico;
    bool monitoreo;
    float tiempoTotalDictado;
    vector<Docente> docentesAsignados;
    vector<Estudiante> estudiantesInscriptos;
    vector<Clase*> clases;
public:
    Asignatura();
    ~Asignatura();
    Asignatura(string, string);
    string getCodigoAsignatura() const;
    string getNombreAsignatura() const;
    bool tieneTeorico() const;
    bool tienePractico() const;
    bool tieneMonitoreo() const;
    float getTiempoTotalDictado() const;
    vector<Docente> getDocentesAsignados() const;
    vector<Estudiante> getEstudiantesInscriptos() const;
    vector<Clase*> getClases() const;
    void setCodigoAsignatura(string);
    void setNombreAsignatura(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    void setTiempoTotalDictado(float);
    void setDocentesAsignados(vector<Docente>);
    void setEstudiantesInscriptos(vector<Estudiante>);
    void setClases(vector<Clase*>);
};

#endif
