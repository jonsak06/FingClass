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
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    asigActual = hndlrAsig.getAsignatura(codigoAsignatura);

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
    return asigActual->getDatosEstudiantesInscriptos();
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
    c->setNombreDocente(docActual->getNombre());
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
IDictionary *ControllerClases::listarClasesEnVivoParticipando(string clave)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    usrActual = hndlrUsr.getUsuario(clave);
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

//CU Asistencia en vivo
IDictionary *ControllerClases::listarAsignaturasCursando(string cedula)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    estActual = hndlrUsr.getEstudiante(cedula);
    return hndlrAsig.getDatosAsignaturasCursando(cedula);
}

IDictionary *ControllerClases::listarClasesEnVivoHabilitado(string codigoAsignatura)
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    asigActual = hndlrAsig.getAsignatura(codigoAsignatura);
    return asigActual->getDatosClasesEnVivoHabilitado(estActual->getCedula());
}

DtClase *ControllerClases::seleccionarClase(int numeroClase)
{
    numeroClaseActual = new int(numeroClase);
    return asigActual->getDatosClase(numeroClase);
}

void ControllerClases::confirmarAsistencia()
{
    Clase *c = asigActual->asistirClase(*numeroClaseActual, estActual, estActual->getCedula());
    estActual->agregarClase(c);
    estActual = nullptr;
    asigActual = nullptr;
    delete numeroClaseActual;
}

void ControllerClases::cancelarAsistencia()
{
    estActual = nullptr;
    asigActual = nullptr;
    delete numeroClaseActual;
}

//CU reproduccion en diferido
IDictionary *ControllerClases::listarClasesEnDiferido(string codigoAsignatura)
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    asigActual = hndlrAsig.getAsignatura(codigoAsignatura);
    return asigActual->getDatosClasesEnDiferido();
}

IDictionary *ControllerClases::confirmarReproduccion()
{
    IDictionary *datosMensajes = asigActual->reproducirClase(*numeroClaseActual, estActual);
    Clase *c = asigActual->getClase(*numeroClaseActual);
    estActual->agregarClase(c);
    asigActual = nullptr;
    estActual = nullptr;
    delete numeroClaseActual;
    return datosMensajes;
}

void ControllerClases::cancelarReproduccion()
{
    asigActual = nullptr;
    estActual = nullptr;
    delete numeroClaseActual;
}

//CU listado de clases
IDictionary *ControllerClases::listarClases(string codigoAsignatura)
{
    IDictionary *datosClases = docActual->getDatosClases(codigoAsignatura);
    docActual = nullptr;
    return datosClases;
}

//CU tiempo de dictado
IDictionary *ControllerClases::listarAsignaturas()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    return hndlrAsig.getDatosAsignaturas();
}

//CU tiempo Asistencia = listarAsignaturasAsignadas y listarClases


// void ControllerClases::finalizarReproduccionClase(string cedula, int numeroClase) {
//     HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
//     Estudiante *e = hndlrUsr.getEstudiante(cedula);
//     e->finalizarReproduccionClase(numeroClase);
// }

