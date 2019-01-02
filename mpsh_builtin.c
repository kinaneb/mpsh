/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_builtin.c                                         */
/* ****************************************************** */

#include "mpsh_builtin.h"


int exit_mpsh(char *c)
{
  if (c)
  {
    return exit_N_mpsh(atoi(c));

  }
  else
  {
    //limited_append_table(history_dir, history, HISTFILESIZE);
    last_command_status = 0;
    exit_boolean = 0;
    return 0;
  }
}

int exit_N_mpsh(int n)
{
  last_command_status = n;
  //limited_append_table(history_dir, history, HISTFILESIZE);
  exit_boolean = 0;
  return 0;
}

int history_mpsh(char *c)
{

  if(c)
  {
    int n = atoi(c);
    if(n < 0)
    {
      HISTSIZE = abs(n);
      history = resize_table(history, HISTSIZE);
      print_table(history);
      return errno;
    }
    else
    {
      if(n < table_length(history))
      {
        char ** line_tokens = mpsh_toknizer(pop(history));
        return mpsh_excuter(line_tokens);
      }
      else
      {
        printf("history size is smaller than this number \n" );
        return errno;
      }
    }
  }
  else
  {
    print_table(history);
  }
  return errno;
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
         off_t i = ftello(fp);
         ftruncate(fileno(fp), i);
       }
       printf(" error export_mpsh! \n" );
    }
    fclose(fp); // close file
    return 0;
  }
  fclose(fp); // close file
  return -1;
}


int mkdir_mpsh(char *c)
{
  mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
  int n;
  if(access(c, F_OK)) // .file is not exist)
  {
    printf("test mkdir\n" );
    n = mkdir(c, mode);
    return n;
  }
  else
  {
    printf(" File exists\n" );
    return errno;
  }

}

int echoShell(char *texteUtilisateur){

        printf("%s\n", texteUtilisateur);
        return errno;
}


int pwdShell(char *dossierType){
    char *pwdActuel = malloc(512*sizeof(char));
    if(pwdActuel){
    	if (!getcwd(pwdActuel, 512)) {
	//copie le chemin d'acces absolu du répertoire du travail courant dans la chaine pointée par pwdActuel qui est de longueur 500
        	perror("getcwd"); // affiche un message sur la sortie d'erreur standard
        	return errno;
   	 }
    printf ("Dossier %s = %s\n", dossierType, pwdActuel);
	}
    free(pwdActuel);
    return errno;
}


int cdShell(char *pathUtilisateur){
    pwdShell("ancien");

    int ret;
    ret = chdir(pathUtilisateur); //remplace le repertoire de travail courant du processus appelant par celui indiqué dans le chemin pathUtilisateur
    if (ret) {
        perror ("chdir");
        return errno;
    }

    pwdShell("actuel");
    return errno;
}

int catShell(char *pathFichier){
    char tmpBuf[512];
    FILE *monFichier = NULL;
    monFichier = fopen(pathFichier, "r+");
    if(monFichier == NULL){
        perror("fopen");
        return errno;
    }

    while (fgets(tmpBuf, 512, monFichier)>0){
        printf("%s", tmpBuf);
    }
    printf("\n");

    fclose(monFichier);
    return errno;
}


int lsShell(char *pathDossier){
  char *path = pathDossier;
  int should_free = 0;
  struct dirent *entree;
  if(path==NULL)
  {
    path = malloc(512*sizeof(char));
    should_free = 1;
    if(path)
    {
    	if (!getcwd(path, 512))
      {
        //copie le chemin d'acces absolu du répertoire du travail courant dans la chaine pointée par pwdActuel qui est de longueur 500
        //perror("getcwd"); // affiche un message sur la sortie d'erreur standard
        return errno;
      }
    }
  }
  if(path)
  {
    DIR *dossier;
    dossier = opendir(path);
    while ((entree = readdir(dossier)) != NULL)
    {
      printf("%s \n", entree->d_name);
    }
    printf("\n");
    closedir(dossier);
    if(should_free){
      free(path);
    }
    return errno;
  }
  return errno;

}



