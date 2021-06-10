objetos = main.o Clases/Asignacion.o Clases/Asignatura.o Clases/AsistenciaEnDiferido.o Clases/Clase.o Clases/Docente.o Clases/Estudiante.o \
Clases/Mensaje.o Clases/Monitoreo.o Clases/Practico.o Clases/Teorico.o Clases/Usuario.o Clases/AsistenciaEnVivo.o \
Datatypes/DtAsignatura.o Datatypes/DtClase.o Datatypes/DtDocente.o Datatypes/DtEstudiante.o Datatypes/FechaHora.o \
Datatypes/DtMensaje.o Datatypes/DtMonitoreo.o Datatypes/DtPractico.o Datatypes/DtTeorico.o Datatypes/DtUsuario.o Otros/ControllerClases.o \
Otros/ControllerAsignaturasUsuarios.o Otros/Factory.o ICollection/Integer.o ICollection/String.o ICollection/collections/List.o \
ICollection/collections/ListIterator.o ICollection/collections/ListNode.o ICollection/collections/OrderedDictionary.o \
ICollection/collections/OrderedDictionaryEntry.o ICollection/interfaces/ICollectible.o ICollection/interfaces/ICollection.o \
ICollection/interfaces/IDictionary.o ICollection/interfaces/IIterator.o ICollection/interfaces/IKey.o ICollection/interfaces/OrderedKey.o

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

Factory.o: Factory.cpp
	g++ -c Factory.cpp

Integer.o: Integer.cpp
	g++ -c Integer.cpp

String.o: String.cpp
	g++ -c String.cpp

List.o: List.cpp
	g++ -c List.cpp

ListIterator.o: ListIterator.cpp
	g++ -c ListIterator.cpp

ListNode.o: ListNode.cpp
	g++ -c ListNode.cpp

OrderedDictionary.o: OrderedDictionary.cpp
	g++ -c OrderedDictionary.cpp

OrderedDictionaryEntry.o: OrderedDictionaryEntry.cpp
	g++ -c OrderedDictionaryEntry.cpp

ICollectible.o: ICollectible.cpp
	g++ -c ICollectible.cpp

ICollection.o: ICollection.cpp
	g++ -c ICollection.cpp

IDictionary.o: IDictionary.cpp
	g++ -c IDictionary.cpp

IIterator.o: IIterator.cpp
	g++ -c IIterator.cpp

IKey.o: IKey.cpp
	g++ -c IKey.cpp

OrderedKey.o: OrderedKey.cpp
	g++ -c OrderedKey.cpp

clean:
	rm */*.o */*/*.o main.o a.out