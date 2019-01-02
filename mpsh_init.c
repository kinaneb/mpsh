/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_init.c                                            */
/* ****************************************************** */


#include "mpsh_init.h"


char PS1[100] = "mpsh (: "; // max PS1 = 99 char
table history;
char *home_dir;
char *rc_dir;
char *history_dir;
int HISTSIZE= 1000;
int HISTFILESIZE= 2000;
int last_command_status = 0;
int history_init_len = 0;



int init_dir(void)
{
  home_dir = getenv("HOME");
  rc_dir = malloc(sizeof(char)*(strlen(home_dir)+strlen("/.mpshrc")+ 1));
  history_dir = malloc(sizeof(char)*(strlen(home_dir)+strlen("/.mpshrc")+ 1));
  if(home_dir == NULL){
    fprintf(stderr, "%s\n", strerror( errno ) );
    return errno;
  }
  else if (rc_dir == NULL)
  {
    fprintf(stderr, "%s\n", strerror( errno ) );
    return errno;
  }
  else if (history_dir == NULL)
  {
    fprintf(stderr, "%s\n", strerror( errno ) );
    return errno;
  }
  else
  {
    strcpy(rc_dir, home_dir);
    strcpy(history_dir, home_dir);
    strcat(rc_dir, "/.mpshrc");
    strcat(history_dir, "/.mpshHistory");
    if(home_dir == NULL || rc_dir == NULL || history_dir == NULL)
    {
      fprintf(stderr, "%s\n", strerror( errno ) );
      return errno;
    }
  }
  return errno;
}

int mpsh_init_history(void)
{

  if(access(history_dir, F_OK)) // .mpshHistory is not exist
  {
    FILE *file_pointer;
    // open the file "name_of_file.txt" for writing
    file_pointer = fopen(history_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "");
    // Close the file
    fclose(file_pointer);
  }
  else // .mpshHistory is exist
  {
  FILE *file_pointer ;
  char s[512];
  file_pointer = fopen (history_dir, "r+");
  if (file_pointer == NULL) // fail of opening file
  {
    perror("error opening history file.\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(s, 510, file_pointer) != NULL) // file text not ended
  {
    memset(&s[strlen(s)-1],'\0',  1); // set end of string s
    history = limited_append_row(history, s, HISTSIZE);
  }
  fclose(file_pointer); // close file
  }

  return 0;
}

int mpsh_init_rc(void)
{
  if(access(rc_dir, F_OK)) // .mpshrc is not exist
  {
    FILE *file_pointer;
    // open the file "name_of_file.txt" for writing
    file_pointer = fopen(rc_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "PS1=\"mpsh (: \"");
    // Close the file
    fclose(file_pointer);
  }
  else // .mpshrc is exist
  {
    FILE *file_pointer ;
    char s[201]; // max buffer PS1 200
    file_pointer = fopen (rc_dir, "r");
    if (file_pointer == NULL) // fail of opening file
    {
      fprintf(stderr, "%s\n", strerror( errno ) );
      return errno;
    }
    else
    {
      if (fgets(s, 200, file_pointer) != NULL) // file text not ended
      {
        memset(&s[200],'\0',  1); // set end of string s
      }
      char *ps1 = "PS1=\"";
      if(strncmp(s, ps1 , 5)==0)
      {
        int i;
        for(i = 0; strncmp(&s[i+5], "\"" , 1); i++)
        {
          PS1[i]=s[i+5];
        }
        PS1[i]='\0';
      }
    }
    fclose(file_pointer);
  }
  return errno;
}


int mpsh_init(void)
{
  if(init_dir())
  {
    fprintf(stderr, "%s\n", strerror( errno ) );
    return errno;
  }
  mpsh_init_rc();
  mpsh_init_history();
  history_init_len = table_length(history);
  return errno;
}
