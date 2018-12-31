CC=gcc

CFLAGS=-Wall -g -std=c11

LDLIBS= -lm

ALL = mpsh_main

all: $(ALL)

mpsh : mpsh.o mpsh_builtin.o mpsh_main_loop.o mpsh_text_analyzer.o mpsh_init.o mpsh_excuter.o mpsh_table.o mpsh_file_handler.o mpsh_function_handler.o 

mpsh_main: mpsh_main.o mpsh_func.o 

mpsh_main.o : mpsh_main.c mpsh_func.h

mpsh_main_loop.o : mpsh_main_loop.c mpsh_main_loop.h mpsh_text_analyzer.h mpsh_init.h mpsh_excuter.h mpsh_function_handler.h mpsh_file_handler.h

mpsh_func.o:mpsh_func.c mpsh_func.h

mpsh_init.o : mpsh_init.c mpsh_init.h mpsh_table.h mpsh_function_handler.h

mpsh_table.o : mpsh_table.c mpsh_table.h

mpsh_excuter.o : mpsh_excuter.c mpsh_excuter.h

mpsh_builtin.o : mpsh_builtin.c mpsh_builtin.h mpsh_init.h mpsh_excuter.h mpsh_table.h mpsh_main_loop.h

mpsh_file_handler.o : mpsh_file_handler.c mpsh_file_handler.h mpsh_main_loop.h mpsh_table.h mpsh_init.h

mpsh_function_handler.o : mpsh_function_handler.c mpsh_function_handler.h mpsh_builtin.h



cleanall : rm -rf *~ $(ALL)
