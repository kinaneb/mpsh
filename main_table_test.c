#include<stdlib.h>
#include<stdio.h>
#include "mpsh_table.h"

int main(void)
{
		table t = create_table();
		 t = new_row("teting 1", NULL);
		//print_table(t);
		printf("fff \n" );
		for(int i = 0; i <4000 ; i++){
		t=append_row(t,"testing 2");}
		printf("222 \n" );
		print_table(t);
		printf("222 \n" );
	return 0;
}
