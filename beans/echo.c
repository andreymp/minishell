#include "../minishell.h"

int	mini_echo(char **str) // n - флаг "-n"
{
	bool	nflag;
	int 	i;

	nflag = false;
	i = 0;
	if (str[1] && !ft_strcmp(str[1], "-n"))
		nflag = true;
	if (nflag)
		i = 1;
	while (str[++i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
	}
	if (!nflag)
		ft_putstr_fd("\n", 1);
	return (0);
}