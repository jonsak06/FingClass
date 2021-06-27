#include "Otros/Factory.h"
#include "Datatypes/DtAsignatura.h"
#include "Otros/Reloj.h"
#include "ICollection/String.h"
#include <iostream>
#include <sstream>

int menuUsuario();
int menuAdministrador();
int menuDocente();
int menuEstudiante();
int menuConfirmacion();
void pausarConsola();
int stringToInt(string);

using namespace std;

int main()
{
    Factory &fabrica = Factory::getInstance();
    IClases &clases = fabrica.getCtrlClases();
    IAsignaturasUsuarios &asigUsr = fabrica.getCtrlAsigUsr();
    Reloj &reloj = Reloj::getInstance();
    int opcion;

    do
    {
        opcion = menuUsuario();
        switch (opcion)
        {
        case 1:
        {
            int opt;
            do
            {
                opt = menuAdministrador();
                switch (opt)
                {
                case 1: //listo
                {
                    string opc;
                    int op;
                    string nombre, email, contrasenia, urlImgPerfil, nombreInstituto, cedula;
                    while (true)
                    {
                        cout << "Tipo de usuario a agregar:\n1- Docente\n2- Estudiante\n";
                        getline(cin, opc);
                        op = stringToInt(opc);
                        if (op == 1 || op == 2)
                        {
                            system("clear");
                            break;
                        }
                        system("clear");
                    }

                    cout << "Ingrese el nombre: ";
                    getline(cin >> ws, nombre);
                    cout << "Ingrese el email: ";
                    getline(cin >> ws, email);
                    cout << "Ingrese la contrasenia: ";
                    getline(cin >> ws, contrasenia);
                    cout << "Ingrese la url de la imagen de perfil: ";
                    getline(cin >> ws, urlImgPerfil);

                    if (op == 1)
                    {
                        cout << "Ingrese el nombre del instituto: ";
                        getline(cin >> ws, nombreInstituto);
                        asigUsr.agregarDocente(nombre, email, contrasenia, urlImgPerfil, nombreInstituto);
                    }
                    else
                    {
                        cout << "Ingrese la cedula: ";
                        getline(cin >> ws, cedula);
                        asigUsr.agregarEstudiante(nombre, email, contrasenia, urlImgPerfil, cedula);
                    }

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarAltaUsuario();
                    }
                    else
                    {
                        asigUsr.cancelarAltaUsuario();
                    }
                }
                break;

                case 2: //listo
                {
                    string nombreAsignatura, codigoAsignatura;
                    bool teorico, practico, monitoreo;
                    string opc;
                    int op;
                    cout << "Ingrese el codigo de la asignatura: ";
                    getline(cin >> ws, codigoAsignatura);
                    cout << "Ingrese el nombre de la asignatura: ";
                    getline(cin >> ws, nombreAsignatura);

                    cout << "\nTiene teorico?\n1- Si\n2- No\n";
                    getline(cin, opc);
                    op = stringToInt(opc);
                    if (op == 1)
                    {
                        teorico = true;
                    }
                    else
                    {
                        teorico = false;
                    }

                    cout << "\nTiene practico?\n1- Si\n2- No\n";
                    getline(cin, opc);
                    op = stringToInt(opc);
                    if (op == 1)
                    {
                        practico = true;
                    }
                    else
                    {
                        practico = false;
                    }

                    cout << "\nTiene monitoreo?\n1- Si\n2- No\n";
                    getline(cin, opc);
                    op = stringToInt(opc);
                    if (op == 1)
                    {
                        monitoreo = true;
                    }
                    else
                    {
                        monitoreo = false;
                    }
                    system("clear");
                    cout << "Datos de la asignatura:\n";
                    cout << asigUsr.agregarAsignatura(codigoAsignatura, nombreAsignatura, teorico, practico, monitoreo);

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarAltaAsignatura();
                    }
                    else
                    {
                        asigUsr.cancelarAltaAsignatura();
                    }
                }
                break;

                case 3: //listo
                {
                    IDictionary *datosAsignaturas = asigUsr.listarAsignaturas();
                    IIterator *it = datosAsignaturas->getIterator();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No existen asignaturas en el sistema\n";
                        pausarConsola();
                        delete it;
                        break;
                    }

                    cout << "Listado de asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig;
                    }
                    delete it;

                    string codAsig;
                    bool existeAsignatura;
                    IKey *k;

                    do
                    {
                        cout << "\nCodigo de la asignatura seleccionada: ";
                        getline(cin >> ws, codAsig);
                        k = new String(codAsig);
                        existeAsignatura = datosAsignaturas->find(k) != NULL;
                        if (!existeAsignatura)
                        {
                            cout << "\nLa asignatura no existe\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
                    system("clear");

                    string email, opc;
                    int op, o;
                    bool seguirAsignando = true, existeDocente;
                    IDictionary *datosDocentes = asigUsr.listarDocentesSinAsignar(codAsig);

                    do
                    {
                        if (datosDocentes->isEmpty())
                        {
                            cout << "\nNo existen docentes sin asignar\n";
                            asigUsr.dejarDeAsignarDocentes();
                            pausarConsola();
                            break;
                        }

                        it = datosDocentes->getIterator();
                        cout << "Listado de docentes sin asignar:\n";
                        for (it; it->hasCurrent(); it->next())
                        {
                            DtDocente *dvDoc = dynamic_cast<DtDocente *>(it->getCurrent());
                            cout << dvDoc;
                        }
                        delete it;

                        do
                        {
                            cout << "\nEmail del docente seleccionado: ";
                            getline(cin >> ws, email);
                            k = new String(email);
                            existeDocente = datosDocentes->find(k) != NULL;
                            if (!existeDocente)
                            {
                                cout << "\nEl docente no existe o ya esta asignado\n";
                            }
                            delete k;
                        } while (!existeDocente);

                        TipoClase rolDictado;
                        while (true)
                        {

                            cout << "\nSeleccione el rol de dictado del docente:\n1- Teorico\n2- Practico\n3- Monitoreo\n";
                            getline(cin, opc);
                            op = stringToInt(opc);

                            if (op == 1)
                            {
                                rolDictado = teorico;
                            }
                            else if (op == 2)
                            {
                                rolDictado = practico;
                            }
                            else
                            {
                                rolDictado = monitoreo;
                            }

                            if (asigUsr.tieneClaseDe(codAsig, rolDictado))
                            {
                                break;
                            }
                            cout << "\nLa asignatura no tiene ese tipo de clase\n";
                            pausarConsola();
                            system("clear");
                        }
                        asigUsr.seleccionarDocente(email, rolDictado);

                        op = menuConfirmacion();
                        if (op == 1)
                        {
                            asigUsr.confirmarAsignacion();
                            k = new String(email);
                            datosDocentes->remove(k);
                            delete k;
                            cout << "\nDocente asignado\n";
                        }
                        else
                        {
                            asigUsr.cancelarAsignacion();
                        }

                        if (datosDocentes->isEmpty())
                        {
                            cout << "\nNo quedan docentes sin asignar\n";
                            asigUsr.dejarDeAsignarDocentes();
                            pausarConsola();
                            break;
                        }

                        cout << "\nDesea seguir asignando docentes? 1- Si 2- No\n";
                        getline(cin, opc);
                        o = stringToInt(opc);
                        if (o == 2)
                        {
                            seguirAsignando = false;
                            asigUsr.dejarDeAsignarDocentes();
                        }
                    } while (seguirAsignando);
                }
                break;

                case 4: //listo
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturasConTiempoDictado();
                    IIterator *it = datosAsignaturas->getIterator();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No existen asignaturas en el sistema\n";
                        pausarConsola();
                        delete it;
                        break;
                    }

                    cout << "Tiempo de dictado de clases por asignatura:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << endl
                             << "Nombre: " << dvAsig->getNombreAsignatura() << endl;
                        cout << "Tiempo de dictado: " << dvAsig->getTiempoTotalDictado() << endl;
                    }
                    pausarConsola();
                }
                break;

                case 5: //listo
                {
                    IDictionary *datosAsignaturas = asigUsr.listarAsignaturas();
                    IIterator *it = datosAsignaturas->getIterator();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No existen asignaturas en el sistema\n";
                        pausarConsola();
                        delete it;
                        break;
                    }

                    cout << "Listado de asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig;
                    }

                    string codAsig;
                    bool existeAsignatura;
                    IKey *k;
                    do
                    {
                        cout << "\nCodigo de la asignatura seleccionada: ";
                        getline(cin >> ws, codAsig);
                        k = new String(codAsig);
                        existeAsignatura = datosAsignaturas->find(k) != NULL;
                        if (!existeAsignatura)
                        {
                            cout << "\nLa asignatura no existe\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;

                    asigUsr.seleccionarAsignatura(codAsig);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarEliminacion();
                    }
                    else
                    {
                        asigUsr.cancelarEliminacion();
                    }
                    cout << "\nAsignatura eliminada\n";
                    pausarConsola();
                }
                break;

                case 6: //listo
                {
                    FechaHora *fh = reloj.getFechaHoraActual();
                    if (fh != NULL)
                    {
                        cout << "Fecha y hora del sistema:\n";
                        cout << reloj.getFechaHoraActual();
                        pausarConsola();
                    }
                    else
                    {
                        cout << "No hay fecha ni hora registrada en el reloj del sistema\n";
                        pausarConsola();
                    }
                }
                break;

                case 7: //listo
                {
                    string num;
                    int dia, mes, anio, hora, min, seg;
                    cout << "Ingrese la fecha:\n";
                    cout << "Dia: ";
                    getline(cin, num);
                    dia = stringToInt(num);
                    cout << "Mes: ";
                    getline(cin, num);
                    mes = stringToInt(num);
                    cout << "Anio: ";
                    getline(cin, num);
                    anio = stringToInt(num);
                    system("clear");
                    cout << "Ingrese la hora:\n";
                    cout << "Hora: ";
                    getline(cin, num);
                    hora = stringToInt(num);
                    cout << "Minuto: ";
                    getline(cin, num);
                    min = stringToInt(num);
                    cout << "Segundo: ";
                    getline(cin, num);
                    seg = stringToInt(num);
                    reloj.setFechaHoraActual(new FechaHora(dia, mes, anio, hora, min, seg));
                    cout << "\nFecha y hora registrada\n";
                    pausarConsola();
                }
                break;

                case 8:
                    break;

                default:
                    break;
                }
            } while (opt != 8);
        }
        break;

        case 2:
        {
            int opt;
            do
            {
                opt = menuDocente();
                switch (opt)
                {
                case 1: //falta arreglarlo
                {
                    string email;
                    //si da el tiempo: agregar listarEstudiantes para corroborar que exista o clase sesion para que no pida los datos
                    cout << "Ingrese su direccion de email: ";
                    getline(cin >> ws, email);
                    IDictionary *datosAsignaturas = clases.listarAsignaturasAsignadas(email);
                    IIterator *it = datosAsignaturas->getIterator();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No tiene asignaturas asignadas\n";
                        pausarConsola();
                        delete it;
                        clases.cancelarInicioClase();
                        break;
                    }
                    cout << "\nListado de sus asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig;
                    }
                    delete it;

                    string codAsig, nombreClase;
                    IKey *k;
                    bool existeAsignatura = false;

                    do
                    {
                        cout << "\nCodigo de la asignatura seleccionada: ";
                        getline(cin >> ws, codAsig);
                        k = new String(codAsig);
                        existeAsignatura = datosAsignaturas->find(k) != NULL;
                        if (!existeAsignatura)
                        {
                            cout << "\nLa asignatura no existe\n";
                        }
                        delete k, datosAsignaturas;
                    } while (!existeAsignatura);
                    system("clear");

                    cout << "Ingrese el nombre de la clase: ";
                    getline(cin >> ws, nombreClase);
                    int dia, mes, anio, hora, min, seg;
                    string num;
                    cout << "\nIngrese la fecha de comienzo:\n";
                    cout << "\nDia: ";
                    getline(cin, num);
                    dia = stringToInt(num);
                    cout << "Mes: ";
                    getline(cin, num);
                    mes = stringToInt(num);
                    cout << "Anio: ";
                    getline(cin, num);
                    anio = stringToInt(num);
                    cout << "\nIngrese la hora de comienzo:\n";
                    cout << "Hora: ";
                    getline(cin, num);
                    hora = stringToInt(num);
                    cout << "Minuto: ";
                    getline(cin, num);
                    min = stringToInt(num);
                    cout << "Segundo: ";
                    getline(cin, num);
                    seg = stringToInt(num);
                    TipoClase tipoClase = clases.crearDatosClase(codAsig, nombreClase, FechaHora(dia, mes, anio, hora, min, seg));

                    

                    if (tipoClase == monitoreo)
                    {
                        system("clear");
                        IDictionary *datosEstudiantes = clases.listarEstudiantesInscriptos();
                        if (datosEstudiantes->isEmpty())
                        {
                            cout << "No existen estudiantes inscriptos para habilitar\n";
                            pausarConsola();
                            clases.cancelarInicioClase();
                            break;
                        }
                        
                        string cedula;
                        bool seguirHabilitando = true;
                        int i = 0;
                        while (seguirHabilitando && i < 15 && !datosEstudiantes->isEmpty())
                        {
                            it = datosEstudiantes->getIterator();

                            
                            DtEstudiante *dvEst;
                            cout << "Listado de estudiantes inscriptos a la asignatura:\n";
                            for (it; it->hasCurrent(); it->next())
                            {
                                dvEst = dynamic_cast<DtEstudiante *>(it->getCurrent());
                                cout << dvEst;
                            }
                            delete it;

                            cout << "\nCedula del estudiante seleccionado: ";
                            getline(cin >> ws, cedula);
                            k = new String(cedula);
                            if (datosEstudiantes->find(k) != NULL)
                            {
                                clases.habilitarEstudiante(cedula);
                                datosEstudiantes->remove(k);
                                delete k;
                                system("clear");
                                cout << "\nEstudiante habilitado\n";
                            }
                            else
                            {
                                cout << "\nEl estudiante no existe o no cursa la asignatura\n";
                                delete k;
                                system("clear");
                                continue;
                            }
                            i++;
                            if (datosEstudiantes->isEmpty())
                            {
                                cout << "No existen mas estudiantes inscriptos\n";
                                pausarConsola();
                                delete it;
                                seguirHabilitando = false;
                            }
                            else if (i < 15)
                            {
                                int op;
                                cout << "\nDesea seguir habilitando estudiantes? 1- Si 2- No\n";
                                getline(cin, num);
                                op = stringToInt(num);
                                if (op == 2)
                                {
                                    seguirHabilitando = false;
                                }
                                system("clear");
                            }
                        }
                        delete datosEstudiantes;
                    }
                    system("clear");
                    cout << "\nInformacion de la clase:\n";
                    cout << clases.obtenerInfoClase();

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.confirmarInicioClase();
                        cout << "\nClase iniciada\n";
                        pausarConsola();
                    }
                    else
                    {
                        clases.cancelarInicioClase();
                    }
                }
                break;

                case 2: //agregar controles de existencia
                {
                    string email;
                    cout << "Ingrese su direccion de email: ";
                    getline(cin >> ws, email);
                    IDictionary *datosClases = clases.listarClasesEnVivo(email);
                    IIterator *it = datosClases->getIterator();

                    cout << "Listado de sus clases en vivo:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls;
                    }

                    int nroCls;
                    cout << "Numero de la clase seleccioanda: ";
                    cin >> nroCls;
                    DtClase *dvCls = clases.seleccionarClaseDocente(nroCls);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.confirmarFinalizacionClase();
                    }
                    else
                    {
                        clases.cancelarFinalizacionClase();
                    }
                    system("clear");
                }
                break;

                case 3: //agregar controles de existencia
                {
                    string email;
                    cout << "Ingrese su direccion de email: ";
                    getline(cin >> ws, email);
                    IDictionary *datosClases = clases.listarClasesEnVivoParticipando(email);
                    IIterator *it = datosClases->getIterator();

                    cout << "Listado de sus clases en vivo:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls;
                    }
                    delete datosClases;

                    int nroCls;
                    string num;
                    cout << "Numero de la clase seleccioanda: ";
                    getline(cin,num);
                    nroCls = stringToInt(num);
                    IDictionary *datosMensajes = clases.listarMensajes(nroCls);
                    it = datosMensajes->getIterator();
                    cout << "\nMensajes de la clase:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtMensaje *dvMsj = dynamic_cast<DtMensaje *>(it->getCurrent());
                        cout << dvMsj;
                    }

                    string mensaje;
                    cout << "\nIngrese su mensaje: ";
                    getline(cin >> ws, mensaje);
                    int op;
                    string opc;
                    if (datosMensajes->isEmpty())
                    {
                        cout << "Su mensaje es respuesta? 1- Si 2- No\n";
                        getline(cin,opc);
                        op = stringToInt(opc);
                    }
                    
                    
                    int idMensaje;
                    if (op == 1)
                    {
                        cout << "ID del mensaje al que responde: ";
                        getline(cin,num);
                        idMensaje = stringToInt(opc);
                        clases.responderMensaje(idMensaje, mensaje);
                    }
                    else
                    {
                        clases.escribirMensaje(mensaje);
                    }

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.enviarMensaje();
                    }
                    else
                    {
                        clases.cancelarMensaje();
                    }
                    system("clear");
                }
                break;

                case 4:
                {
                    string email;
                    cout << "Ingrese su direccion de email: ";
                    getline(cin >> ws, email);
                    IDictionary *datosAsignaturas = clases.listarAsignaturasAsignadas(email);
                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "Listado de sus asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig;
                    }

                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
                    IDictionary *datosClases = clases.listarClases(codAsig);
                    it = datosClases->getIterator();

                    cout << "Listado de sus clases:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls->getNombreClase(); //sobrecargar el cout en DtClase
                    }
                    system("clear");
                }
                break;

                case 5:
                {
                    string email;
                    cout << "Ingrese su direccion de email: ";
                    getline(cin >> ws, email);
                    IDictionary *datosAsignaturas = clases.listarAsignaturasAsignadas(email);
                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "Listado de sus asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig;
                    }

                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
                    IDictionary *datosClases = clases.listarClasesDictadas(codAsig);
                    it = datosClases->getIterator();

                    cout << "Tiempo de asistencia a sus clases de la asignatura seleccionada:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls->getNombreClase(); //sobrecargar el cout en DtClase
                    }
                    system("clear");
                }
                break;

                case 6:
                    break;

                default:
                    break;
                }
            } while (opt != 6);
        }
        break;

        case 3:
        {
            int opt;
            do
            {
                opt = menuEstudiante();
                switch (opt)
                {
                case 1: //listo
                {
                    string cedula;
                    cout << "Ingrese su cedula: ";
                    getline(cin >> ws, cedula);
                    IDictionary *datosAsignaturas = asigUsr.listarAsignaturasNoInscripto(cedula);
                    IIterator *it = datosAsignaturas->getIterator();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "\nNo existen asignaturas a las que no este inscripto\n";
                        pausarConsola();
                        delete it;
                        break;
                    }

                    cout << "\nListado de asignaturas a las que no esta inscripto:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig;
                    }

                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
                    asigUsr.seleccionarAsignatura(codAsig);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarInscripcion();
                    }
                    else
                    {
                        asigUsr.cancelarInscripcion();
                    }
                    cout << "Inscripcion realizada\n";
                    pausarConsola();
                }
                break;

                case 2:
                {
                    string email;
                    cout << "Ingrese su direccion de email: ";
                    getline(cin >> ws, email);
                    IDictionary *datosClases = clases.listarClasesEnVivoParticipando(email);
                    IIterator *it = datosClases->getIterator();

                    cout << "Listado de sus clases en vivo:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls->getNombreClase(); //sobrecargar el cout en DtClase
                    }

                    int nroCls;
                    cout << "Numero de la clase seleccioanda: ";
                    cin >> nroCls;
                    IDictionary *datosMensajes = clases.listarMensajes(nroCls);
                    it = datosMensajes->getIterator();
                    cout << "Mensajes de la clase:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtMensaje *dvMsj = dynamic_cast<DtMensaje *>(it->getCurrent());
                        cout << dvMsj->getMensaje(); //sobrecargar el cout en DtMensaje
                    }

                    string mensaje;
                    cout << "Ingrese su mensaje: ";
                    getline(cin >> ws, mensaje);
                    int op;
                    cout << "Su mensaje es respuesta? 1- Si 2- No\n";
                    cin >> op;
                    int idMensaje;
                    if (op == 1)
                    {
                        cout << "ID del mensaje al que responde: ";
                        cin >> idMensaje;
                        clases.responderMensaje(idMensaje, mensaje);
                    }
                    else
                    {
                        clases.escribirMensaje(mensaje);
                    }

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.enviarMensaje();
                    }
                    else
                    {
                        clases.cancelarMensaje();
                    }
                    system("clear");
                }
                break;

                case 3:
                {
                    string cedula;
                    cout << "Ingrese su cedula: ";
                    getline(cin >> ws, cedula);
                    IDictionary *datosAsignaturas = clases.listarAsignaturasCursando(cedula);
                    IIterator *it = datosAsignaturas->getIterator();

                    cout << "Listado de sus asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig->getNombreAsignatura(); //sobrecargar el cout en DtAsignatura
                    }

                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
                    IDictionary *datosClases = clases.listarClasesEnVivoHabilitado(codAsig);
                    it = datosClases->getIterator();

                    cout << "Listado de las clases en vivo habilitado a asistir:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls->getNombreClase(); //sobrecargar el cout en DtClase
                    }

                    int nroCls;
                    cout << "Numero de la clase seleccionada: ";
                    cin >> nroCls;
                    DtClase *dvCls = clases.seleccionarClase(nroCls);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.confirmarAsistencia();
                    }
                    else
                    {
                        clases.cancelarAsistencia();
                    }
                    system("clear");
                }
                break;

                case 4:
                {
                    string cedula;
                    cout << "Ingrese su cedula: ";
                    getline(cin >> ws, cedula);
                    IDictionary *datosAsignaturas = clases.listarAsignaturasCursando(cedula);
                    IIterator *it = datosAsignaturas->getIterator();

                    cout << "Listado de sus asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig->getNombreAsignatura(); //sobrecargar el cout en DtAsignatura
                    }

                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
                    IDictionary *datosClases = clases.listarClasesEnDiferido(codAsig);
                    it = datosClases->getIterator();

                    cout << "Listado de clases en diferido:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls->getNombreClase(); //sobrecargar el cout en DtClase
                    }

                    int nroCls;
                    cout << "Numero de la clase seleccionada: ";
                    cin >> nroCls;
                    DtClase *dvCls = clases.seleccionarClase(nroCls);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        IDictionary *datosMensajes = clases.confirmarReproduccion();
                        it = datosMensajes->getIterator();

                        cout << "Mensajes de la clase:\n";
                        for (it; it->hasCurrent(); it->next())
                        {
                            DtMensaje *dvMsj = dynamic_cast<DtMensaje *>(it->getCurrent());
                            cout << dvMsj->getMensaje(); //sobrecargar el cout en DtMensaje
                        }
                    }
                    else
                    {
                        clases.cancelarReproduccion();
                    }
                    system("clear");
                }
                break;

                case 5:
                    break;

                default:
                    break;
                }
            } while (opt != 5);
        }
        break;

        case 4: //listo
        {
            asigUsr.cargarDatosAsigUsr();
            clases.cargarDatosClases();
            cout << "Datos cargados\n";
            pausarConsola();
        }
        break;

        case 5:
            break;

        default:
            break;
        }
    } while (opcion != 5);
}

