/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:49 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 12:52:41 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static bool	pre_check_unset(char	*str)
{
	if (!str)
	{
		ft_putendl_fd(ERROR"unset: not enough arguments"TEXT, 2);
		g_sig.ex_code = 1;
		return (false);
	}
	return (true);
}

static bool	check_equal(char	**str, int	*j)
{
	if (ft_strchr(str[*j], '='))
	{
		ft_putendl_fd(ERROR"unset: option '=' is illigal"TEXT, 2);
		g_sig.ex_code = 1;
		(*j)++;
		return (false);
	}
	return (true);
}

void	mini_unset(t_lst **list, char **str, bool *flag)
{
	int		j;
	t_lst	*last;

	j = 0;
	*flag = true;
	if (!pre_check_unset(str[1]))
		return ;
	last = ft_lstlast_rem(*list);
	g_sig.ex_code = 0;
	while (str[++j])
	{
		if (!check_equal(str, &j))
			break ;
		while ((*list)->next)
		{
			if (!ft_strncmp((*list)->var, str[j], ft_strlen(str[j])))
			{
				last = (*list)->next;
				ft_lstdelone_rem(*list, del);
				*list = last;
				break ;
			}
			list = &(*list)->next;
		}
	}
}
