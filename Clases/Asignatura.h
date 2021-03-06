#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Clase.h"
#include "Teorico.h"
#include "Practico.h"
#include "Monitoreo.h"
#include "Estudiante.h"
#include "../Datatypes/DtAsignatura.h"
#include "../Datatypes/DtClase.h"
#include "../Datatypes/DtTeorico.h"
#include "../Datatypes/DtPractico.h"
#include "../Datatypes/DtMonitoreo.h"
#include "../Datatypes/DtMensaje.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"
#include <string>

using namespace std;

class Clase;

class Asignatura : public ICollectible
{
private:
    string codigoAsignatura;
    string nombreAsignatura;
    bool teorico;
    bool practico;
    bool monitoreo;
    double tiempoTotalDictado;
    IDictionary *estudiantesInscriptos;
    IDictionary *clases;

public:
    Asignatura();
    ~Asignatura();
    Asignatura(string, string, bool, bool, bool, double);
    Asignatura(string, string, bool, bool, bool);
    string getCodigoAsignatura() const;
    string getNombreAsignatura() const;
    bool tieneTeorico() const;
    bool tienePractico() const;
    bool tieneMonitoreo() const;
    double getTiempoTotalDictado() const;
    IDictionary *getEstudiantesInscriptos() const;
    IDictionary *getClases() const;
    void setCodigoAsignatura(string);
    void setNombreAsignatura(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    void setTiempoTotalDictado(double);
    void setEstudiantesInscriptos(IDictionary *);
    void setClases(IDictionary *);

    DtAsignatura *getDatosAsignatura();
    Clase *iniciarClase(DtClase *dvCls) const;
    Clase *iniciarClase(DtClase *dvCls, IDictionary *habilitados) const;
    IDictionary *getDatosClasesEnDiferido() const;
    IDictionary *reproducirClase(int numeroClase, Estudiante *e) const;
    void eliminarClases();
    Clase *getClase(int numeroClase) const;
    bool comprobarInscripcionEstudiante(string cedula) const;
    void inscribirEstudiante(Estudiante *e);
    IDictionary *getDatosEstudiantesInscriptos() const;
    IDictionary *getDatosClasesEnVivoHabilitado(string cedula) const;
    DtClase *getDatosClase(int numeroClase) const;
    Clase *asistirClase(int numeroClase, Estudiante *e, string cedula) const;
    void calcularTiempoTotalDictado();
    void finalizarReproduccion(string cedula, int numeroClase);
};

#endif
