#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "mpsh_func.h"


void echoShell(char *texteUtilisateur){

        printf("%s\n", texteUtilisateur); 
}


void pwdShell(char *dossierType){
    char *pwdActuel = malloc(500*sizeof(char));
    if(pwdActuel){
    	if (!getcwd(pwdActuel, 500)) { 
	//copie le chemin d'acces absolu du répertoire du travail courant dans la chaine pointée par pwdActuel qui est de longueur 500
        	perror("getcwd"); // affiche un message sur la sortie d'erreur standard  
        	exit(-1);
   	 }
    printf ("Dossier %s = %s\n", dossierType, pwdActuel);
	} 
    free(pwdActuel);
}


void cdShell(char *pathUtilisateur){
    pwdShell("ancien");

    int ret;
    ret = chdir(pathUtilisateur); //remplace le repertoire de travail courant du processus appelant par celui indiqué dans le chemin pathUtilisateur 
    if (ret) {
        perror ("chdir");
        exit (EXIT_FAILURE);
    }

    pwdShell("actuel");
}

void catShell(char *pathFichier){
    char tmpBuf[512];
    FILE *monFichier = NULL;
    monFichier = fopen(pathFichier, "r+");
    if(monFichier == NULL){
        perror("fopen");
        exit(-1);        
    }          

    while (fgets(tmpBuf, 512, monFichier)>0){ 
        printf("%s", tmpBuf);            
    }
    printf("\n");
    
    fclose(monFichier);
}


void lsShell(char *pathDossier){
    struct dirent *entree;
    
    DIR *dossier;
    dossier = opendir(pathDossier);
    
    while ((entree = readdir(dossier)) != NULL) {
            printf("%s ", entree->d_name);
    }
    
    printf("\n");
    closedir(dossier);
}

