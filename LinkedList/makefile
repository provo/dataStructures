# Makefile for compiling and testing

CC=g++
FLAGS=-c -Wall -std=c++11

all: linkedList

linkedList: main.o linkedList.o
	$(CC) main.o linkedList.o -o linkedList

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

queue.o: queue.cpp queue.hpp
	$(CC) $(FLAGS) queue.cpp queue.hpp

clean:
	rm *.o *.gch
