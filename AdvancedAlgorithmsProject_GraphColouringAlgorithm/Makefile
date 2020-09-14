CC = g++
WFLAG = -Wall  		#Warning Flag
DFLAG = -ggdb		#Debugging Flag
CFLAG = -c		#Compiling Flag
SOURCES = src
INCLUDES = include
BUILDS = build
BINARY = bin

all:GraphColouring

GraphColouring: GraphColouring.o
	${CC} ${WFLAG} ${DFLAG} -o ${BINARY}/GraphColouring ${BUILDS}/GraphColouring.o 

GraphColouring.o: ${SOURCES}/GraphColouring.cpp
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} -I${INCLUDES} -o ${BUILDS}/GraphColouring.o ${SOURCES}/GraphColouring.cpp
.PHONY: clean

clean:
	rm -rf ${BINARY}/*
	#rm -rf ${BUILDS}