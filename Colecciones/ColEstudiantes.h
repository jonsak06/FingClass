#ifndef COLESTUDIANTES_H
#define COLESTUDIANTES_H

#include "../Clases/Estudiante.h"
#include <vector>

using namespace std;

class ColEstudiantes
{
private:
    vector <Estudiante> estudiantes;
    Estudiante estudiantesHabilitados[14];
public:
    ColEstudiantes();
    ~ColEstudiantes();
};

#endif