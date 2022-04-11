#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>

extern char **environ;
void printenv(void);
int _putchar(char c);
int _strlen(char *s);
int changer(char *str);

#endif
