#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "../Colecciones/ColDocentes.h"
#include "../Colecciones/ColEstudiantes.h"
#include "../Colecciones/ColClases.h"
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
    ColDocentes docentesAsignados;
    ColEstudiantes estudiantesInscriptos;
    ColClases clases;
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
    ColDocentes getDocentesAsignados() const;
    ColEstudiantes getEstudiantesInscriptos() const;
    ColClases getClases() const;
    void setCodigoAsignatura(string);
    void setNombreAsignatura(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    void setTiempoTotalDictado(float);
    void setDocentesAsignados(ColDocentes);
    void setEstudiantesInscriptos(ColEstudiantes);
    void setClases(ColClases);
};

#endif
