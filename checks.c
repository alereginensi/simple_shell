#include "main.h"
/**
 * changer - changes tabs for spaces
 * @str: string
 * Return: 0
**/
int changer(char *str)
{
	int x = 0;

	if (str[x] != ' ' && str[x] != '\n' && str[x] != '\t')
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
