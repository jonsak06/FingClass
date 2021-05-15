objetos = main.o Clases/Asignacion.o Clases/Asignatura.o Clases/Asistencia.o Clases/Clase.o Clases/Docente.o Clases/Estudiante.o \
Clases/Mensaje.o Clases/Monitoreo.o Clases/Practico.o Clases/Sistema.o Clases/Teorico.o Clases/Usuario.o Colecciones/ColFechaHora.o \
Datatypes/DtAsignatura.o Datatypes/DtClase.o Datatypes/DtDocente.o Datatypes/DtEstudiante.o Datatypes/DtFechaHora.o \
Datatypes/DtMensaje.o Datatypes/DtMonitoreo.o Datatypes/DtPractico.o Datatypes/DtTeorico.o Datatypes/DtUsuario.o 

main: $(objetos)
	g++ $(objetos)

main.o: main.cpp
	g++ -c main.cpp

Asignacion.o: Asignacion.cpp
	g++ -c Asignacion.cpp

Asignatura.o: Asignatura.cpp
	g++ -c Asignatura.cpp

Asistencia.o: Asistencia.cpp
	g++ -c Asistencia.cpp

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

Sistema.o: Sistema.cpp
	g++ -c Sistema.cpp

Teorico.o: Teorico.cpp
	g++ -c Teorico.cpp

Usuario.o: Usuario.cpp
	g++ -c Usuario.cpp

ColFechaHora.o: ColFechaHora.cpp
	g++ -c ColFechaHora.cpp

DtAsignatura.o: DtAsignatura.cpp
	g++ -c DtAsignatura.cpp

DtClase.o: DtClase.cpp
	g++ -c DtClase.cpp

DtDocente.o: DtDocente.cpp
	g++ -c DtDocente.cpp

DtEstudiante.o: DtEstudiante.cpp
	g++ -c DtEstudiante.cpp

DtFechaHora.o: DtFechaHora.cpp
	g++ -c DtFechaHora.cpp

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

clean:
	rm */*.o main.o a.out