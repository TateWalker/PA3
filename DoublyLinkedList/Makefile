all: run-dll

run-dll: TemplateDoublyLinkedList.o Main.o
	g++ -std=c++11 TemplateDoublyLinkedList.o Main.o -v -o run-dll

DoublyLinkedList.o: TemplateDoublyLinkedList.cpp TemplateDoublyLinkedList.h
	g++ -std=c++11  TemplateDoublyLinkedList.cpp

Main.o: Main.cpp TemplateDoublyLinkedList.h
	g++ -std=c++11  -v Main.cpp

clean:
	rm -f *.o run-dll
