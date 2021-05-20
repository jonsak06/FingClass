#ifndef COLDOCENTES_H
#define COLDOCENTES_H

#include "../Clases/Docente.h"
#include <vector>

using namespace std;

class ColDocentes
{
private:
    vector <Docente> docentes;
public:
    ColDocentes();
    ~ColDocentes();
};

#endif