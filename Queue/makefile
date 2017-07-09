# Makefile for compiling and testing queue class

CC = g++
FLAGS = -c -Wall -std=c++11

all: queue

queue: main.o queue.o
	$(CC) main.o queue.o -o queue

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

queue.o: queue.cpp
	$(CC) $(FLAGS) queue.cpp queue.hpp

clean:
	rm *.o *.gch
