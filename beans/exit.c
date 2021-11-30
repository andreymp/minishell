#include "../minishell.h"

int	ft_isdigit(int c)
{
	char	i;

	i = '0';
	while (i < 58)
	{
		if (i == c)
			return (1);
		i++;
	}
	return (0);
}

void	mini_exit(char *str)
{
	int	exit_code;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
		{
			write(2, "numeric argumen required\n", 25);
			exit(255);
		}
		i++;
	}
	exit_code = ft_atoi(str);
	while (exit_code < 0)
		exit_code = 256 + exit_code;
	while(exit_code > 255)
		exit_code = exit_code - 256;
	exit(exit_code);
}