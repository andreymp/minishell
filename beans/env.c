#include "../minishell.h"

int	mini_env(t_list *list)
{
	while(list)
	{
		ft_putstr_fd(list->var, 1);
		write(1, "\n", 1);
		list = list->next;
	}
	return (0);
}