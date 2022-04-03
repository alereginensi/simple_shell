#include "main.h"

/**
 */

int main()
{
	pid_t pid = fork();

	if (pid == 0)
	{
		printf("hello from child\n");
	}
	else
	{
		char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

		printf("Before execve\n");
		wait(NULL);

		if (execve (argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
		printf("After execve\n");
	}
	return (0);
}
