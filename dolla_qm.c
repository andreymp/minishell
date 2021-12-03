#include "minishell.h"

void	dollar(char *str, int ex_code)
{
	char	*code;

	code = ft_itoa(ex_code);
	if (!ft_strcmp(str, "$?"))
	{
		ft_putstr_fd("minishell: command not found: ", 1);
		ft_putstr_fd(code, 1);
		write(1, "\n", 1);
	}
}