int menuUsuario()
{
    system("clear");
    while (true)
    {
        string opt;
        int op;
        cout << "             Tipo de usuario:\n"
             << "/////////////////////////////////////////\n"
             << "1- Administrador\n"
             << "2- Docente\n"
             << "3- Estudiante\n"
             << "4- Cargar datos de prueba\n"
             << "5- Salir\n"
             << "/////////////////////////////////////////\n";
        getline(cin, opt);
        op = stringToInt(opt);
        if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5)
        {
            system("clear");
            return op;
        }
        system("clear");
    }

    return -1;
}

int menuAdministrador()
{
    system("clear");
    while (true)
    {
        string opt;
        int op;
        cout << "             Opciones:\n"
             << "/////////////////////////////////////////\n"
             << "1- Alta de usuario\n"
             << "2- Alta de asignatura\n"
             << "3- Asignar docentes a una asignatura\n"
             << "4- Ver tiempo de dictado de clases\n"
             << "5- Eliminar asignatura\n"
             << "6- Consultar fecha y hora\n"
             << "7- Modificar fecha y hora\n"
             << "8- Salir\n"
             << "/////////////////////////////////////////\n";
        getline(cin, opt);
        op = stringToInt(opt);
        if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6 || op == 7 || op == 8)
        {
            system("clear");
            return op;
        }
        system("clear");
    }
    return -1;
}

