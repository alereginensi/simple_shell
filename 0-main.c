#include<stdio.h>
#include<unistd.h>

/**
 * main - main
 * Return: 0
 */
int main()
{
	printf("Process ID: %d\n", getpid() );
	printf("Parent Process ID: %d\n", getppid() );

	return 0;
}
