/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_table.h                                           */
/* ****************************************************** */

#ifndef MPSH_TABLE_H
#define MPSH_TABLE_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct row row;
typedef row *table;
struct row{
  char *text;
  table next;
};

extern int errno;

extern table create_table(void);
extern table remove_row(table t, int n);
extern table add_row(table t, int n, char *text);
extern table append_row(table t, char *text);
extern void print_table(table t);

#endif
