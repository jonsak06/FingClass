#ifndef COLFECHAHORA_H
#define COLFECHAHORA_H

#include "../Datatypes/DtFechaHora.h"
#include <vector>

using namespace std;

class ColFechaHora
{
private:
    vector <DtFechaHora> fechaHora;
public:
    ColFechaHora();
    ~ColFechaHora();
};

#endif