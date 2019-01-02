/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_table.c                                           */
/* ****************************************************** */

#include "mpsh_table.h"

// #include <stdlib.h>
// #include <string.h>


char *add_text(char *text_from_file)
{
  char *text_to_list = malloc(sizeof(char)*(strlen(text_from_file) + 1));
  memset(&text_to_list[strlen(text_from_file)-2],'\0',  1);
  if(text_to_list == NULL){
    fprintf(stderr, "%s\n", strerror( errno ) );
    exit(EXIT_FAILURE);
  }else{
    strcpy(text_to_list, text_from_file);
    return text_to_list;
  }
}


table create_table(void)
{
  table t = malloc(sizeof(table));
  if(t)
  {
    return t;
  }
    fprintf(stderr, "%s\n", strerror( errno ) );
    printf("err table malloc!\n");
    exit(EXIT_FAILURE);
}

row *new_row(char *text, table row)
{
  table new;
  new = malloc(sizeof(row));
  if(new)
  {
    new->text = add_text(text);
    new->next = row;
    return new;
  }
  fprintf(stderr, "%s\n", strerror( errno ) );
  printf("err row malloc!\n");
  exit(EXIT_FAILURE);

}

static table remove_next_row(table t)
{
  row *temp = t->next;
  t->next = NULL;
  free_row(temp);
  return t;
}

static table next_row(row *row)
{
  if(row)
  {
    return row->next;
  }
  return row;
}

static row *n_row(table t, int n)
{
  if(n == 1)
  {
    return t;
  }
  else if(t == NULL)
  {
    return t;
  }
  table temp = t;
  for(int i = 1; i < n; i++)
  {
    temp = next_row(temp);
    if(temp == NULL)
    {
      printf("** row index greater than table length!\n");
      return temp;
    }
  }
  return temp;
  }

char *n_row_text(table t, int n)
{
  return n_row(t, n)->text;
}

void free_row(row *r)
{
  free(r->text);
  free(r);
}

table remove_first_row(table t)
{
  if(t)
  {
    row *deletme = t;
    if(deletme != NULL)
    {
      t = next_row(deletme);
      free_row(deletme);
    }
    return t;
  }
  return t;
}


table remove_n_row(table t, int n)  // t->n->n->n->n
{
  if(t == NULL)
  {
    printf("error empty table !\n" );
    return t;
  }
  if(n == 1)
  {
    return remove_first_row(t);
  }
  row *previous = n_row(t, n-1);
  if(previous != NULL)
  {
    row *deletme = next_row(previous);
    if(deletme != NULL)
    {
      row *next = next_row(deletme);
      previous->next = next;
      free_row(deletme);
      return t;
    }
  }
  return t;
}


table add_row(table t, int n,char *text)
{
  table temp = t;
  if(temp == NULL && n == 0)
  {
    return new_row(text, NULL);
  }
  else if (temp == NULL)
  {
    printf("error empty table !\n" );
    return t;
  }else if(n == 0)
  {
    t = new_row(text, NULL);
  }
  row *previous = n_row(t, n-1);
  if(previous != NULL)
  {
    row *add_me_here = next_row(previous);
    previous->next = new_row(text, add_me_here);

  }
  return t;
}

table append_row(table t, char *text)
{
  if(t)
  {
    table temp = last_line(t);
    temp->next = new_row(text, NULL);
    return t;
  }
  else
  {
    return t = new_row(text, NULL);
  }
}


void print_table(table t)
{
  if(t)
  {
    int i = 1;
    table temp = t;
    table next = next_row(t);
    printf("%d %s\n", i++, temp->text);
    while(next)
    {
      printf("%d %s\n", i++, next->text);
      temp = next;
      next = next_row(temp);
    }
  }
}

row *last_line(table t)
{
  if(t)
  {
    table temp = t;
    table next = next_row(t);
    while(next)
    {
      temp = next;
      next = next_row(temp);
    }
    return temp;
  }
  else
  {
    return new_row(NULL, NULL);
  }
}

char *pop(table t)
{
  return last_line(t)->text;
}

int table_length(table t)
{
    if(t)
    {
      int i = 1;
      table temp = t;
      table next = next_row(t);
      while(next)
      {
        i++;
        temp = next;
        next = next_row(temp);
      }
      return i;
    }
    return 0;
}

table remove_first_n_row(table t, int n)
{
  if(!(table_length(t) < n))
  {
    for(;n > 0; n--)
    {
      t = remove_first_row(t);
    }
    return t;
  }
  return t;
}

table limited_append_row(table t, char *text, int max)
{
  if(t)
  {
    int d = max - table_length(t);
    if(!(d > 0))
    {
      t = remove_first_n_row(t, (-1*d)+1);
    }
    table temp = last_line(t);
    temp->next = new_row(text, NULL);
    return t;
  }
  else
  {
    return t = new_row(text, NULL);
  }
}

table resize_table(table t, int size)
{

  if(t)
  {
    int d = size - table_length(t);
    if(!(d > 0))
    {
      t = remove_first_n_row(t, (-1*d));
    }
    return t;
  }
  else
  {
    return t;
  }
}
