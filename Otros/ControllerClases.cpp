#include "ControllerClases.h"

ControllerClases::ControllerClases()
{
    numeroClase = 1;
    idMensaje = 1;
    habilitados = new OrderedDictionary;
}

ControllerClases &ControllerClases::getInstance()
{
    static ControllerClases *controller = new ControllerClases();
    return *controller;
}

//CU inicio de clase
IDictionary *ControllerClases::listarAsignaturasAsignadas(string email)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    Docente *d = hndlrUsr.getDocente(email);
    docActual = d;
    return d->getDatosAsignaturas();
}

TipoClase ControllerClases::crearDatosClase(string codigoAsignatura, string nombreClase, FechaHora fechaHoraComienzo)
{
    TipoClase rol = docActual->getRolDictado(codigoAsignatura);
    if (rol == teorico)
    {
        claseNueva = new DtTeorico(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura);
    }
    else if (rol == practico)
    {
        claseNueva = new DtPractico(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura);
    }
    else
    {
        claseNueva = new DtMonitoreo(numeroClase, nombreClase, fechaHoraComienzo, codigoAsignatura);
    }
    return rol;
}

IDictionary *ControllerClases::listarEstudiantesInscriptos()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    Asignatura *a = hndlrAsig.getAsignatura(claseNueva->getCodigoAsignatura());
    asigActual = a;
    return a->getDatosEstudiantesInscriptos();
}

void ControllerClases::habilitarEstudiante(string cedula)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    Estudiante *e = hndlrUsr.getEstudiante(cedula);
    IKey *k = new String(e->getCedula());
    habilitados->add(k, e);
}

DtClase *ControllerClases::obtenerInfoClase()
{
    return claseNueva;
}

void ControllerClases::confirmarInicioClase()
{
    Clase *c;
    if (dynamic_cast<DtMonitoreo *>(claseNueva) != nullptr)
    {
        c = asigActual->iniciarClase(claseNueva, habilitados);
    }
    else
    {
        c = asigActual->iniciarClase(claseNueva);
    }
    docActual->agregarClase(c);
    asigActual = nullptr;
    docActual = nullptr;
    numeroClase++;
    delete claseNueva;
}

void ControllerClases::cancelarInicioClase()
{
    asigActual = nullptr;
    docActual = nullptr;
    delete claseNueva, habilitados;
}

//CU finalizacion de clase
IDictionary *ControllerClases::listarClasesEnVivo(string email)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    docActual = hndlrUsr.getDocente(email);
    return docActual->getDatosClasesEnVivo();
}

DtClase *ControllerClases::seleccionarClaseDocente(int numeroClase)
{
    numeroClaseActual = new int(numeroClase);
    return docActual->getDatosClase(numeroClase);
}

void ControllerClases::confirmarFinalizacionClase()
{
    docActual->finalizarClase(*numeroClaseActual);
    docActual = nullptr;
    delete numeroClaseActual;
}

void ControllerClases::cancelarFinalizacionClase()
{
    docActual = nullptr;
    delete numeroClaseActual;
}

//CU envio de mensaje
IDictionary *ControllerClases::listarClasesEnVivoParticipando(string email)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    usrActual = hndlrUsr.getUsuario(email);
    return usrActual->getDatosClasesEnVivo();
}

IDictionary *ControllerClases::listarMensajes(int numeroClase)
{
    clsActual = usrActual->getClase(numeroClase);
    return usrActual->getDatosMensajes(numeroClase);
}

void ControllerClases::responderMensaje(int idMensaje, string mensaje)
{
    msjActual = clsActual->getMensaje(idMensaje);
    this->mensaje = new string(mensaje);
}

void ControllerClases::escribirMensaje(string mensaje)
{
    this->mensaje = new string(mensaje);
}

void ControllerClases::enviarMensaje()
{
    Reloj &reloj = Reloj::getInstance();
    FechaHora *fh = reloj.getFechaHoraActual();
    if (msjActual == nullptr)
    {
        clsActual->enviarMensaje(usrActual, idMensaje, *mensaje, fh);
    }
    else
    {
        clsActual->responderMensaje(usrActual, idMensaje, msjActual, *mensaje, fh);
    }
    idMensaje++;
    usrActual = nullptr;
    clsActual = nullptr;
    msjActual = nullptr;
    delete mensaje;
}

