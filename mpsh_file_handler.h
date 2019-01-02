/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_file_handler.h                                    */
/* ****************************************************** */

#ifndef MPSH_FILE_HANDLER_H
#define MPSH_FILE_HANDLER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mpsh_table.h"
#include "mpsh_init.h"

extern void append_line_to_file(char *file_dir, char *line);
extern void remove_first_n_line(char *file_dir, int n);
extern void remove_last_n_line(char *file_dir, int n);
extern void limited_append_line(char *file_dir, char *line, int max);
extern char *find_line_in_file(char *file_dir, char *word);
extern void limited_append_table(char *file_dir, table table , int max);

#endif
