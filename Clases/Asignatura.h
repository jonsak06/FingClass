#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Estudiante.h"
#include "Clase.h"
#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"
#include <vector>
#include <string>

using namespace std;

class Clase;
class Estudiante;

class Asignatura
{
private:
    string codigoAsignatura;
    string nombreAsignatura;
    bool teorico;
    bool practico;
    bool monitoreo;
    float tiempoTotalDictado;
    // vector<Estudiante> estudiantesInscriptos;
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
    // vector<Estudiante> getEstudiantesInscriptos() const;
    vector<Clase*> getClases() const;
    void setCodigoAsignatura(string);
    void setNombreAsignatura(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    void setTiempoTotalDictado(float);
    // void setEstudiantesInscriptos(vector<Estudiante>);
    void setClases(vector<Clase*>);
    //operaciones DCD
    DtAsignatura getDatosAsignatura() const;
    Clase* iniciarClase(DtClase*, vector<Estudiante>) const;
    vector<DtClase> getDatosClasesDiferido() const;
    vector<DtMensaje> reproducirClase(int, Estudiante) const;
    void eliminarClases();
};

#endif
