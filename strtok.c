#include<stdio.h>
#include <string.h>

/**
 * strtok - splits a string
 * Return: 0
 */
int strtok()
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
