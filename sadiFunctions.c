#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdbool.h>
#include "functions.h"

char *ajoutG(char const *chaine){
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


void alias(int argc , char const *argv[]){
	//Ouverture du fichier .bashrc
	FILE *fd = NULL;
	fd = fopen(".bashrc","a");

	if ( fd != NULL )
	{
		//si la creation du fichier s'est bien déroulée
		//on test si l'utilisateur a bien saisi une commande
		if ( argc == 0 )
		{
			printf("Veuillez introduire une commande\n");
		}else{
			//si il la bien saisi une commande
			if ( strcmp(argv[1] , "alias") == 0 )
			{
				fputs("alias ",fd);
				char *commande = ajoutG(argv[2]) ;
				fputs(commande , fd);
				fputc('\n',fd);

			}else{
				printf("voulez vous dire alias !!\n");
			} 
		}

	}else{
		printf("Y a une erreur lors de la creation\n");
	}
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

//une fonction recherche dans un fichier
void unalias( char const *chaine){
	
		// ou placer la chaine
		char *ch = malloc(1000 * sizeof(char));
		char *ch2 = malloc(1000 * sizeof(char));

		//le fichier temporaire
		FILE *tmp = fopen("tmp.txt","w");
		FILE *f = fopen(".bashrc","r");

		while( (fgets(ch,1000,f) != NULL) ){
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

void type(char const *commande){

	char *ch = malloc(1000 * sizeof(char) );
	char *ch2 = malloc(1000 * sizeof(char) );
	char *contenu = malloc(1000 * sizeof(char) );

	//ouvrir le fichier .bashrc en lecture
	FILE *f = fopen(".bashrc","r");
	
	while( (fgets(ch,1000,f) != NULL) ){
			 //ch2 contient le nom de lalias
			ch2 = get_N_alias(ch,getPosition(ch));
			contenu = get_C_alias(ch,getP(ch));
			if ( strcmp(commande,ch2) == 0 )
			{
				printf(" %s est un alias vers %s \n", commande , contenu );
			}
		}
}