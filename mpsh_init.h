/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_init.h                                         */
/* ****************************************************** */

#ifndef MPSH_INIT_H
#define MPSH_INIT_H

#include "mpsh_text_analyzer.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "mpsh_table.h"
//#include "mpsh_file_handler.h"
#include "mpsh_function_handler.h"




extern char PS1[];
extern table history;
extern char *home_dir;
extern char *history_dir;
extern int mpsh_init(void);
extern void mpshrc(char *s);
extern int HISTSIZE;
extern int HISTFILESIZE;
extern int last_command_status;
extern int history_init_len;
extern int history_counter;

#endif