void ControllerClases::cancelarMensaje()
{
    usrActual = nullptr;
    clsActual = nullptr;
    msjActual = nullptr;
    delete mensaje;
}

//CU AsistenciaEnDiferido en vivo
IDictionary *ControllerClases::listarAsignaturasCursando(string cedula) {}
IDictionary *ControllerClases::listarClasesEnVivoHabilitado(string codigoAsignatura) {}
DtClase *ControllerClases::seleccionarClase(int numeroClase) {}
void ControllerClases::confirmarAsistencia() {}
void ControllerClases::cancelarAsistencia() {}
//CU reproduccion en diferido
IDictionary *ControllerClases::listarClasesEnDiferido(string codigoAsignatura) {}
IDictionary *ControllerClases::confirmarReproduccion() {}
void ControllerClases::cancelarReproduccion() {}
//CU listado de clases
IDictionary *ControllerClases::listarClases(string codigoAsignatura) {}

//CU tiempo de dictado
IDictionary *ControllerClases::listarAsignaturasConTiempoDictado()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    return hndlrAsig.getDatosAsignaturasConTiempoDictado();
}

//CU tiempo Asistencia
//IDictionary* ControllerClases::listarAsignaturasAsignadas(string email) {}
IDictionary *ControllerClases::listarClasesDictadas(string codigoAsignatura) {}

void ControllerClases::cargarDatosClases()
{
    Reloj &reloj = Reloj::getInstance();
    listarAsignaturasAsignadas("juan@mail.com");
    crearDatosClase("P1", "Intro", FechaHora(1, 5, 20, 9, 0, 0));
    confirmarInicioClase();
    listarAsignaturasAsignadas("juan@mail.com");
    crearDatosClase("P1", "Tema 1", FechaHora(3, 5, 20, 9, 0, 0));
    confirmarInicioClase();
    listarAsignaturasAsignadas("juan@mail.com");
    crearDatosClase("P1", "Tema 2", FechaHora(8, 5, 20, 9, 0, 0));
    confirmarInicioClase();
    listarAsignaturasAsignadas("maria@mail.com");
    crearDatosClase("P1", "Pra 1", FechaHora(2, 5, 20, 16, 0, 0));
    confirmarInicioClase();
    listarAsignaturasAsignadas("maria@mail.com");
    crearDatosClase("P1", "Pra 2", FechaHora(3, 5, 20, 16, 0, 0));
    confirmarInicioClase();
    listarAsignaturasAsignadas("jorge@mail.com");
    crearDatosClase("P1", "01/06/20", FechaHora(4, 5, 20, 16, 0, 0));
    listarEstudiantesInscriptos();
    habilitarEstudiante("23456789");
    habilitarEstudiante("34567890");
    confirmarInicioClase();

    // reloj.setFechaHoraActual(new FechaHora(1, 5, 20, 10, 0, 0));
    // listarClasesEnVivo("juan@mail.com");
    // seleccionarClaseDocente(1);
    // confirmarFinalizacionClase();
    // reloj.setFechaHoraActual(new FechaHora(3, 5, 20, 10, 0, 0));
    // listarClasesEnVivo("juan@mail.com");
    // seleccionarClaseDocente(2);
    // confirmarFinalizacionClase();
    // reloj.setFechaHoraActual(new FechaHora(8, 5, 20, 10, 0, 0));
    // listarClasesEnVivo("juan@mail.com");
    // seleccionarClaseDocente(3);
    // confirmarFinalizacionClase();
    // reloj.setFechaHoraActual(new FechaHora(2, 5, 20, 17, 0, 0));
    // listarClasesEnVivo("maria@mail.com");
    // seleccionarClaseDocente(4);
    // confirmarFinalizacionClase();
    // reloj.setFechaHoraActual(new FechaHora(3, 5, 20, 17, 0, 0));
    // listarClasesEnVivo("maria@mail.com");
    // seleccionarClaseDocente(5);
    // confirmarFinalizacionClase();
    // reloj.setFechaHoraActual(new FechaHora(4, 5, 20, 17, 0, 0));
    // listarClasesEnVivo("jorge@mail.com");
    // seleccionarClaseDocente(6);
    // confirmarFinalizacionClase();
}