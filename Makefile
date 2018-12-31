CC=gcc

CFLAGS=-Wall -g -std=c11 

LDLIBS= -lm

ALL = mpsh_main

all: $(ALL)

mpsh_main: mpsh_main.o mpsh_func.o 

mpsh_main.o : mpsh_main.c mpsh_func.h

mpsh_func.o:mpsh_func.c mpsh_func.h

cleanall :rm -rf *~ $(ALL)

