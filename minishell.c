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
 * main - Main function of Simple Shell.
 * Return: An integer depending on the input.
 * @argc: Argument counter.
 * @argv: Argument value.
 * @env: Enviroment variable.
 */
int main(int __attribute__((unused)) argc, char *argv[], char **env)
{	char *buffer = NULL, *exitt = "exit", *buff = NULL, *token = NULL;
	size_t bufsize = 1024, characters = 0, n = -1;
	pid_t child = 0;
	int counter = 0, status = 0, x = 1;

	while (1)
	{	signal(SIGINT, controlc);
		x = (isatty(STDIN_FILENO));
		if (x == 1)
			_putchar('$'), _putchar(' ');
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == n)
		{
			if (x == 1)
				_putchar('\n');
			break;	}
		if (changer(buffer) == 0)
			continue;
		argv = malloc(sizeof(char) * bufsize), buff = buffer;
		token = strtok(buff, "\n"), buff[characters + 1] = '\0';
		token = strtok(buff, " ");
		while (token != NULL)
			argv[counter] = token, counter++, token = strtok(NULL, " ");
		argv[counter + 1] = NULL, child = fork();
		if (_strcmp(exitt, argv[0]) == 0)
		{	free(argv), free(token);
			break;	}
		if (child == 0)
		{
			if (_strcmp("env", argv[0]) == 0)
			{	printenv(), _putchar('\n'), free(argv);
				break;	}
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error"), free(argv), free(token);
				break;	}	}
		else
			wait(&status);
		free(argv), free(buffer), buffer = NULL, counter = 0, bufsize = 0;	}
	free(buffer);
	return (WEXITSTATUS(status));	}
