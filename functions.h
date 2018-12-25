#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//ajouter des guillemets
char *ajoutG(char const *chaine);
//ajouter l'alias dans le fichier
void alias(int argc , char const *argv[]);
// retourne la position du char suivant lespace
//exemple alias c="clear" retourne la position de c
int getPosition(char *chaine);

//getP retourne la position de '='
int getP(char *chaine);
//la fonction retourne le nom de lalias
char *get_N_alias(char *chaine , int pos);
//get_C_alias retourn le contenu de alias
char *get_C_alias(char *chaine , int pos);
//une fonction recherche dans un fichier
void unalias( char const *chaine);
//elle n'est pas complète
void type(char const *commande);

#endif