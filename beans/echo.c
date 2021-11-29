#include "../minishell.h"

int	mini_echo(char *str, int n) // n - флаг "-n"
{
	if (n == 1)
	{
		ft_putstr_fd(str, 1);
	}
	else if (n == 0)
	{
		ft_putstr_fd(str, 1);
		write(1, "\n", 1);
	}
	return (0);
}