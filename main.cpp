#include "Otros/Factory.h"

int main() {
    Factory& fabrica = Factory::getInstance();
    IClases& controlador1 = fabrica.getCtrlClases();
    IAsignaturasUsuarios& controlador2 = fabrica.getCtrlAsigUsr();
    controlador1.cancelarInicioClase();
    controlador2.confirmarAltaUsuario();
}