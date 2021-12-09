/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:12 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 21:42:04 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mini_shlvl(t_mini	**mini, char	**envp, bool	*flag)
{
	char	*tmp;
	char	*sl;
	t_lst	*temp;

	*flag = false;
	temp = (*mini)->list;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	(*mini)->shlvl++;
	while (temp && ft_strncmp(temp->var, "SHLVL=", 6))
		temp = temp->next;
	if (!temp)
	{
		(*mini)->list = envp_copy(envp);
		(*mini)->shlvl = 1;
	}
	else
	{
		tmp = ft_substr(temp->var, 0, 6);
		sl = ft_itoa((*mini)->shlvl);
		temp->var = ft_strjoin(tmp, sl);
		free(sl);
	}
}
