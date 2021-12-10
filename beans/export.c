/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:38 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 13:09:41 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

static void	just_print(t_lst	*tmp1)
{
	while (tmp1)
	{
		ft_putendl_fd(tmp1->var, 1);
		tmp1 = tmp1->next;
	}
}

void	print_sorted_env(t_lst	*list)
{
	char	*temp;
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*copy;

	copy = make_copy_env(list);
	tmp1 = copy;
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
	just_print(copy);
	ft_lstclear_rem(&copy, del);
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
