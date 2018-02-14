#
# Assignment 1: Stacks & Queues
# makefile
# Created: 02/11/2018
# Authors: Jonathan Daniel, Rob Putyra, Christopher Runyan
#
CC=g++
CFLAGS=-g -Wall

all: QueueTest.o Queue.o
	${CC} ${CFLAGS} -o main QueueTest.o Queue.o

QueueTest.o: QueueTest.cpp
	${CC} ${CFLAGS} -c QueueTest.cpp

Queue.o: Queue.cpp
	${CC} ${CFLAGS} -c Queue.cpp

clean:
	rm *.o
	rm main
