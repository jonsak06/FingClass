#include "Factory.h"

Factory& Factory::getInstance() {
    static Factory* factory = new Factory();
    return *factory;
}

IAsignaturasUsuarios& Factory::getCtrlAsigUsr() {
    return ControllerAsignaturasUsuarios::getInstance();
}

IClases& Factory::getCtrlClases() {
    return ControllerClases::getInstance();
}