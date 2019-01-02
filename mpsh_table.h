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
extern row *new_row(char *text, table row);
extern table remove_n_row(table t, int n);
extern table add_row(table t, int n, char *text);
extern table append_row(table t, char *text);
extern void print_table(table t);
extern row *last_line(table t);
extern char *pop(table t);
extern table limited_append_row(table t, char *text, int max);
extern void free_row(row *r);
extern table resize_table(table t, int n);
extern int table_length(table t);
extern char *n_row_text(table t, int n);


#endif
