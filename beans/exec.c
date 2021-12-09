/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:41:48 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 20:07:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	exec(t_mini	*mini, char	**envp)
{
	bool	flag;

	while (mini->lst)
	{
		flag = false;
		if (!ft_strcmp(mini->lst->cmd[0], "pwd"))
			mini_pwd(&flag);		
		else if (!ft_strcmp(mini->lst->cmd[0], "cd"))
			mini_cd(mini->lst->cmd[1], &mini->list, &flag);
		else if (!ft_strcmp(mini->lst->cmd[0], "echo"))
			mini_echo(mini->lst->cmd, mini->change, &flag, envp);
		else if (!ft_strcmp(mini->lst->cmd[0], "export"))
			mini_export(&mini->list, mini->lst->cmd, &flag);
		else if (!ft_strcmp(mini->lst->cmd[0], "unset"))
			mini_unset(&mini->list, mini->lst->cmd, &flag);
		else if (!ft_strcmp(mini->lst->cmd[0], "env"))
			mini_env(mini->list, &flag);
		else if (!ft_strcmp(mini->lst->cmd[0], "exit"))
			mini_exit(mini->lst->cmd[1], &flag);
		else if (!ft_strcmp(mini->lst->cmd[0], "history"))
			mini_history(mini->history, &flag);
		else if (!ft_strncmp(mini->lst->cmd[0], "$?", 2))
			mini_dq(mini->lst->cmd[0], &flag);
		else if (!ft_strcmp(mini->lst->cmd[0], "./minishell"))
		{
			mini_shlvl(&mini, envp, &flag);
			run(&mini->cmds, &mini->proc, mini, envp);
		}
		else
			run(&mini->cmds, &mini->proc, mini, envp);
		if (mini->proc.fdin > 0)
			dup2(mini->cmds.in, STDIN_FILENO);
		if (mini->proc.fdout > 0)
			dup2(mini->cmds.out, STDOUT_FILENO);
		mini->lst = mini->lst->next;
	}
	return (true);
}
