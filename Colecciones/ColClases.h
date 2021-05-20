#ifndef COLCLASES_H
#define COLCLASES_H

#include "../Clases/Clase.h"
#include <vector>

using namespace std;

class ColClases
{
private:
    vector <Clase*> clases;
public:
    ColClases();
    ~ColClases();
};

#endif