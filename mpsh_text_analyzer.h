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
#include <errno.h>

extern int errno;

extern char *mpsh_read_line(void);
extern char **mpsh_toknizer(char *line);
extern char *after_equal_signe_from_line(char *line, char *target);
extern int int_target_from_line(char *line, char *target);

#endif
