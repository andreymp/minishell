/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:49 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 15:41:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mini_unset(t_lst **list, char **str, bool *flag)
{
	int		size;
	int		j;
	t_lst	*last;
	t_lst	*head;

	j = 1;
	*flag = true;
	head = *list;
	if (!str[j])
	{
		ft_putendl_fd(ERROR"unset: not enough arguments"TEXT, 2);
		g_exit = 1;
		return (0);
	}
	last = ft_lstlast_rem(*list);
	while (str[j])
	{
		size = ft_strlen(str[j]);
		while ((*list)->next)
		{
			if (!ft_strncmp((*list)->var, str[j], size))
			{
				last = (*list)->next;
				ft_lstdelone_rem(*list, del);
				*list = last;
				break ;
			}
			list = &(*list)->next;
		}
		list = &head;
		j++;
	}
	g_exit = 0;
	return (0);
}
