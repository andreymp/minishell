#include "../minishell.h"

t_list	*ft_lstlastlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_preback(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlastlast(*lst)->next = new;
	else
		*lst = new;
}

int	if_same(t_list **list, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	while ((*list)->next)
	{
		if (!ft_strncmp((*list)->var, str, i))
		{
			(*list)->var = str;
			return (1);
		}
		list = &(*list)->next;
	}
	return (0);
}

int	mini_export(t_list **list, char **str)
{
	int		i;
	int		j;
	char	*tmp;
	t_list	*last;

	j = 0;
	i = 0;
	last = ft_lstlast(*list);
	tmp = last->var;
	while (str[j] != '\0')
	{
		while (str[j][i] != '\0')
		{
			if (str[j][i] == '=')
				break ;
			i++;
		}
		if (str[j][i] == '\0')
			return (0);
		if (if_same(list, str[j]))
			return (0);
		if (j == 0)
			ft_lstadd_preback(list, ft_lstnew(str[j]));
		else
			ft_lstadd_back(list, ft_lstnew(str[j]));
		i = 0;
		j++;
	}
	ft_lstadd_back(list, ft_lstnew(tmp));
	return (0);
}
