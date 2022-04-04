#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 *main - function
 *Return: characters
**/
int main()
{
int x, y, z;
char *buffer;
size_t bufsize = 32;
size_t characters;

buffer = (char *)malloc(bufsize * sizeof(char));

if (buffer == NULL)
{
return (-1);
}

printf("$ ");
characters = getline(&buffer, &bufsize, stdin);

for (x = 0; buffer[x] != '\0'; x++)
{
	if (buffer[x] == ' ')
	{
		y = x
		z = x
	}

return (characters);

}