void ControllerClases::cargarDatosClases()
{
    Reloj &reloj = Reloj::getInstance();
    //inicio de clase
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
    // listarAsignaturasAsignadas("jorge@mail.com");
    // crearDatosClase("P1", "01/06/20", FechaHora(4, 5, 20, 16, 0, 0));
    // listarEstudiantesInscriptos();
    // habilitarEstudiante("23456789");
    // habilitarEstudiante("34567890");
    // confirmarInicioClase();

    //asistencia en vivo
    reloj.setFechaHoraActual(new FechaHora(1, 5, 20, 9, 1, 0));
    listarAsignaturasCursando("12345678");
    listarClasesEnVivoHabilitado("P1");
    seleccionarClase(1);
    confirmarAsistencia();
    reloj.setFechaHoraActual(new FechaHora(1, 5, 20, 9, 2, 0));
    listarAsignaturasCursando("23456789");
    listarClasesEnVivoHabilitado("P1");
    seleccionarClase(1);
    confirmarAsistencia();
    reloj.setFechaHoraActual(new FechaHora(1, 5, 20, 9, 3, 0));
    listarAsignaturasCursando("34567890");
    listarClasesEnVivoHabilitado("P1");
    seleccionarClase(1);
    confirmarAsistencia();
    // reloj.setFechaHoraActual(new FechaHora(4, 5, 20, 16, 0, 0));
    // listarAsignaturasCursando("34567890");
    // listarClasesEnVivoHabilitado("P1");
    // seleccionarClase(6);
    // confirmarAsistencia();

    //envio de mensaje
    listarClasesEnVivoParticipando("juan@mail.com");
    listarMensajes(1);
    escribirMensaje("Bienvenidos!");
    enviarMensaje();
    listarClasesEnVivoParticipando("juan@mail.com");
    listarMensajes(1);
    escribirMensaje("Confirmen materiales por favor.");
    enviarMensaje();
    // listarClasesEnVivoParticipando("jorge@mail.com");
    // listarMensajes(6);
    // escribirMensaje("Comparto pantalla");
    // enviarMensaje();
    listarClasesEnVivoParticipando("12345678");
    listarMensajes(1);
    responderMensaje(1, "Listo para aprender");
    enviarMensaje();
    listarClasesEnVivoParticipando("juan@mail.com");
    listarMensajes(1);
    responderMensaje(4, "Me alegro");
    enviarMensaje();
    listarClasesEnVivoParticipando("23456789");
    listarMensajes(1);
    responderMensaje(2, "Todo listo");
    enviarMensaje();
    // listarClasesEnVivoParticipando("34567890");
    // listarMensajes(6);
    // responderMensaje(3, "Ya la vemos");
    // enviarMensaje();

    // finalizacion de clase
    reloj.setFechaHoraActual(new FechaHora(1, 5, 20, 10, 0, 0));
    listarClasesEnVivo("juan@mail.com");
    seleccionarClaseDocente(1);
    confirmarFinalizacionClase();
    reloj.setFechaHoraActual(new FechaHora(3, 5, 20, 10, 0, 0));
    listarClasesEnVivo("juan@mail.com");
    seleccionarClaseDocente(2);
    confirmarFinalizacionClase();
    reloj.setFechaHoraActual(new FechaHora(8, 5, 20, 10, 0, 0));
    listarClasesEnVivo("juan@mail.com");
    seleccionarClaseDocente(3);
    confirmarFinalizacionClase();
    reloj.setFechaHoraActual(new FechaHora(2, 5, 20, 17, 0, 0));
    listarClasesEnVivo("maria@mail.com");
    seleccionarClaseDocente(4);
    confirmarFinalizacionClase();
    reloj.setFechaHoraActual(new FechaHora(3, 5, 20, 17, 0, 0));
    listarClasesEnVivo("maria@mail.com");
    seleccionarClaseDocente(5);
    confirmarFinalizacionClase();
    // reloj.setFechaHoraActual(new FechaHora(4, 5, 20, 17, 0, 0));
    // listarClasesEnVivo("jorge@mail.com");
    // seleccionarClaseDocente(6);
    // confirmarFinalizacionClase();

    reloj.setFechaHoraActual(new FechaHora(12,5,20,9,1,0));
    listarAsignaturasCursando("12345678");
    listarClasesEnDiferido("P1");
    seleccionarClase(1);
    confirmarReproduccion();
    reloj.setFechaHoraActual(new FechaHora(12,5,20,9,1,0));
    listarAsignaturasCursando("23456789");
    listarClasesEnDiferido("P1");
    seleccionarClase(2);
    confirmarReproduccion();
    reloj.setFechaHoraActual(new FechaHora(13,5,20,10,1,0));
    listarAsignaturasCursando("23456789");
    listarClasesEnDiferido("P1");
    seleccionarClase(2);
    confirmarReproduccion();
    reloj.setFechaHoraActual(new FechaHora(14,5,20,9,1,0));
    listarAsignaturasCursando("23456789");
    listarClasesEnDiferido("P1");
    seleccionarClase(2);
    confirmarReproduccion();
}