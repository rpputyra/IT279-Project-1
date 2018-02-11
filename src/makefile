#
# Assignment 1: Stacks & Queues
# makefile
# Created: 02/11/2018
# Authors: Jonathan Daniel, Rob Putyra, Christopher Runyan
#
CC=g++
CFLAGS=-g -Wall

all: Stack.o
	${CC} ${CFLAGS} -o main Stack.o

Stack.o: Stack.cpp
	${CC} ${CFLAGS} -c Stack.cpp

clean:
	rm *.o
	rm main
