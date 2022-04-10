/*
 * C Program to Print Environment variables
 */
#include "main.h"

void printenv(void)
{
    unsigned int i;
    unsigned int x;

    for (i = 0; environ[i] != NULL; i++)
    {
    }
    
    while (x <= i)
    {
	    printf("%s\n", environ[x]);
	    x++;
    }
    if (x == i)
    {
	    printf("%s", environ[x]);
    }
}
