/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_builtin.h                                         */
/* ****************************************************** */

#ifndef HEADERS_FILE_H
#define HEADERS_FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "mpsh_init.h"
#include "mpsh_excuter.h"
#include "mpsh_table.h"
#include "mpsh_file_handler.h"
#include "mpsh_main_loop.h"


extern int echoShell(char *texteUtilisateur);
extern int pwdShell(char *dossierType);
extern int cdShell(char *pathUtilisateur);
extern int catShell(char *pathFichier);
extern int lsShell(char *pathDossier);

extern int exit_mpsh(char *c);
extern int exit_N_mpsh(int n);
extern int export_mpsh (char *s);
extern int history_mpsh(char *c);
extern int mkdir_mpsh(char *c);




//ajouter des guillemets
extern char *ajoutG(char  *chaine);

//ajouter l'alias dans le fichier
extern int alias(char *c);

// retourne la position du char suivant lespace
//exemple alias c="clear" retourne la position de c
extern int getPosition(char *chaine);

//getP retourne la position de '='
int getP(char *chaine);

//la fonction retourne le nom de lalias
char *get_N_alias(char *chaine , int pos);

//get_C_alias retourn le contenu de alias
char *get_C_alias(char *chaine , int pos);

//une fonction recherche dans un fichier
void unalias( char const *chaine);

//elle n'est pas complète
int type(char *commande);

extern int last_command_status;
extern table history;

#endif
