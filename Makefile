

CC=gcc

CFLAGS=-Wall -g -std=c11 

LDLIBS= -lm

ALL = mpsh

all : $(ALL)

mpsh : mpsh.o mpsh_main_loop.o mpsh_text_analyzer.o mpsh_init.o mpsh_excuter.o

mpsh.o : mpsh.c mpsh_main_loop.h

mpsh_main_loop.o : mpsh_main_loop.c mpsh_main_loop.h mpsh_text_analyzer.h mpsh_init.h mpsh_excuter.h

mpsh_text_analyzer.o : mpsh_text_analyzer.c mpsh_text_analyzer.h

mpsh_init.o : mpsh_init.c mpsh_init.h

mpsh_excuter.o : mpsh_excuter.c mpsh_excuter.h

cleanall : rm -rf *~ $(ALL)
