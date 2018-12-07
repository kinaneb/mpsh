/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_text_analyzer.h                                   */
/* ****************************************************** */

#ifndef MPSH_TEXT_ANALYZER_H
#define MPSH_TEXT_ANALYZER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int errno;

extern char *mpsh_read_line(void);
extern char **mpsh_toknizer(char *line);

#endif
