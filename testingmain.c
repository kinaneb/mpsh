/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* testingmain.c                                          */
/* ****************************************************** */

#include "mpsh_table.h"


int main(void)
{
  char c[100] = "SP1=\"";
  char s[50] = "SP1=\"    sd";
  if(strncmp(c, "SP1" , 3)==0){
    c[2] = '\0';
  printf("%s\n",c );}
  table t;
  for(int i = 0; i < 5; i ++){
    // char *s = malloc(sizeof(char)*16);
    // if(s == NULL){
    //   printf("malloc sting error \n");
    //   return 1;
    // }
    char c[] = "I am testing " ;
    //s = c ;
    //memset(s+14, '\0', 1);
    //printf("while test\n");
    t = append_row(t, c);

    // free(s);
  }

  //printf("testing...\n");
  print_table(t);
  free(t);
}