int menuDocente()
{
    system("clear");
    while (true)
    {
        string opt;
        int op;
        cout << "             Opciones:\n"
             << "/////////////////////////////////////////\n"
             << "1- Iniciar clase\n"
             << "2- Finalizar clase\n"
             << "3- Enviar mensaje\n"
             << "4- Listar clases\n"
             << "5- Ver tiempos de asistencia a clase\n"
             << "6- Salir\n"
             << "/////////////////////////////////////////\n";
        getline(cin, opt);
        op = stringToInt(opt);
        if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6)
        {
            system("clear");
            return op;
        }
        system("clear");
    }
    return -1;
}

int menuEstudiante()
{
    system("clear");
    while (true)
    {
        string opt;
        int op;
        cout << "             Opciones:\n"
             << "/////////////////////////////////////////\n"
             << "1- Inscripcion a asignatura\n"
             << "2- Enviar mensaje\n"
             << "3- Asistir a clase en vivo\n"
             << "4- Reproducir clase en diferido\n"
             << "5- Salir\n"
             << "/////////////////////////////////////////\n";
        getline(cin, opt);
        op = stringToInt(opt);
        if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5)
        {
            system("clear");
            return op;
        }
        system("clear");
    }
    return -1;
}

int menuConfirmacion()
{
    int op;
    string opt;
    while (true)
    {
        cout << "\nSeleccione:\n1- Confirmar\n2- Cancelar\n";
        getline(cin, opt);
        op = stringToInt(opt);
        if (op == 1 || op == 2)
        {
            system("clear");
            return op;
        }
        system("clear");
    }
}

void pausarConsola()
{
    do
    {
        cout << '\n'
             << "Presione enter para continuar...";
    } while (cin.get() != '\n');
}

int stringToInt(string s)
{
    stringstream convertir(s);
    int x;
    convertir >> x;
    return x;
}