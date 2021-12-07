/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:38 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 18:25:57 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	mini_export(t_lst **list, char **str, bool *flag)
{
	int		i;
	int		j;
	char	*tmp;
	t_lst	*last;

	j = 1;
	i = 0;
	if (!str[j])
	{
		mini_env(*list, flag);
		return (0);
	}
	last = ft_lstlast_rem(*list);
	tmp = last->var;
	while (str[j])
	{
		while (str[j][i] && str[j][i] != '=')
			i++;
		if (!str[j][i])
			return (0);
		if (if_same(list, str[j]))
			return (0);
		if (j == 1)
			ft_lstadd_preback(list, ft_lstnew_rem(str[j]));
		else
			ft_lstadd_back_rem(list, ft_lstnew_rem(str[j]));
		i = 0;
		j++;
	}
	ft_lstadd_back_rem(list, ft_lstnew_rem(tmp));
	*flag = true;
	g_exit = 0;
	return (0);
}