#include "recherche.h"
#include "mpsh_text_analyzer.h"

int Enchaine_OU(char *s){
	char *tab[500] = mpsh_toknizer(s);
	for(int i = 1;i<500;i++){
		if(strcmp(tab[i],"||")==0){
			if(recherche(mpsh_toknizer(tab[0]))) !=0){
				if(recherche(mpsh_toknizer(tab[i+1]))) !=0){
					 printf("commande introuvable");
				         return -1;}
				else { 	return 0;}
			}else{return 0;}
		}
	}
return 0;
}
			

int Enchaine_ET(char *s){
	char *tab[500] = mpsh_toknizer(s);
	for(int i = 1;i<500;i++){
		if(strcmp(tab[i],"&&")==0){
			if((recherche(mpsh_toknizer(tab[0]))) ==0) &&(recherche(mpsh_toknizer(tab[i+1]))) ==0)){
				return 0;
				}
				
			else{ printf("commande introuvable");
				return -1;}
		}
	}
return 0;
}
