all: run-main

run-main: Parser.o Evaluator.o Main.o token.o
	c++ -o run-main Parser.o Evaluator.o Main.o token.o

Main.o: Parser.h Evaluator.h RuntimeException.h token.h
	c++ -std=c++11 -c -g Main.cpp

Evaluator.o: Evaluator.h Parser.h LinkedStack.h LinkedQueue.h TemplateDoublyLinkedList.h RuntimeException.h token.h
	c++ -std=c++11 -c -g Evaluator.cpp

Parser.o: Parser.h LinkedStack.h LinkedQueue.h TemplateDoublyLinkedList.h RuntimeException.h token.h
	c++ -std=c++11 -c -g Parser.cpp

Token.o: token.h
	c++ -std=c++11 -c -g token.cpp
clean:
	rm -f *.o run-main
