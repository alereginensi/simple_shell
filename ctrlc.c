#include "main.h"
#include <stdio.h>
#include <signal.h>

void controlc(int sig_num)
{
        if (sig_num == SIGINT)
	write(1, "\n$ ", 3);
}
