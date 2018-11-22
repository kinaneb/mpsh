

CC=gcc

CFLAGS=-Wall -g -std=c11

LDLIBS= -lm

ALL = mpsh

all : $(ALL)

tp5 : mpsh.c

cleanall : rm -rf *~ $(ALL)
