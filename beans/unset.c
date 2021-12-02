#include "../minishell.h"

int	mini_unset(t_lst **list, char *str)
{
	int		i;
	char	*tmp;
	t_lst	*last;

	i = 0;
	if (!str)
		return (1);
    last = ft_lstlast_rem(*list);
    tmp = last->var;
    while (str[i] != '\0')
        i++;
    while ((*list)->next)
    {
        if (!ft_strncmp((*list)->var, str, i))
        {
            ft_lstclear_rem(list, del);
            ft_lstadd_back_rem(list, ft_lstnew_rem(tmp));
            return (0);
        }
        list = &(*list)->next;
    }
    return (0);
}