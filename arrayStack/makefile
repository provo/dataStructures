# Simple makefile for compiling test code

CC=g++
FLAGS=-c -Wall

all: arrayStack

arrayStack: main.o arrayStack.o
	$(CC) main.o arrayStack.o -o arrayStack

main.o: main.cpp
	$(CC) $(FLAGS)  main.cpp

arrayStack.o: arrayStack.cpp
	$(CC) $(FLAGS)  arrayStack.cpp arrayStack.hpp

clean:
	rm *.o *.gch 
