#include "../minishell.h"

t_lst	*ft_lstlastlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_preback(t_lst **lst, t_lst *new)
{
	if (*lst)
		ft_lstlastlast(*lst)->next = new;
	else
		*lst = new;
}

int	if_same(t_lst **list, char *str)
{
	int i;

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

int	mini_export(t_lst **list, char *str)
{
	int     i;
    char    *tmp;
    t_lst  *last;
 
    i = 0;
	if (!str)
		return (1);
    while (str[i] != '\0')
    {
        if (str[i] == '=')
            break ;
        i++;
    }
    if (str[i] == '\0')
        return (0);
    if (if_same(list, str))
        return (0);
    last = ft_lstlast_rem(*list);
    tmp = last->var;
    ft_lstadd_preback(list, ft_lstnew_rem(str));
    ft_lstadd_back_rem(list, ft_lstnew_rem(tmp));
    return (0);
}
