

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mpsh_read(){
char line[1000];
//char **lines;
  scanf("%s", line);
  //char str[80] = "This is - www.tutorialspoint.com - website";
  const char s[2] = " ";
  char *token;
  char **parameters;

  /* get the first token */
  token = strtok(line, s);

  /* walk through other tokens */
  while( token != NULL ) {

     printf( " %s\n", token );

     token = strtok(NULL, s);
  }
}

search if parameters[0] exist in intern or extern functions
short mpsh_search(char *parameters , char *link){

}

if yes test(parameters[1]) contain "-" if yes mpsh_mexcuter()




int main (void)
{
  mpsh_read();
}
/*

analys


toknize (char *line)
{
}
char ** lines = toknize(user);
if (type(line[0]))
{

}*/
