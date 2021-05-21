#ifndef CLASE_H
#define CLASE_H

#include "../Datatypes/DtFechaHora.h"
#include "Docente.h"
#include "Estudiante.h"
#include <vector>
#include <string>

using namespace std;

class Clase
{
private:
    string nombre;
    int numero;
    DtFechaHora fechaHoraComienzo;
    bool enVivo;
    string urlGrabacion;
    DtFechaHora fechaHoraFinalizacion;
    float promedioTiempoAsistencia;
    vector<Docente> docentes;
    vector<Estudiante> estudiantes;
public:
    Clase();
    virtual ~Clase() = 0;
    Clase(string, int, DtFechaHora);
    string getNombre() const;
    int getNumero() const;
    DtFechaHora getFechaHoraComienzo() const;
    bool estaEnVivo() const;
    string getUrlGrabacion() const;
    DtFechaHora getFechaHoraFinalizacion() const;
    float getPromedioTiempoAsistencia() const;
    vector<Docente> getDocentes() const;
    vector<Estudiante> getEstudiantes() const;
    void setNombre(string);
    void setNumero(int);
    void setFechaHoraComienzo(DtFechaHora);
    void setEnVivo(bool);
    void setUrlGrabacion(string);
    void setFechaHoraFinalizacion(DtFechaHora);
    void setPromedioTiempoAsistencia(float);
    void setDocentes(vector<Docente>);
    void setEstudiantes(vector<Estudiante>);
};

#endif
