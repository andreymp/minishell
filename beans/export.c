/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:38 by jobject           #+#    #+#             */
/*   Updated: 2021/12/08 15:42:58 by jobject          ###   ########.fr       */
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

void	print_sorted_env(t_lst	*list)
{
	char	*temp;
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = list;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->var, tmp2->var) > 0)
			{
				temp = tmp1->var;
				tmp1->var = tmp2->var;
				tmp2->var = temp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	while (list)
	{
		ft_putendl_fd(list->var, 1);
		list = list->next;
	}
}

int	mini_export(t_lst **list, char **str, bool *flag)
{
	int		j;
	char	*tmp;
	t_lst	*last;

	j = 1;
	*flag = true;
	g_sig.ex_code = 0;
	if (!pre_export_check(str, *list))
		return (0);
	last = ft_lstlast_rem(*list);
	tmp = last->var;
	if (!make_export(str, list))
		return (0);
	ft_lstadd_back_rem(list, ft_lstnew_rem(tmp));
	return (0);
}