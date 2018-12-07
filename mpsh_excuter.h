/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_excuter.h                                         */
/* ****************************************************** */

#ifndef MPSH_EXCUTER_H
#define MPSH_EXCUTER_H

#include <unistd.h> // fork lib
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

extern int mpsh_excuter(char **line_tokens);

#endif
