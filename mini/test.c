#include "includes/minishell.h"
int main (int ac, char ** av, char **env)
{
	if (av[ac - 1] || env)
	execve("/bin/ls", av+ 1, NULL);
}