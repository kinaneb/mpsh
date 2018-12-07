/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_init.h                                         */
/* ****************************************************** */

#ifndef MPSH_INIT_H
#define MPSH_INIT_H

#include "mpsh_text_analyzer.h"
#include <unistd.h>

extern char PS1[];
extern void mpsh_init(void);
extern void mpshrc(char *s);

#endif
