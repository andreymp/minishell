/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:49 by jobject           #+#    #+#             */
/*   Updated: 2021/12/03 17:39:06 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_unset(t_lst **list, char **str)
{
	int		i;
	int		j;
	t_lst	*last;

	i = 0;
	j = 1;
	if (!str[j])
	{
		ft_putendl_fd("unset: not enough arguments", 2);
		return (0);
	}
	last = ft_lstlast_rem(*list);
	while (str[j])
	{
		while (str[j][i])
			i++;
		while ((*list)->next)
		{
			if (!ft_strncmp((*list)->var, str[j], i))
			{
				last = (*list)->next;
				ft_lstdelone_rem(*list, del);
				*list = last;
				break ;
			}
			list = &(*list)->next;
		}
		i = 0;
		j++;
	}
	return (0);
}
