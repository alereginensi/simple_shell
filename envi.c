#include "main.h"

/**
 * printenv - function that prints enviroment
 */
void printenv(void)
{
	unsigned int i;
	unsigned int x = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
	}
	while (x <= i)
	{
		write(1, environ[x], _strlen(environ[x]));
		_putchar('\n');
		x++;
	}
}
