#include<stdio.h>
#include<unistd.h>

/**
 * getppid - main
 * Return: 0
 */
int getppid()
{
	printf("Process ID: %d\n", getpid() );
	printf("Parent Process ID: %d\n", getppid() );

	return 0;
}
