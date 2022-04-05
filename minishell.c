#include "main.h"

/**
 * main - main function
 * Return: characters
 */

int main()
{
	char **argv;
	char *buffer = NULL;
	size_t bufsize = 32;
	char *token;
	size_t characters;
	pid_t child;

	while (1)
	{
		argv = malloc(2 * sizeof(char*));

		argv[1] = NULL;

		printf("$ ");

		characters = getline(&buffer, &bufsize, stdin);

		token = strtok(buffer, "\n");
		token = strtok(buffer, " ");

		argv[0] = token;

		child = fork();

        	if (child == 0)
        	{
                	if (execve (argv[0], argv, NULL) == -1)
                	{
                        	perror("Error");
                	}
        	}
        	else
		{
			wait (NULL);
		}
	}
		return (characters);
}
