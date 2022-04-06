#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * _strcmp - function that concatenates two strings
 * @s1: variable
 * @s2: variable
 *
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;


	for (i = 0; *s1 != '\0' && *s2 != '\0' && *s1 == *s2; i++)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
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

	while (1)
	{
		argv = malloc(2 * sizeof(char*));

		argv[1] = NULL;

		_putchar('$');
		_putchar(' ');

		characters = getline(&buffer, &bufsize, stdin);

		token = strtok(buffer, "\n");
		token = strtok(buffer, " ");

		argv[0] = token;

		child = fork();

		if (_strcmp(exit, token) == 0)
		{
			free(argv);
			free(token);
			break;
		}
		/**if (scanf("%s", token) == EOF)
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
