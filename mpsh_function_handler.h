/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_function_handler.h                                  */
/* ****************************************************** */

#ifndef MPSH_FUNCTION_HANDLER_H
#define MPSH_FUNCTION_HANDLER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include "mpsh_builtin.h"
#include "mpsh_text_analyzer.h"

struct mpsh_builtin
{
  char* s;
  int (*func)(char *line);
};
typedef struct mpsh_builtin mpsh_builtin;

extern int recherche(char *line);
extern int builtin_handler(char *line);

#endif
