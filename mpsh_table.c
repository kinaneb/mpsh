/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_table.c                                           */
/* ****************************************************** */

#include "mpsh_table.h"

// #include <stdlib.h>
// #include <string.h>



table create_table(void)
{
  table t = malloc(sizeof(table));
  if(t)
  {
    t->text = "";
    t->next = NULL;
    return t;
  }
    fprintf(stderr, "%s\n", strerror( errno ) );
    printf("err table malloc!\n");
    exit(EXIT_FAILURE);
}

static row *new_row(char *text, table row)
{
  table new;
  new = malloc(sizeof(row));
  if(new)
  {
    new->text = text;
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
  free(temp);
  return t;
}

static table next_row(row *row)
{
  if(row)
  {
    //printf("row index greater than table length!\n");
    return row->next;
  }
  return row;
}

static row *n_row(table t, int n)
{
  if(n == 0)
  {
    return t;
  }
  else if(t == NULL)
  {
    return t;
  }
    table temp = t;
    for(int i = 0; i < n; i++)
    {
      temp = next_row(temp);
      if(temp == NULL && n-i > 1)
      {
        printf("** row index greater than table length!\n");
        return temp;
      }
    }
    return temp;
  }


table remove_row(table t, int n)  // t->n->n->n->n
{
  if(t == NULL)
  {
    printf("error empty table !\n" );
    return t;
  }
  row *previous = n_row(t, n-1);
  if(previous != NULL)
  {
    row *deletme = next_row(previous);
    if(deletme != NULL)
    {
      row *next = next_row(deletme);
      previous->next = next;
      free(deletme);
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
    table temp = t;
    table next = next_row(t);
    while(next)
    {
      temp = next;
      next = next_row(temp);
    }
    temp->next = new_row(text, NULL);
    return t;
  }
  else
  {
    return new_row(text, NULL);
  }
}


void print_table(table t)
{
  if(t)
  {
    int i = 1;
    table temp = t;
    table next = next_row(t);
    while(next)
    {
      printf("%d %s\n", i++, temp->text);
      temp = next;
      next = next_row(temp);
    }
  }
}
