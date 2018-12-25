#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdbool.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
		if ( strcmp(argv[1],"type") == 0 )
		{
			type(argv[2]);
		}
		
		if ( strcmp(argv[1],"alias") == 0 )
		{
			alias(argc , argv);
		}
		if ( strcmp(argv[1],"unalias") == 0 )
		{
			unalias(argv[2]);
		}
	return 0;
}