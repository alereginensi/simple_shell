#include "main.h"

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
 * Return: characters.
 */
int main(void)
{	char **argv = NULL, *env = "env", *buffer = NULL, *exitt = "exit";
	char *token = NULL;
	size_t bufsize = 32, characters = 0, n = -1;
	pid_t child = 0;
	int x = 1, counter = 0;

	while (x)
	{	x = isatty(STDIN_FILENO);
		if (x == 1)
			_putchar('$'), _putchar(' ');
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == n)
			break;
		if (changer(buffer) == 0)
			continue;
		argv = malloc(characters * sizeof(char *));
		token = strtok(buffer, "\n"), buffer[characters + 1] = '\0';
		token = strtok(buffer, " ");/**token = strtok(buffer, "\t");*/
		while (token != NULL)
			argv[counter] = token, counter++, token = strtok(NULL, " ");
		argv[counter + 1] = NULL, child = fork();
		if (_strcmp(exitt, argv[0]) == 0)
		{
			free(argv), free(token);
			break;	}
		if (child == 0)
		{
			if (_strcmp(env, argv[0]) == 0)
			{
				printenv(), _putchar('\n'), free(argv);
				break;	}
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error"), free(argv), free(token);
				break;	}	}
		else
			wait(NULL);
		free(argv), free(buffer), buffer = NULL, counter = 0, bufsize = 0;	}
	free(buffer);
	return (0);
}
