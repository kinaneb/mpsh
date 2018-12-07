/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_init.c                                            */
/* ****************************************************** */


#include "mpsh_init.h"

char PS1[100] = "mpsh->: "; // max PS1 = 99 char

void mpsh_init(void)
{
  if(access(".mpshrc", F_OK)) // .mpshrc is not exist
  {
    FILE *file_pointer;
    // open the file "name_of_file.txt" for writing
    file_pointer = fopen(".mpshrc", "ab");
    // Write to the file
    fprintf(file_pointer, "PS1=\"mpsh->: \"");
    // Close the file
    fclose(file_pointer);
  }
  else // .mpshrc is exist
  {
    FILE *fp;
    char s[201]; // max buffer PS1 200
    fp = fopen (".mpshrc", "r");
    if (fp == NULL) // fail of opening file
    {
      fprintf(stderr, "%s\n", strerror( errno ) );
      exit(EXIT_FAILURE);
    }
    else
    {
      if (fgets(s, 200, fp) != NULL) // file text not ended
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
    fclose(fp);
  }

}
