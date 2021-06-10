#ifndef FACTORY_H
#define FACTORY_H

#include "ControllerAsignaturasUsuarios.h"
#include "ControllerClases.h"

class Factory
{
private:
    Factory() = default;
    Factory(const Factory&) = delete;
    Factory& operator=(const Factory&) = delete;
    Factory(Factory&&) = delete;
    Factory& operator=(Factory&&) = delete;
public:
    static Factory& getInstance();
    IAsignaturasUsuarios& getCtrlAsigUsr();
    IClases& getCtrlClases();
};

#endif