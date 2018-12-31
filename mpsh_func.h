#ifndef MPSH_H
#define MPSH_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

extern int errno;

int echoShell(char *texteUtilisateur);
int  pwdShell(char *dossierType);
int  cdShell(char *pathUtilisateur);
int catShell(char *pathFichier);
int lsShell(char *pathDossier);

#endif
