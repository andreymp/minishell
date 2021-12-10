/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:12 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 12:50:39 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mini_shlvl(t_mini	**mini, char __unused **envp, bool	*flag)
{
	char	*tmp;
	char	*sl;
	int		i;
	t_lst	*temp;

	*flag = false;
	temp = (*mini)->list;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (temp && ft_strncmp(temp->var, "SHLVL=", 6))
		temp = temp->next;
	if (!temp)
	{
		i = 0;
		while (envp[i] && ft_strncmp(envp[i], "SHLVL=", 6))
			i++;
		tmp = ft_substr(envp[i], 0, 6);
		sl = ft_itoa(0);
		envp[i] = ft_strjoin(tmp, sl);
		free(sl);
	}
}
