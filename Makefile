objetos = main.o Clases/Asignacion.o Clases/Asignatura.o Clases/AsistenciaEnDiferido.o Clases/Clase.o Clases/Docente.o Clases/Estudiante.o \
Clases/Mensaje.o Clases/Monitoreo.o Clases/Practico.o Clases/Teorico.o Clases/Usuario.o Clases/AsistenciaEnVivo \
Datatypes/DtAsignatura.o Datatypes/DtClase.o Datatypes/DtDocente.o Datatypes/DtEstudiante.o Datatypes/FechaHora.o \
Datatypes/DtMensaje.o Datatypes/DtMonitoreo.o Datatypes/DtPractico.o Datatypes/DtTeorico.o Datatypes/DtUsuario.o Otros/ControllerClases.o \
Otros/ControllerAsignaturasUsuarios.o
main: $(objetos)
	g++ $(objetos)

main.o: main.cpp
	g++ -c main.cpp

Asignacion.o: Asignacion.cpp
	g++ -c Asignacion.cpp

Asignatura.o: Asignatura.cpp
	g++ -c Asignatura.cpp

AsistenciaEnDiferido.o: AsistenciaEnDiferido.cpp
	g++ -c AsistenciaEnDiferido.cpp

AsistenciaEnVivo.o: AsistenciaEnVivo.cpp
	g++ -c AsistenciaEnVivo.cpp

Clase.o: Clase.cpp
	g++ -c Clase.cpp

Docente.o: Docente.cpp
	g++ -c Docente.cpp

Estudiante.o: Estudiante.cpp
	g++ -c Estudiante.cpp

Mensaje.o: Mensaje.cpp
	g++ -c Mensaje.cpp

Monitoreo.o: Monitoreo.cpp
	g++ -c Monitoreo.cpp

Practico.o: Practico.cpp
	g++ -c Practico.cpp

Teorico.o: Teorico.cpp
	g++ -c Teorico.cpp

Usuario.o: Usuario.cpp
	g++ -c Usuario.cpp

DtAsignatura.o: DtAsignatura.cpp
	g++ -c DtAsignatura.cpp

DtClase.o: DtClase.cpp
	g++ -c DtClase.cpp

DtDocente.o: DtDocente.cpp
	g++ -c DtDocente.cpp

DtEstudiante.o: DtEstudiante.cpp
	g++ -c DtEstudiante.cpp

FechaHora.o: FechaHora.cpp
	g++ -c FechaHora.cpp

DtMensaje.o: DtMensaje.cpp
	g++ -c DtMensaje.cpp

DtMonitoreo.o: DtMonitoreo.cpp
	g++ -c DtMonitoreo.cpp

DtPractico.o: DtPractico.cpp
	g++ -c DtPractico.cpp

DtTeorico.o: DtTeorico.cpp
	g++ -c DtTeorico.cpp

DtUsuario.o: DtUsuario.cpp
	g++ -c DtUsuario.cpp

ControllerClases.o: ControllerClases.cpp
	g++ -c ControllerClases.cpp

ControllerAsignaturasUsuarios.o: ControllerAsignaturasUsuarios.cpp
	g++ -c ControllerAsignaturasUsuarios.cpp

clean:
	rm */*.o main.o a.out