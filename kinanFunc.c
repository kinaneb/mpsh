#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdarg.h>
//#include <mpshControler>

int exit_mpsh();
int exit_N_mpsh(int n, ...);
int export_mpsh (char *s);
int history_mpsh(int n);
int mkdir(const char *pathname, mode_t mode);

int b;
extern int last_command_status;

int main (void)
{
//char *ss = "test export";
  //export_mpsh("test export");
  history_mpsh(0);
  return 0;
  
}

int exit_mpsh()
{
  int last_command_status = 0;
  return last_command_status;
}

int exit_N_mpsh(int n, ...)
{
   va_list ap;
    va_start(ap, n);
    n = va_arg(ap, int);
    printf("%d.\n", n);
    va_end(ap);
  return n;
}

int history_mpsh(int n)
{
  FILE *fp;
  char s[1024];
  fp = fopen (".mpshHistory", "r");
  if (fp == NULL) // fail of opening file
  {
    perror("error opening history file.\n");
    exit(EXIT_FAILURE);
  }
  if(n == 0)
  {
    while (fgets(s, 1022, fp) != NULL) // file text not ended
    {
      memset(&s[strlen(s)-1],'\0',  1); // set end of string s
      printf(" %s\n", s);
    }
  }
  if(n > 0)
  {
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF)
    {
      if(i == n)
      {
        //lunsh_mpsh(one line without the number)
        return 0;
      }
      if (c == '\n'){i++;}
    }
    return -1;
  }
  if(n < 0)
  {

  }
  fclose(fp); // close file
  return 0;
}

int export_mpsh(char *s)
{
  FILE *fp;
  int n;
  fp = fopen (".mpshProfile", "a");
  if(fp)
  {
    n = fprintf(fp, "%s", s);
    if (n != strlen(s))
    {
       if(n > 0)
       {
         fseeko(fp,-n,SEEK_END);
         off_t position = ftello(fp);
         ftruncate(fileno(fp), position);
       }
       printf(" error export_mpsh! \n" );
    }
    fclose(fp); // close file
    return 0;
  }
  fclose(fp); // close file
  return -1;
}


int mkdir_mpsh(char *pathname, mode_t mode)
{
  int n;

  n = mkdir(pathname, mode);
  return n;
}


/*
 supporter les références de fichiers relatives et absolues ;
commandes sur mpsh sont toutes lancées en avant-plan ;
*/
