#include "../minishell.h"

int	mini_unset(t_list **list, char **str)
{
	int		i;
	int		j;
	char	*tmp;
	t_list	*last;

	i = 0;
	j = 0;
	last = ft_lstlast(*list);
	tmp = last->var;
	while (str[j] != '\0')
	{
		while (str[j][i] != '\0')
			i++;
		while ((*list)->next)
		{
			if (!ft_strncmp((*list)->var, str[j], i))
			{
				last = (*list)->next;
				ft_lstdelone(*list, del);
				list = &last;
				ft_lstadd_back(list, ft_lstnew(tmp));
			}
			list = &(*list)->next;
		}
		i = 0;
		j++;
	}
	return (0);
}
