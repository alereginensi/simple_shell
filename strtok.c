#include<stdio.h>
#include <string.h>

int main()
{
	char string[50] = "testing ted tested toc";
	char * token = strtok(string, " ");

	while( token != NULL )
	{
		printf( " %s\n", token );
		token = strtok(NULL, " ");
	}
	return 0;
}
