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
 * main - main function.
 * Return: characters
 */
int main()
{
	char **argv = NULL;
	char *buffer = NULL;
	size_t bufsize = 32;
	char *token = NULL;
	size_t characters = 0;
	pid_t child = 0;
	char *exitt = "exit";
	int x = 1, counter = 0;
	size_t n = -1;

	while (x)
	{
		x = isatty(STDIN_FILENO);

		if (x == 1)
		{
			_putchar('$');
			_putchar(' ');
		}
		characters = getline(&buffer, &bufsize, stdin);
		argv = malloc(characters * sizeof(char*));
		token = strtok(buffer, "\n");
		buffer[characters + 1] = '\0';
		token = strtok(buffer, " ");

		while (token != NULL)
		{
			argv[counter] = token;
			counter++;
			token = strtok(NULL, " ");
		}
		argv[counter + 1] = NULL;

		child = fork();

			if (_strcmp(exitt, argv[0]) == 0 || characters == n)
			{
				free(argv);
				free(token);
				break;
			}
        		if (child == 0)
        		{
                		if (execve (argv[0], argv, NULL) == -1)
                		{
					perror("Error");
					free (argv);
					free (token);
					break;
				}
			}
			else
			{
			wait (NULL);
			}
			free(argv);
			free(buffer);
		        buffer = NULL;
			counter = 0;
			bufsize = 0;
	}
	free(buffer);
	return (characters);
}
