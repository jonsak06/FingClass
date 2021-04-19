objetos = main.o Clases/Asignatura.o Clases/Clase.o Clases/Docente.o Clases/Estudiante.o Clases/Monitoreo.o Clases/Practico.o Clases/Sistema.o Clases/Teorico.o Clases/Usuario.o Datatypes/DtFechaHora.o

main: $(objetos)
	g++ $(objetos)

main.o: main.cpp
	g++ -c main.cpp

Asignatura.o: Asignatura.cpp
	g++ -c Asignatura.cpp

Clase.o: Clase.cpp
	g++ -c Clase.cpp

Docente.o: Docente.cpp
	g++ -c Docente.cpp

Estudiante.o: Estudiante.cpp
	g++ -c Estudiante.cpp

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

DtFechaHora.o: DtFechaHora.cpp
	g++ -c DtFechaHora.cpp

clean:
	rm */*.o main.o a.out