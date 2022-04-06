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
	char *exit = "exit";
	/**char *EOF = EOF;*/

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

		if (strcmp(exit, token) == 0)
		{
			free(argv);
			free(token);
			break;
		}
		/**if (strcmp(EOF, token) == 0)
		{
			free(argv);
			free(token);
			break;
		}*/
        	if (child == 0)
        	{
                	if (execve (argv[0], argv, NULL) == -1)
                	{
                        	perror("Error");
				free (argv);
			}
		}
		else
		{
			free(argv);
			wait (NULL);
		}
	}
	return (characters);
}
