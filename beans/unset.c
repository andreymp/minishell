#include "../minishell.h"

int	mini_unset(t_list **list, char *str)
{
	int		i;
	char	*tmp;
	t_list	*last;

	i = 0;
	last = ft_lstlast(*list);
	tmp = last->var;
	while (str[i] != '=')
		i++;
	while ((*list)->next)
	{
		if (!ft_strncmp((*list)->var, str, i))
		{
			ft_lstclear(list, del);
			ft_lstadd_back(list, ft_lstnew(tmp));
			return (0);
		}
		*list = (*list)->next;
	}
	return (0);
}