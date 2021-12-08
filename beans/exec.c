/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:41:48 by jobject           #+#    #+#             */
/*   Updated: 2021/12/08 21:06:49 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	exec(t_mini	*mini, char	**envp)
{
	bool	flag;
	t_list	*tmp;

	tmp = mini->lst;
	while (tmp)
	{
		flag = false;
		if (!ft_strcmp(tmp->cmd[0], "pwd"))
			mini_pwd(&flag);		
		if (!ft_strcmp(tmp->cmd[0], "cd"))
			mini_cd(tmp->cmd[1], &mini->list, &flag);
		if (!ft_strcmp(tmp->cmd[0], "echo"))
			mini_echo(tmp->cmd, mini->change, &flag, envp);
		if (!ft_strcmp(tmp->cmd[0], "export"))
			mini_export(&mini->list, tmp->cmd, &flag);
		if (!ft_strcmp(tmp->cmd[0], "unset"))
			mini_unset(&mini->list, tmp->cmd, &flag);
		if (!ft_strcmp(tmp->cmd[0], "env"))
			mini_env(mini->list, &flag);
		if (!ft_strcmp(tmp->cmd[0], "exit"))
			mini_exit(tmp->cmd[1], &flag);
		if (!ft_strcmp(tmp->cmd[0], "history"))
			mini_history(mini->history, &flag);
		if (!ft_strncmp(tmp->cmd[0], "$?", 2))
			mini_dq(tmp->cmd[0], &flag);
		if (!ft_strncmp(tmp->cmd[0], "./minishell", 2))
			mini_shlvl(&mini, envp, &flag);
		tmp = tmp->next;
	}
	return (flag);
}
