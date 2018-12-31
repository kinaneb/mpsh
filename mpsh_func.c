
#include "mpsh_func.h"


int echoShell(char *texteUtilisateur){

        printf("%s\n", texteUtilisateur); 
	return 0;
}


int pwdShell(char *dossierType){
    char *pwdActuel = malloc(500*sizeof(char));
    if(pwdActuel){
    	if (!getcwd(pwdActuel, 500)) { 
	//copie le chemin d'acces absolu du répertoire du travail courant dans la chaine pointée par pwdActuel qui est de longueur 500
        	fprintf(stderr, "%s\n", strerror( errno ) ); // affiche un message sur la sortie d'erreur standard  
        	return errno;
   	 }
    printf ("Dossier %s = %s\n", dossierType, pwdActuel);
	} 
    free(pwdActuel);
return 0;
}


int cdShell(char *pathUtilisateur){
    pwdShell("ancien");

    int ret;
    ret = chdir(pathUtilisateur); //remplace le repertoire de travail courant du processus appelant par celui indiqué dans le chemin pathUtilisateur 
    if (ret) {
        fprintf(stderr, "%s\n", strerror( errno ) );
	return errno; 
    }

    pwdShell("actuel");
return 0;
}

int catShell(char *pathFichier){
    char tmpBuf[512];
    FILE *monFichier = NULL;
    monFichier = fopen(pathFichier, "r+");
    if(monFichier == NULL){
      fprintf(stderr, "%s\n", strerror( errno ) );
      return errno;         
    }          

    while (fgets(tmpBuf, 512, monFichier)>0){ 
        printf("%s", tmpBuf);            
    }
    printf("\n");
    
    fclose(monFichier);
return 0;
}


int lsShell(char *pathDossier){
    struct dirent *entree;
    
    DIR *dossier;
    dossier = opendir(pathDossier);
    if ((entree = readdir(dossier)) == NULL) {
	    fprintf(stderr, "%s\n", strerror( errno ) );
      	    return errno;}  
    while ((entree = readdir(dossier)) != NULL) {
            printf("%s ", entree->d_name);
    }
    
    printf("\n");
    closedir(dossier);
return 0;
}

