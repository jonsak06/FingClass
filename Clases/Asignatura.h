#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Estudiante.h"
#include "Clase.h"
#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"
#include <string>

using namespace std;

class Clase;
class Estudiante;

class Asignatura : public ICollectible
{
private:
    string codigoAsignatura;
    string nombreAsignatura;
    bool teorico;
    bool practico;
    bool monitoreo;
    float tiempoTotalDictado;
    IDictionary* estudiantesInscriptos;
    IDictionary* clases;
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
    IDictionary* getEstudiantesInscriptos() const;
    IDictionary* getClases() const;
    void setCodigoAsignatura(string);
    void setNombreAsignatura(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    void setTiempoTotalDictado(float);
    void setEstudiantesInscriptos(IDictionary*);
    void setClases(IDictionary*);
    //operaciones DCD
    DtAsignatura getDatosAsignatura() const;
    Clase* iniciarClase(DtClase*, IDictionary*) const;
    ICollection* getDatosClasesDiferido() const;
    ICollection* reproducirClase(int, Estudiante) const;
    void eliminarClases();
};

#endif
