#include<stdio.h>
#include <string.h>

int main()
{
	char string[50] = "testing ted tested toc";
	// Extract the first token
	char * token = strtok(string, " ");
	// loop through the string to extract all other tokens
	while( token != NULL )
	{
		printf( " %s\n", token ); //printing each token
		token = strtok(NULL, " ");
	}
	return 0;
}
