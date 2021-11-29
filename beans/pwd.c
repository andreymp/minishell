#include "../minishell.h"

int	mini_pwd(void)
{
	char	*dir;
	int		size;
	char	*res;

	size = 1;
	while (1)
	{
		dir = malloc(size);
		res = getcwd(dir, size);
		if (res == NULL)
			size++;
		else
		{
			ft_putstr_fd(dir, 1);
			write(1, "\n", 1);
			free(dir);
			break ;
		}	
		free(dir);
	}
	return (0);
}