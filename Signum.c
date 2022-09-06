#include "shell.h"

/**
 * ctrl_C - A function to create a system interrupt with control + C
 * @signum: var 1
 */

void ctrl_C(int signum)
{
	if (signum == SIGINT)
	{
		print("\n($) ", STDIN_FILENO);
	}
}
