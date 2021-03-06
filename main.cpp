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
string seleccionEstudiante();
string seleccionDocente();

using namespace std;

int main()
{
    Factory &fabrica = Factory::getInstance();
    IClases &clases = fabrica.getCtrlClases();
    IAsignaturasUsuarios &asigUsr = fabrica.getCtrlAsigUsr();
    Reloj &reloj = Reloj::getInstance();
    int opcion;
    int limite = 0;
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
                case 1:
                {
                    string opc;
                    int op;
                    string nombre, email, contrasenia, urlImgPerfil, nombreInstituto, cedula;
                    while (true)
                    {
                        cout << "Tipo de usuario a agregar:\n1- Docente\n2- Estudiante\n\n";
                        getline(cin, opc);
                        op = stringToInt(opc);
                        if (op == 1 || op == 2)
                        {
                            break;
                        }
                        system("clear");
                    }
                    system("clear");

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
                        cout << "Usuario agregado\n";
                        pausarConsola();
                    }
                    else
                    {
                        asigUsr.cancelarAltaUsuario();
                    }
                }
                break;

                case 2:
                {
                    string nombreAsignatura, codigoAsignatura;
                    bool teorico, practico, monitoreo;
                    string opc;
                    int op;
                    cout << "Ingrese el codigo de la asignatura: ";
                    getline(cin >> ws, codigoAsignatura);
                    cout << "Ingrese el nombre de la asignatura: ";
                    getline(cin >> ws, nombreAsignatura);

                    cout << "\nTiene teorico?\n1- Si\n2- No\n\n";
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

                    cout << "\nTiene practico?\n1- Si\n2- No\n\n";
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

                    cout << "\nTiene monitoreo?\n1- Si\n2- No\n\n";
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
                        cout << "Asignatura agregada\n";
                        pausarConsola();
                    }
                    else
                    {
                        asigUsr.cancelarAltaAsignatura();
                    }
                }
                break;

                case 3:
                {
                    IDictionary *datosAsignaturas = asigUsr.listarAsignaturas();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No existen asignaturas en el sistema\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
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
                    bool seguirAsignando = true;
                    bool existeDocente;
                    IDictionary *datosDocentes = asigUsr.listarDocentesSinAsignar(codAsig);

                    do
                    {
                        system("clear");
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

                            cout << "\nSeleccione el rol de dictado del docente:\n1- Teorico\n2- Practico\n3- Monitoreo\n\n";
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
                            cout << "Docente asignado\n";
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

                        cout << "\nDesea seguir asignando docentes? 1- Si 2- No\n\n";
                        getline(cin, opc);
                        o = stringToInt(opc);
                        if (o == 2)
                        {
                            seguirAsignando = false;
                            asigUsr.dejarDeAsignarDocentes();
                        }
                    } while (seguirAsignando);
                    if (!datosDocentes->isEmpty())
                    {
                        delete datosDocentes;
                    }
                }
                break;

                case 4:
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturas();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No existen asignaturas en el sistema\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "Tiempo de dictado de clases por asignatura:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << endl
                             << "Nombre: " << dvAsig->getNombreAsignatura() << endl;
                        cout << "Tiempo de dictado: " << dvAsig->getTiempoTotalDictado() << " horas" << endl;
                    }
                    delete datosAsignaturas;
                    pausarConsola();
                }
                break;

                case 5:
                {
                    IDictionary *datosAsignaturas = asigUsr.listarAsignaturas();

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No existen asignaturas en el sistema\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
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
                        delete k;
                        if (!existeAsignatura)
                        {
                            cout << "\nLa asignatura no existe\n";
                        }
                    } while (!existeAsignatura);
                    delete datosAsignaturas;

                    asigUsr.seleccionarAsignatura(codAsig);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarEliminacion();
                        cout << "Asignatura eliminada\n";
                        pausarConsola();
                    }
                    else
                    {
                        asigUsr.cancelarEliminacion();
                    }
                }
                break;

                case 6:
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

                case 7:
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
                    system("clear");
                    cout << "Fecha y hora registrada\n";
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
            string email;
            IDictionary *docentes = asigUsr.listarDocentes();
            if (docentes->isEmpty())
            {
                cout << "No existen docentes en el sistema\n";
                pausarConsola();
                break;
            }
            
            IIterator *it = docentes->getIterator();
            cout << "Lista de docentes en el sistema\n";
            DtDocente *dvDoc;
            for (it; it->hasCurrent(); it->next())
            {
                dvDoc = dynamic_cast<DtDocente *>(it->getCurrent());
                cout << dvDoc;
            }
            delete it, docentes;
            email = seleccionDocente();
            int opt;
            do
            {
                opt = menuDocente();
                switch (opt)
                {
                case 1:
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturasAsignadas(email);

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "No tiene asignaturas asignadas\n";
                        pausarConsola();
                        break;
                    }
                    IIterator *it = datosAsignaturas->getIterator();
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
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
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
                    cout << "\nHora: ";
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
                            break;
                        }

                        string cedula;
                        bool seguirHabilitando = true;
                        bool existeEstudiante;
                        int i = 0;
                        while (seguirHabilitando && i < 15 && !datosEstudiantes->isEmpty())
                        {
                            system("clear");
                            it = datosEstudiantes->getIterator();

                            cout << "Listado de estudiantes inscriptos a la asignatura:\n";
                            for (it; it->hasCurrent(); it->next())
                            {
                                cout << dynamic_cast<DtEstudiante *>(it->getCurrent());
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
                                if (datosEstudiantes->isEmpty())
                                {
                                    cout << "\nNo quedan estudiantes para habilitar\n";
                                    pausarConsola();
                                    break;
                                }
                            }
                            else
                            {
                                cout << "\nEl estudiante no existe o no cursa la asignatura\n";
                                pausarConsola();
                                system("clear");
                                delete k;
                                continue;
                            }
                            i++;
                            if (i < 15 && !datosEstudiantes->isEmpty())
                            {
                                int op;
                                cout << "\nDesea seguir habilitando estudiantes? 1- Si 2- No\n";
                                getline(cin, num);
                                op = stringToInt(num);
                                if (op == 2)
                                {
                                    seguirHabilitando = false;
                                }
                            }
                        }
                        if (!datosEstudiantes->isEmpty())
                        {
                            delete datosEstudiantes;
                        }
                    }
                    system("clear");
                    cout << "\nInformacion de la clase:\n";
                    DtClase *dvCls = clases.obtenerInfoClase();
                    FechaHora *fh = new FechaHora(dvCls->getFechaHoraComienzo());
                    cout << "\nNumero: " << dvCls->getNumeroClase() << endl;
                    cout << "Nombre: " << dvCls->getNombreClase() << endl;
                    cout << "Fecha y hora de comienzo: " << fh << endl;
                    delete fh;

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

                case 2:
                {
                    IDictionary *datosClases = clases.listarClasesEnVivo(email);

                    if (datosClases->isEmpty())
                    {
                        cout << "No tiene clases en vivo\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosClases->getIterator();
                    cout << "Listado de sus clases en vivo:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls;
                    }

                    int nroCls;
                    string num;
                    bool existeClase;
                    IKey *k;
                    do
                    {
                        cout << "Numero de la clase seleccionada: ";
                        getline(cin, num);
                        nroCls = stringToInt(num);
                        k = new Integer(nroCls);
                        existeClase = datosClases->find(k) != NULL;
                        delete k;
                        if (!existeClase)
                        {
                            cout << "\nLa clase no existe en su lista\n\n";
                        }

                    } while (!existeClase);
                    delete datosClases;
                    DtClase *dvCls = clases.seleccionarClaseDocente(nroCls);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.confirmarFinalizacionClase();
                        cout << "Clase finalizada\n";
                        pausarConsola();
                    }
                    else
                    {
                        clases.cancelarFinalizacionClase();
                    }
                }
                break;

                case 3:
                {
                    IDictionary *datosClases = clases.listarClasesEnVivoParticipando(email);

                    if (datosClases->isEmpty())
                    {
                        cout << "\nNo tiene clases en vivo\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosClases->getIterator();
                    cout << "Listado de sus clases en vivo:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << "\nNumero: " << dvCls->getNumeroClase() << endl;
                        cout << "Nombre: " << dvCls->getNombreClase() << endl
                             << endl;
                    }
                    delete it;

                    int nroCls;
                    string num;
                    bool existeClase;
                    IKey *k;
                    do
                    {
                        cout << "Numero de la clase seleccionada: ";
                        getline(cin, num);
                        nroCls = stringToInt(num);
                        k = new Integer(nroCls);
                        existeClase = datosClases->find(k) != NULL;
                        delete k;
                        if (!existeClase)
                        {
                            cout << "\nLa clase no existe en su lista\n";
                        }
                    } while (!existeClase);
                    delete datosClases;
                    system("clear");

                    IDictionary *datosMensajes = clases.listarMensajes(nroCls);
                    it = datosMensajes->getIterator();
                    if (!datosMensajes->isEmpty())
                    {
                        cout << "Mensajes de la clase:\n";
                        for (it; it->hasCurrent(); it->next())
                        {
                            DtMensaje *dvMsj = dynamic_cast<DtMensaje *>(it->getCurrent());
                            cout << dvMsj;
                        }
                    }

                    string mensaje;
                    int op;
                    int idMensaje;
                    cout << "\nIngrese su mensaje: ";
                    getline(cin >> ws, mensaje);
                    cout << "\nEs respuesta? 1- Si 2- No\n";
                    getline(cin, num);
                    op = stringToInt(num);
                    if (op == 1)
                    {
                        bool existeMensaje;
                        do
                        {
                            cout << "\nID del mensaje al que responde: ";
                            getline(cin, num);
                            idMensaje = stringToInt(num);
                            k = new Integer(idMensaje);
                            existeMensaje = datosMensajes->find(k) != NULL;
                            if (!existeMensaje)
                            {
                                cout << "\nEl mensaje no existe\n";
                            }
                        } while (!existeMensaje);
                        clases.responderMensaje(idMensaje, mensaje);
                    }
                    else
                    {
                        clases.escribirMensaje(mensaje);
                    }
                    if (!datosMensajes->isEmpty())
                    {
                        delete datosMensajes;
                    }

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.enviarMensaje();
                        cout << "Mensaje enviado\n";
                        pausarConsola();
                    }
                    else
                    {
                        clases.cancelarMensaje();
                    }
                }
                break;

                case 4:
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturasAsignadas(email);
                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "\nNo tiene asignaturas asignadas\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "\nListado de sus asignaturas:\n";
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
                            cout << "\nLa asignatura no existe o no esta asignado\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
                    system("clear");

                    IDictionary *datosClases = clases.listarClases(codAsig);
                    if (datosClases->isEmpty())
                    {
                        cout << "La asignatura no tiene clases\n";
                        pausarConsola();
                        break;
                    }

                    it = datosClases->getIterator();
                    DtClase *dvCls;
                    cout << "Listado de sus clases:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls;
                    }
                    pausarConsola();
                }
                break;

                case 5:
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturasAsignadas(email);
                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "\nNo tiene asignaturas asignadas\n";
                        pausarConsola();
                        break;
                    }
                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "Listado de sus asignaturas:\n";
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
                            cout << "\nLa asignatura no existe o no esta asignado\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
                    system("clear");

                    IDictionary *datosClases = clases.listarClases(codAsig);
                    if (datosClases->isEmpty())
                    {
                        cout << "\nLa asignatura no tiene clases\n";
                        pausarConsola();
                        break;
                    }

                    it = datosClases->getIterator();
                    cout << "Listado de sus clases con el promedio de asistencia:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << endl
                             << "Numero: " << dvCls->getNumeroClase() << endl;
                        cout << "Nombre: " << dvCls->getNombreClase() << endl;
                        cout << "Promedio: " << dvCls->getPromedioTiempoAsistencia() << " minutos" << endl;
                    }
                    delete datosClases;
                    pausarConsola();
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
            string cedula;
            IDictionary *estudiantes = asigUsr.listarEstudiantes();
            if (estudiantes->isEmpty())
            {
                cout << "No existen estudiantes en el sistema\n";
                pausarConsola();
                break;
            }
            
            IIterator *it = estudiantes->getIterator();
            cout << "Lista de estudiantes en el sistema\n";
            DtEstudiante *dvEst;
            for (it; it->hasCurrent(); it->next())
            {
                dvEst = dynamic_cast<DtEstudiante *>(it->getCurrent());
                cout << dvEst;
            }
            delete it, estudiantes;
            cedula = seleccionEstudiante();
            
            int opt;
            do
            {
                opt = menuEstudiante();
                switch (opt)
                {
                case 1:
                {
                    IDictionary *datosAsignaturas = asigUsr.listarAsignaturasNoInscripto(cedula);

                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "\nNo existen asignaturas a las que no este inscripto\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "\nListado de asignaturas a las que no esta inscripto:\n";
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
                            cout << "\nLa asignatura no existe o ya esta inscripto\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
                    asigUsr.seleccionarAsignatura(codAsig);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarInscripcion();
                        cout << "Inscripcion realizada\n";
                        pausarConsola();
                    }
                    else
                    {
                        asigUsr.cancelarInscripcion();
                    }
                }
                break;

                case 2:
                {
                    IDictionary *datosClases = clases.listarClasesEnVivoParticipando(cedula);

                    if (datosClases->isEmpty())
                    {
                        cout << "\nNo tiene clases en vivo\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosClases->getIterator();
                    cout << "Listado de sus clases en vivo:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << "\nNumero: " << dvCls->getNumeroClase() << endl;
                        cout << "Nombre: " << dvCls->getNombreClase() << endl
                             << endl;
                    }
                    delete it;

                    int nroCls;
                    string num;
                    bool existeClase;
                    IKey *k;
                    do
                    {
                        cout << "Numero de la clase seleccionada: ";
                        getline(cin, num);
                        nroCls = stringToInt(num);
                        k = new Integer(nroCls);
                        existeClase = datosClases->find(k) != NULL;
                        delete k;
                        if (!existeClase)
                        {
                            cout << "\nLa clase no existe en su lista\n";
                        }
                    } while (!existeClase);
                    delete datosClases;
                    system("clear");

                    IDictionary *datosMensajes = clases.listarMensajes(nroCls);
                    it = datosMensajes->getIterator();
                    if (!datosMensajes->isEmpty())
                    {
                        cout << "Mensajes de la clase:\n";
                        for (it; it->hasCurrent(); it->next())
                        {
                            DtMensaje *dvMsj = dynamic_cast<DtMensaje *>(it->getCurrent());
                            cout << dvMsj;
                        }
                    }

                    string mensaje;
                    int op;
                    int idMensaje;
                    cout << "\nIngrese su mensaje: ";
                    getline(cin >> ws, mensaje);
                    cout << "\nEs respuesta? 1- Si 2- No\n";
                    getline(cin, num);
                    op = stringToInt(num);

                    if (op == 1)
                    {
                        bool existeMensaje;
                        do
                        {
                            cout << "\nID del mensaje al que responde: ";
                            getline(cin, num);
                            idMensaje = stringToInt(num);
                            k = new Integer(idMensaje);
                            existeMensaje = datosMensajes->find(k) != NULL;
                            if (!existeMensaje)
                            {
                                cout << "\nEl mensaje no existe\n";
                            }
                        } while (!existeMensaje);
                        clases.responderMensaje(idMensaje, mensaje);
                    }
                    else
                    {
                        clases.escribirMensaje(mensaje);
                    }
                    if (!datosMensajes->isEmpty())
                    {
                        delete datosMensajes;
                    }

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.enviarMensaje();
                        cout << "Mensaje enviado\n";
                        pausarConsola();
                    }
                    else
                    {
                        clases.cancelarMensaje();
                    }
                }
                break;

                case 3:
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturasCursando(cedula);
                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "\nNo esta inscripto a ninguna asignatura\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "Listado de sus asignaturas:\n";
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
                            cout << "\nLa asignatura no existe o no esta inscripto\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
                    system("clear");

                    IDictionary *datosClases = clases.listarClasesEnVivoHabilitado(codAsig);
                    if (datosClases->isEmpty())
                    {
                        cout << "La asignatura no tiene clases\n";
                        pausarConsola();
                        break;
                    }

                    it = datosClases->getIterator();
                    cout << "Listado de las clases en vivo habilitado a asistir:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        FechaHora *fh = new FechaHora(dvCls->getFechaHoraComienzo());
                        cout << "\nNumero: " << dvCls->getNumeroClase() << endl;
                        cout << "Nombre: " << dvCls->getNombreClase() << endl;
                        cout << "Fecha y hora de comienzo: " << fh << endl;
                        delete fh;
                    }
                    delete it;

                    int nroCls;
                    string num;
                    bool existeClase;
                    do
                    {
                        cout << "Numero de la clase seleccionada: ";
                        getline(cin, num);
                        nroCls = stringToInt(num);
                        k = new Integer(nroCls);
                        existeClase = datosClases->find(k) != NULL;
                        delete k;
                        if (!existeClase)
                        {
                            cout << "\nLa clase no existe en su lista\n\n";
                        }

                    } while (!existeClase);
                    delete datosClases;
                    DtClase *dvCls = clases.seleccionarClase(nroCls);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        clases.confirmarAsistencia();
                        cout << "Clase iniciada\n";
                        pausarConsola();
                    }
                    else
                    {
                        clases.cancelarAsistencia();
                    }
                }
                break;

                case 4:
                {
                    IDictionary *datosAsignaturas = clases.listarAsignaturasCursando(cedula);
                    if (datosAsignaturas->isEmpty())
                    {
                        cout << "\nNo esta inscripto a ninguna asignatura\n";
                        pausarConsola();
                        break;
                    }

                    IIterator *it = datosAsignaturas->getIterator();
                    cout << "Listado de sus asignaturas:\n";
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
                            cout << "\nLa asignatura no existe o no esta inscripto\n";
                        }
                        delete k;
                    } while (!existeAsignatura);
                    delete datosAsignaturas;
                    system("clear");

                    IDictionary *datosClases = clases.listarClasesEnDiferido(codAsig);
                    if (datosClases->isEmpty())
                    {
                        cout << "La asignatura no tiene clases en diferido\n";
                        pausarConsola();
                        break;
                    }

                    it = datosClases->getIterator();
                    cout << "Listado de clases en diferido:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtClase *dvCls = dynamic_cast<DtClase *>(it->getCurrent());
                        cout << dvCls;
                    }
                    delete it;

                    int nroCls;
                    string num;
                    bool existeClase;
                    do
                    {
                        cout << "Numero de la clase seleccionada: ";
                        getline(cin, num);
                        nroCls = stringToInt(num);
                        k = new Integer(nroCls);
                        existeClase = datosClases->find(k) != NULL;
                        delete k;
                        if (!existeClase)
                        {
                            cout << "\nLa clase no existe en su lista\n\n";
                        }

                    } while (!existeClase);
                    delete datosClases;
                    DtClase *dvCls = clases.seleccionarClase(nroCls);

                    int op = menuConfirmacion();
                    if (op == 1)
                    {
                        cout << "\nReproduccion iniciada\n";
                        pausarConsola();
                        system("clear");
                        IDictionary *datosMensajes = clases.confirmarReproduccion();
                        if (!datosMensajes->isEmpty())
                        {
                            it = datosMensajes->getIterator();
                            cout << "Mensajes de la clase:\n";
                            DtMensaje *dvMsj;
                            for (it; it->hasCurrent(); it->next())
                            {
                                dvMsj = dynamic_cast<DtMensaje *>(it->getCurrent());
                                cout << dvMsj;
                            }
                            delete it, datosMensajes;
                            pausarConsola();
                        }
                    }
                    else
                    {
                        clases.cancelarReproduccion();
                    }
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

        case 4:
        {
            if (limite < 1)
            {
                asigUsr.cargarDatosAsigUsr();
                clases.cargarDatosClases();
                limite++;
                cout << "Datos cargados\n";
                pausarConsola();
            }
            else
            {
                cout << "Los datos ya fueron cargados\n";
                pausarConsola();
            }
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
        cout << "\nSeleccione:\n1- Confirmar\n2- Cancelar\n\n";
        getline(cin, opt);
        op = stringToInt(opt);
        if (op == 1 || op == 2)
        {
            system("clear");
            return op;
        }
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

string seleccionEstudiante()
{
    Factory &fabrica = Factory::getInstance();
    IAsignaturasUsuarios &asigUsr = fabrica.getCtrlAsigUsr();
    string opt, pas;
    do
    {
        cout << "Inicie sesion seleccionando una cedula de la lista: ";
        getline(cin, opt);

    } while (!asigUsr.existeUsuario(opt));
    do
    {
        cout << "Password: ";
        getline(cin, pas);

    } while (!asigUsr.confirmarPassword(opt, pas));
    return opt;
}

string seleccionDocente()
{
    Factory &fabrica = Factory::getInstance();
    IAsignaturasUsuarios &asigUsr = fabrica.getCtrlAsigUsr();
    string opt, pas;
    do
    {
        cout << "Inicie sesion seleccionando un email de la lista: ";
        getline(cin, opt);

    } while (!asigUsr.existeUsuario(opt));
    do
    {
        cout << "Password: ";
        getline(cin, pas);

    } while (!asigUsr.confirmarPassword(opt, pas));
    return opt;
}