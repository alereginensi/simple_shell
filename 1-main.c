#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 *main - function
 *Return: number of chars
**/
int main()
{
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

printf("%s", buffer);
return (characters);



}
