#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_list	*ft_lstnew(void	*content)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (list)
	{
		list->var = content;
		list->next = 0;
	}
	return (list);
}

void	ft_lstdelone(t_list	*lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->var);
	free(lst);
}

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}