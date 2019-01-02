/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_function_handler.c                                  */
/* ****************************************************** */

#include "mpsh_function_handler.h"



//typedef enum {alias, cat, cd, echo, exit, export, history, ls, mkdir, [pwd], type, umask, unalias} func;

mpsh_builtin builtin[]=
{
  {"alias", alias},         //0
  {"cat", catShell},        //1
  {"cd", cdShell},          //2
  {"echo", echoShell},      //3
  {"exit", exit_mpsh},      //4
  {"export", export_mpsh},  //5
  {"history", history_mpsh},//6
  {"ls", lsShell},          //7
  {"mkdir", mkdir_mpsh},      //8
  {"pwd", pwdShell},        //9
  {"type", type},           //10
  {"umask",pwdShell},  //11
  {"unalias", lsShell}  //12
};


// alias, cat ref,cd [dir], echo $var, exit [n], export var[=word], history [n], ls [ref], mkdir [-p] ref, pwd, type name [name ...], umask mode, unalias name


int recherche(char *token)
{
  for(int i = 0; i < sizeof(builtin)/sizeof(builtin[0]); i++)
  {
    if(strcmp(token, builtin[i].s) == 0)
    {
      //return builtin[i].func(line_tokens[0]);
      return i;

    }
  }
  return -1;
}

int builtin_handler(char *line)
{
  char **line_tokens = mpsh_toknizer(line);
  int i = recherche(line_tokens[0]);
  if(i < 0)
  {
    return i;
  }
  else
  {
    return builtin[i].func(line_tokens[1]);
  }

}
// extern int echoShell(char *texteUtilisateur);
// extern int pwdShell(char *dossierType);
// extern int cdShell(char *pathUtilisateur);
// extern int catShell(char *pathFichier);
// extern int lsShell(char *pathDossier);
//
// extern int exit_mpsh(char *c);
// extern int exit_N_mpsh(int n, ...);
// extern int export_mpsh (char *s);
// extern int history_mpsh(int n);
// extern int mkdir(const char *pathname, mode_t mode);
