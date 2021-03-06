#include "ControllerAsignaturasUsuarios.h"

ControllerAsignaturasUsuarios &ControllerAsignaturasUsuarios::getInstance()
{
    static ControllerAsignaturasUsuarios *controller = new ControllerAsignaturasUsuarios();
    return *controller;
}

//CU Alta usuario
void ControllerAsignaturasUsuarios::agregarDocente(string nombre, string email, string contrasenia, string urlImgPerfil, string nombreInstituto)
{
    dvUsr = new DtDocente(nombre, email, contrasenia, urlImgPerfil, nombreInstituto);
}

void ControllerAsignaturasUsuarios::agregarEstudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula)
{
    dvUsr = new DtEstudiante(nombre, email, contrasenia, urlImgPerfil, cedula);
}

void ControllerAsignaturasUsuarios::confirmarAltaUsuario()
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    hndlrUsr.agregarUsuario(dvUsr);
    delete dvUsr;
}

void ControllerAsignaturasUsuarios::cancelarAltaUsuario()
{
    delete dvUsr;
}

//CU Alta asignatura
DtAsignatura *ControllerAsignaturasUsuarios::agregarAsignatura(string codigoAsignatura, string nombreAsignatura, bool teorico, bool practico, bool monitoreo)
{
    dvAsig = new DtAsignatura(codigoAsignatura, nombreAsignatura, teorico, practico, monitoreo);
    return dvAsig;
}
void ControllerAsignaturasUsuarios::confirmarAltaAsignatura()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    hndlrAsig.agregarAsignatura(dvAsig);
    delete dvAsig;
}
void ControllerAsignaturasUsuarios::cancelarAltaAsignatura()
{
    delete dvAsig;
}

//CU asignacion docente a asignatura
IDictionary *ControllerAsignaturasUsuarios::listarAsignaturas()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    return hndlrAsig.getDatosAsignaturas();
}

IDictionary *ControllerAsignaturasUsuarios::listarDocentesSinAsignar(string codigoAsignatura)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    this->codigoAsignatura = new string(codigoAsignatura);
    return hndlrUsr.getDatosDocentesSinAsignar(codigoAsignatura);
}

void ControllerAsignaturasUsuarios::seleccionarDocente(string email, TipoClase rolDictado)
{
    this->email = new string(email);
    this->rolDictado = new TipoClase(rolDictado);
}

void ControllerAsignaturasUsuarios::confirmarAsignacion()
{

    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    Asignatura *a = hndlrAsig.getAsignatura(*codigoAsignatura);
    Docente *d = hndlrUsr.getDocente(*email);
    d->asignarAsignatura(a, *rolDictado);

    delete email;
    delete rolDictado;
}

void ControllerAsignaturasUsuarios::cancelarAsignacion()
{
    delete email;
    delete rolDictado;
}

void ControllerAsignaturasUsuarios::dejarDeAsignarDocentes()
{
    delete codigoAsignatura;
}

//CU inscripcion a asignaturas
IDictionary *ControllerAsignaturasUsuarios::listarAsignaturasNoInscripto(string cedula)
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    this->cedula = new string(cedula);
    return hndlrAsig.getDatosAsignaturasNoInscripto(cedula);
}

void ControllerAsignaturasUsuarios::seleccionarAsignatura(string codigoAsignatura)
{
    this->codigoAsignatura = new string(codigoAsignatura);
}

void ControllerAsignaturasUsuarios::confirmarInscripcion()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    Asignatura *a = hndlrAsig.getAsignatura(*codigoAsignatura);
    Estudiante *e = hndlrUsr.getEstudiante(*cedula);
    a->inscribirEstudiante(e);
    delete cedula, codigoAsignatura;
}

void ControllerAsignaturasUsuarios::cancelarInscripcion()
{
    delete cedula, codigoAsignatura;
}

