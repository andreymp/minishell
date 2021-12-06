/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:00:36 by remelia           #+#    #+#             */
/*   Updated: 2021/12/06 20:25:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*envp_copy(char *envp[])
{
	t_lst	*list = NULL;
	int		i;

	i = 0;
	while(envp[i])
	{
		ft_lstadd_back_rem(&list, ft_lstnew_rem(envp[i]));
		i++;
	}
	return (list);
}

void	minishell(t_mini	*mini, char	**envp, char	*strs[])
{
	int	i;

	i = -1;
	while (1)
	{
		dup2(mini->cmds.in, STDIN_FILENO);
		dup2(mini->cmds.out, STDOUT_FILENO);
		sigaction(SIGQUIT, &mini->sig, NULL);
		sigaction(SIGINT, &mini->sig, NULL);
		strs[++i] = readline(MINISHELL"minishell $> "TEXT);
		if (!result_line(&strs[i], &mini->history, envp, mini->change))
			continue ;
		mini->lst = do_split(strs[i]);
		make_split(&mini->lst);
		if (!exec(mini->lst, mini->list, mini->change, mini->history, envp))
			run(&mini->cmds, envp, &mini->proc, mini->lst);
		ft_lstclear(&mini->lst, free);
	}
}