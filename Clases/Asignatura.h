#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Estudiante.h"
#include "Clase.h"
#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtMensaje.h"
#include "../ICollection/interfaces/IDictionary.h"
#include <string>

using namespace std;

class Clase;
// class Estudiante;

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
    Asignatura(string, string, bool, bool, bool);
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
    Clase* iniciarClase(DtClase* dvCls, IDictionary* habilitados) const;
    IDictionary* getDatosClasesEnDiferido() const;
    IDictionary* reproducirClase(int numeroClase, Estudiante e) const;
    void eliminarClases();
    Clase* getClase(int numeroClase) const;
    bool comprobarInscripcionEstudiante(string cedula) const;
    void inscribirEstudiante(Estudiante e);
    IDictionary* getDatosEstudiantesInscriptos() const;
    IDictionary* getDatosClasesEnVivoHabilitado(string cedula) const;
    DtClase* getDatosClase(int numeroClase) const; 
    Clase* asistirClase(int numeroClase, Estudiante e) const;
};

#endif