// retourne la position du char suivant lespace
//exemple alias c="clear" retourne la position de c
int getPosition(char *chaine){
	int i = 0;
	while(chaine[i] != ' ' ){
		i++;
	}
	i++;
	return i;
}

//getP retourne la position de '='
int getP(char *chaine){
	int i = 0;
	while(chaine[i] != '=' ){
		i++;
	}
	i++;
	return i;
}


//la fonction retourne le nom de lalias
char *get_N_alias(char *chaine , int pos){
	int i = pos;
	int j = 0;
	char *al = malloc( 50 * sizeof(char));

	while(chaine[i] != '=' ){
		al[j] = chaine[i];
		i++;
		j++;
	}
	return al;
}


//get_C_alias retourn le contenu de alias
char *get_C_alias(char *chaine , int pos){
	int i = pos;
	int j = 0;
	char *al = malloc( 50 * sizeof(char));

	while(chaine[i] != '\n' ){
		al[j] = chaine[i];
		i++;
		j++;
	}
	return al;
}


int alias(char *c){
	//Ouverture du fichier .bashrc
	FILE *fd = NULL;
	fd = fopen(".bashrc","a");

	if ( fd != NULL )
	{
		//si la creation du fichier s'est bien déroulée
		//on test si l'utilisateur a bien saisi une commande
		if (!c)
		{
			printf("Veuillez introduire une commande\n");
      return errno;
		}
    else
    {
      fputs("alias ",fd);
			char *commande = ajoutG(c) ;
			fputs(commande , fd);
			fputc('\n',fd);
      return errno;
    }
  }
  else
  {
		printf("Y a une erreur lors de la creation\n");
    return errno;
	}
}

//une fonction recherche dans un fichier
void unalias( char const *chaine){

		// ou placer la chaine
		char *ch = malloc(512 * sizeof(char));
		char *ch2 = malloc(512 * sizeof(char));

		//le fichier temporaire
		FILE *tmp = fopen("tmp.txt","w");
		FILE *f = fopen(".bashrc","r");

		while( (fgets(ch,512,f) != NULL) ){
			 //ch2 contient le nom de lalias
			ch2 = get_N_alias(ch,getPosition(ch));

			if ( strcmp(chaine,ch2) != 0 )
			{
				fputs(ch,tmp);
			}
		}
		//maintenat on supprime le fichier .bashrc
		if ( remove(".bashrc") == 0 )
		{
			rename("tmp.txt",".bashrc");
		}else{
			perror("remove ");
			printf("Erreur lors de la suppression du dossier\n");
		}

}

int type(char *commande){

	char *ch = malloc(512 * sizeof(char) );
	char *ch2 = malloc(512 * sizeof(char) );
	char *contenu = malloc(512 * sizeof(char) );

	//ouvrir le fichier .bashrc en lecture
	FILE *f = fopen(".bashrc","r");

	while( (fgets(ch,512,f) != NULL) ){
			 //ch2 contient le nom de lalias
			ch2 = get_N_alias(ch,getPosition(ch));
			contenu = get_C_alias(ch,getP(ch));
			if ( strcmp(commande,ch2) == 0 )
			{
				printf(" %s est un alias vers %s \n", commande , contenu );
			}
		}
    return errno;
}

char *ajoutG(char *chaine){
	int i = 0;
	int j = 0;
	char * resultat = malloc(strlen(chaine) + 3);

	while(chaine[i] != '\0' ){//tanque la chaine est non vide

		if( chaine[i] != '=' ){
			resultat[j] = chaine[i];
			j++;
			i++;
		}else{
			resultat[j] = chaine[i];
			resultat[j+1] = '"';
			j = j+2;
			i++;
		}
	}
	resultat[j] = '"';
	resultat[j+1] = '\0';
	return resultat;
}
