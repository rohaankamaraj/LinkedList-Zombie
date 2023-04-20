

output: Kamaraj_main.o Kamaraj_LinkedList.o
	g++ Kamaraj_main.o Kamaraj_LinkedList.o -o main

Kamaraj_main.o: Kamaraj_main.cpp
	g++ -c Kamaraj_main.cpp

Kamaraj_LinkedList.o: Kamaraj_LinkedList.cpp Kamaraj_LinkedList.h
	g++ -c Kamaraj_LinkedList.cpp
