#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <erreno.h>
#include "mpsh_func.h" 
int main(int argc, char *argv[]){
	if (argc>1){
    
        	if(strcmp(argv[1],"cat")==0){
            		catShell(argv[2]);
        	}    
        	else if(strcmp(argv[1],"cd")==0){
            		cdShell(argv[2]);
        	}               
        	else if(strcmp(argv[1],"ls")==0){
            		lsShell(argv[2]);
        	}
        	else if (strcmp(argv[1],"echo")==0){
            		echoShell(argv[2]);
        	}
        
        	else if(strcmp(argv[1],"pwd")==0){
            		pwdShell("actuel");
        	}  
        	else if(strcmp(argv[1],"exit")==0){
            		exit(0);
       		}  
        	else{
            		printf("Option non disponible\n");
    
        	}
 	}else { 
		printf ("saisir un argument\n"); 
		}
return 0;
}



