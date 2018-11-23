

CC=gcc

CFLAGS=-Wall -g -std=c11

LDLIBS= -lm

ALL = thafatFunc kinanFunc

all : $(ALL)

tp5 : thafatFunc.c kinanFunc.c

cleanall : rm -rf *~ $(ALL)
