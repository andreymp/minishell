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

void	mini_export(t_list **list, char *str)
{
	int		i;
	char	*tmp;
	t_list	*last;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '=')
			break ;
		i++;
	}
	last = ft_lstlast(*list);
	tmp = last->var;
	if(str[i] == '\0')
		return ;
	i = 0;
	ft_lstadd_preback(list, ft_lstnew(str));
	ft_lstadd_back(list, ft_lstnew(tmp));
}