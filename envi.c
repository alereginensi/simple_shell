/*
 * C Program to Print Environment variables
 */
#include "main.h"

void printenv(void)
{
    unsigned int i;

    for (i = 0; environ[i] != NULL; i++)
    {    
        printf("%s\n", environ[i]);
    }
}
