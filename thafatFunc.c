#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

void
echoShell (char *texteUtilisateur);
void
pwdShell (char *dossierType);
void
cdShell (char *pathUtilisateur);
void
catShell (char *pathFichier);
void
lsShell (char *pathDossier);

int
main (int argc, char *argv[])
{

  if (strcmp (argv[1], "cat") == 0)
    {
      catShell (argv[2]);
    }
  else if (strcmp (argv[1], "cd") == 0)
    {
      cdShell (argv[2]);
    }
  else if (strcmp (argv[1], "ls") == 0)
    {
      lsShell (argv[2]);
    }
  else if (strcmp (argv[1], "echo") == 0)
    {
      echoShell (argv[2]);
    }

  else if (strcmp (argv[1], "pwd") == 0)
    {
      pwdShell ("actuel");
    }
  else if (strcmp (argv[1], "exit") == 0)
    {
      exit (0);
    }
  else if (strcmp (argv[1], "  ") == 0)
    {
      printf ("saisir la command que vous voulez\n");
    }
  else
    {
      printf ("Option non disponible\n");

    }

  return 0;
}

void
echoShell (char *texteUtilisateur)
{
  printf ("%s\n", texteUtilisateur);
}

void
pwdShell (char *dossierType)
{
  char *pwdActuel = malloc (500 * sizeof(char));
  if (pwdActuel)
    {
      if (!getcwd (pwdActuel, 500))
	{
	  perror ("getcwd");
	  exit (-1);
	}
      printf ("Dossier %s = %s\n", dossierType, pwdActuel);
    }
  free (pwdActuel);
}

void
cdShell (char *pathUtilisateur)
{
  pwdShell ("ancien");

  int ret;
  ret = chdir (pathUtilisateur);
  if (ret)
    {
      perror ("chdir");
      exit (EXIT_FAILURE);
    }

  pwdShell ("actuel");
}

void
catShell (char *pathFichier)
{
  char tmpBuf[512];
  FILE *monFichier = NULL;
  monFichier = fopen (pathFichier, "r+");
  if (monFichier == NULL)
    {
      perror ("fopen");
      exit (-1);
    }

  while (fgets (tmpBuf, 512, monFichier) > 0)
    {
      printf ("%s", tmpBuf);
    }
  printf ("\n");

  fclose (monFichier);
}

void
lsShell (char *pathDossier)
{
  struct dirent *entree;

  DIR *dossier;
  dossier = opendir (pathDossier);

  while ((entree = readdir (dossier)) != NULL)
    {
      printf ("%s ", entree->d_name);
    }

  printf ("\n");
  closedir (dossier);
}