//CU eliminar asignatura
void ControllerAsignaturasUsuarios::confirmarEliminacion()
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    hndlrUsr.removerClasesYAsignacionDocentes(*codigoAsignatura);
    hndlrUsr.removerClasesEstudiantes(*codigoAsignatura);
    Asignatura *a = hndlrAsig.getAsignatura(*codigoAsignatura);
    a->eliminarClases();
    hndlrAsig.eliminarAsignatura(*codigoAsignatura);
    delete codigoAsignatura;
}

void ControllerAsignaturasUsuarios::cancelarEliminacion()
{
    delete codigoAsignatura;
}

bool ControllerAsignaturasUsuarios::tieneClaseDe(string codigoAsignatura, TipoClase tipoClase)
{
    HandlerAsignaturas &hndlrAsig = HandlerAsignaturas::getInstance();
    return hndlrAsig.tieneClaseDe(codigoAsignatura, tipoClase);
}

IDictionary *ControllerAsignaturasUsuarios::listarEstudiantes()
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    return hndlrUsr.getDatosEstudiantes();
}

IDictionary *ControllerAsignaturasUsuarios::listarDocentes()
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    return hndlrUsr.getDatosDocentes();
}

bool ControllerAsignaturasUsuarios::existeUsuario(string clave)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    return hndlrUsr.existeUsuario(clave);
}

bool ControllerAsignaturasUsuarios::confirmarPassword(string clave, string password)
{
    HandlerUsuarios &hndlrUsr = HandlerUsuarios::getInstance();
    return hndlrUsr.confirmarPass(clave, password);
}

void ControllerAsignaturasUsuarios::cargarDatosAsigUsr()
{
    //alta de usuarios
    agregarDocente("Juan Perez", "juan@mail.com", "1234", "http://fingclass.edu.uy/imagenes/juanp.jpg", "INCO");
    confirmarAltaUsuario();
    agregarDocente("Maria Pires", "maria@mail.com", "1234", "http://fingclass.edu.uy/imagenes/mariap.jpg", "INCO");
    confirmarAltaUsuario();
    agregarDocente("Jorge Chacho", "jorge@mail.com", "1234", "http://fingclass.edu.uy/imagenes/jorgec.jpg", "INCO");
    confirmarAltaUsuario();
    agregarEstudiante("Roberto Parra", "roberto@mail.com", "1234", "http://fingclass.edu.uy/imagenes/robertop.jpg", "12345678");
    confirmarAltaUsuario();
    agregarEstudiante("Ana Rodriguez", "ana@mail.com", "1234", "http://fingclass.edu.uy/imagenes/anar.jpg", "23456789");
    confirmarAltaUsuario();
    agregarEstudiante("Ramon Valdez", "ramon@mail.com", "1234", "http://fingclass.edu.uy/imagenes/ramonv.jpg", "34567890");
    confirmarAltaUsuario();

    //alta de asignaturas
    agregarAsignatura("P1", "Programacion 1", true, true, true);
    confirmarAltaAsignatura();
    agregarAsignatura("P2", "Programacion 2", true, true, true);
    confirmarAltaAsignatura();
    agregarAsignatura("P3", "Programacion 3", true, true, false);
    confirmarAltaAsignatura();

    //asignacion de docentes a asignaturas
    seleccionarAsignatura("P1");
    seleccionarDocente("juan@mail.com", teorico);
    confirmarAsignacion();
    seleccionarDocente("maria@mail.com", practico);
    confirmarAsignacion();
    seleccionarDocente("jorge@mail.com", monitoreo);
    confirmarAsignacion();
    dejarDeAsignarDocentes();

    //inscripcion a asignaturas
    cedula = new string("12345678");
    seleccionarAsignatura("P1");
    confirmarInscripcion();
    cedula = new string("23456789");
    seleccionarAsignatura("P1");
    confirmarInscripcion();
    cedula = new string("23456789");
    seleccionarAsignatura("P2");
    confirmarInscripcion();
    cedula = new string("34567890");
    seleccionarAsignatura("P1");
    confirmarInscripcion();
}