/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:49 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 16:33:29 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mini_unset(t_lst **list, char **str, bool *flag)
{
	int		i;
	int		j;
	t_lst	*last;

	i = 0;
	j = 1;
	*flag = true;
	if (!str[j])
	{
		ft_putendl_fd(ERROR"unset: not enough arguments"TEXT, 2);
		g_sig.ex_code = 1;
		return (0);
	}
	last = ft_lstlast_rem(*list);
	while (str[j])
	{
		if (ft_strchr(str[j], '='))
		{
			ft_putendl_fd(ERROR"unset: option '=' is illigal"TEXT, 2);
			g_sig.ex_code = 1;
			j++;
			break ;
		}
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
	g_sig.ex_code = 0;
	return (0);
}
