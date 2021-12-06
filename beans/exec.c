/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:41:48 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 18:43:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	exec(t_list	*tmp, t_lst	*list, t_inside_gap_2	change, t_list	*history, char	**envp)
{
	bool	flag;

	while (tmp)
	{
		flag = false;
		if (!ft_strcmp(tmp->cmd[0], "pwd"))
			mini_pwd(&flag);		
		if (!ft_strcmp(tmp->cmd[0], "cd"))
			mini_cd(tmp->cmd[1], &list, &flag);
		if (!ft_strcmp(tmp->cmd[0], "echo"))
			mini_echo(tmp->cmd, change, &flag, envp);
		if (!ft_strcmp(tmp->cmd[0], "export"))
			mini_export(&list, tmp->cmd, &flag);
		if (!ft_strcmp(tmp->cmd[0], "unset"))
			mini_unset(&list, tmp->cmd, &flag);
		if (!ft_strcmp(tmp->cmd[0], "env"))
			mini_env(list, &flag);
		if (!ft_strcmp(tmp->cmd[0], "exit"))
			mini_exit(tmp->cmd[0], &flag);
		if (!ft_strcmp(tmp->cmd[0], "history"))
			mini_history(history, &flag);
		tmp = tmp->next;
	}
	return (flag);
}
