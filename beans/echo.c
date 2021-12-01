#include "../minishell.h"

int	mini_echo(char *str, int n, int ex_code) // n - флаг "-n"
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "$?"))
		ft_putstr_fd(str, 1);
	else
		ft_putstr_fd(ft_itoa(ex_code), 1);
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}