#include<stdio.h>
#include <string.h>

/**
 * main - splits a string
 * Return: 0
 */
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
