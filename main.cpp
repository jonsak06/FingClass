#include "Otros/Factory.h"
#include "Datatypes/DtAsignatura.h"
#include "Otros/Reloj.h"
#include <iostream>

int menuUsuario();
int menuAdministrador();
int menuDocente();
int menuEstudiante();
int menuConfirmacion();

int main()
{
    Factory &fabrica = Factory::getInstance();
    IClases &clases = fabrica.getCtrlClases();
    IAsignaturasUsuarios &asigUsr = fabrica.getCtrlAsigUsr();
    Reloj& reloj = Reloj::getInstance();
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
                case 1:
                {
                    int op;
                    string nombre, email, contrasenia, urlImgPerfil, nombreInstituto, cedula;
                    while (true)
                    {
                        cout << "Tipo de usuario a agregar:\n1- Docente\n2- Estudiante\n";
                        cin >> op;
                        if (op == 1 || op == 2)
                        {
                            break;
                        }
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
                        asigUsr.agregarDocente(nombre, email, contrasenia, urlImgPerfil, cedula);
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

                case 2:
                {
                    string nombreAsignatura, codigoAsignatura;
                    bool teorico, practico, monitoreo;
                    int op;
                    cout << "Ingrese el nombre de la asignatura: ";
                    getline(cin >> ws, nombreAsignatura);
                    cout << "Ingrese el codigo de la asignatura: ";
                    getline(cin >> ws, codigoAsignatura);

                    cout << "Tiene teorico?\n1- Si\n2- No\n";
                    cin >> op;
                    if (op == 1)
                    {
                        teorico = true;
                    }
                    else
                    {
                        teorico = false;
                    }

                    cout << "Tiene practico?\n1- Si\n2- No\n";
                    cin >> op;
                    if (op == 1)
                    {
                        practico = true;
                    }
                    else
                    {
                        practico = false;
                    }

                    cout << "Tiene monitoreo?\n1- Si\n2- No\n";
                    cin >> op;
                    if (op == 1)
                    {
                        monitoreo = true;
                    }
                    else
                    {
                        monitoreo = false;
                    }
                    // agregarAsignatura devuelve un DtAsignatura, sobrecargar el cout para mostrar la info
                    asigUsr.agregarAsignatura(nombreAsignatura, codigoAsignatura, teorico, practico, monitoreo);

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

                case 3:
                {
                    ICollection *datosAsignatura = asigUsr.listarAsignaturas();
                    IIterator *it = datosAsignatura->getIterator();

                    cout << "Datos de asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig->getNombreAsignatura(); //sobrecargar el cout en DtAsignatura
                    }

                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
                    ICollection *datosDocentes = asigUsr.listarDocentesSinAsignar(codAsig);
                    it = datosDocentes->getIterator();

                    cout << "Docentes sin asignar a la asignatura seleccionada:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtDocente *dvDoc = dynamic_cast<DtDocente *>(it->getCurrent());
                        cout << dvDoc->getNombre(); //sobrecargar el cout en DtDocente
                    }

                    string email;
                    int op;
                    cout << "Email del docente seleccionado: ";
                    getline(cin >> ws, email);
                    cout << "Seleccione el rol de dictado del docente:\n1- Teorico\n2- Practico\n3- Monitoreo\n";
                    cin >> op;
                    TipoClase rolDictado;
                    if (op == 1)
                    {
                        rolDictado = teroico;
                    }
                    else if (op == 2)
                    {
                        rolDictado = practico;
                    }
                    else
                    {
                        rolDictado = monitoreo;
                    }
                    asigUsr.seleccionarDocente(email, rolDictado);

                    op = menuConfirmacion();
                    if (op == 1)
                    {
                        asigUsr.confirmarAsignacion();
                    }
                    else
                    {
                        asigUsr.cancelarAsignacion();
                    }
                }
                break;

                case 4:
                {
                    ICollection* datosAsignaturas = clases.listarAsignaturas();
                    IIterator* it = datosAsignaturas->getIterator();

                    cout << "Tiempo de dictado de clases por asignatura:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig->getNombreAsignatura(); //sobrecargar el cout en DtAsignatura
                    }
                    //falta pausar la consola
                    system("clear");
                }
                break;

                case 5:
                {
                    ICollection* datosAsignaturas = asigUsr.listarAsignaturas();
                    IIterator* it = datosAsignaturas->getIterator();

                    cout << "Listado de asignaturas:\n";
                    for (it; it->hasCurrent(); it->next())
                    {
                        DtAsignatura *dvAsig = dynamic_cast<DtAsignatura *>(it->getCurrent());
                        cout << dvAsig->getNombreAsignatura(); //sobrecargar el cout en DtAsignatura
                    }
                    
                    string codAsig;
                    cout << "Codigo de la asignatura seleccionada: ";
                    getline(cin >> ws, codAsig);
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
                }
                break;

                case 6:
                {
                    cout << "Fecha y hora del sistema:\n";
                    cout << reloj.getFechaHoraActual().getDia(); //sobrecargar el cout en FechaHora
                }
                break;

                case 7:
                {
                    int dia, mes, anio, hora, min, seg;
                    cout << "Ingrese la fecha:\n";
                    cout << "Dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Anio: ";
                    cin >> anio;
                    system("clear");
                    cout << "Ingrese la hora:\n";
                    cout << "Hora: ";
                    cin >> hora;
                    cout << "Minuto: ";
                    cin >> min;
                    cout << "Segundo: ";
                    cin >> seg;
                    reloj.setFechaHoraActual(FechaHora(dia, mes, anio, hora, min, seg));
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
            int op;
            do
            {
                op = menuDocente();
            } while (op != 6);
        }
        break;

        case 3:
        {
            int op;
            do
            {
                op = menuEstudiante();
            } while (op != 5);
        }
        break;

        case 4:
        {
            clases.cargarDatosClases();
            asigUsr.cargarDatosAsigUsr();
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
    while (true)
    {
        int op;
        cout << "\n             Tipo de usuario:\n"
             << "/////////////////////////////////////////\n"
             << "1- Administrador\n"
             << "2- Docente\n"
             << "3- Estudiante\n"
             << "4- Cargar datos de prueba\n"
             << "5- Salir\n"
             << "/////////////////////////////////////////\n";
        cin >> op;
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
    while (true)
    {
        int op;
        cout << "\n             Opciones:\n"
             << "/////////////////////////////////////////\n"
             << "1- Alta de usuario\n"
             << "2- Alta de asignatura\n"
             << "3- Asignar docente a una asignatura\n"
             << "4- Ver tiempo de dictado de clases\n"
             << "5- Eliminar asignatura\n"
             << "6- Consultar fecha y hora\n"
             << "7- Modificar fecha y hora\n"
             << "8- Salir\n"
             << "/////////////////////////////////////////\n";
        cin >> op;
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
    while (true)
    {
        int op;
        cout << "\n             Opciones:\n"
             << "/////////////////////////////////////////\n"
             << "1- Iniciar clase\n"
             << "2- Finalizar clase\n"
             << "3- Enviar mensaje\n"
             << "4- Listar clases\n"
             << "5- Ver tiempos de asistencia a clase\n"
             << "6- Salir\n"
             << "/////////////////////////////////////////\n";
        cin >> op;
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
    while (true)
    {
        int op;
        cout << "\n             Opciones:\n"
             << "/////////////////////////////////////////\n"
             << "1- Inscripcion a asignatura\n"
             << "2- Enviar mensaje\n"
             << "3- Asistir a clase en vivo\n"
             << "4- Reproducir clase en diferido\n"
             << "5- Salir\n"
             << "/////////////////////////////////////////\n";
        cin >> op;
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
    while (true)
    {
        cout << "Seleccionar:\n1- Confirmar\n2- Cancelar\n";
        cin >> op;
        if (op == 1 || op == 2)
        {
            system("clear");
            return op;
        }
        system("clear");
    }
}
