/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:36:45 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 17:51:27 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

static void	child(t_cmd	*cmds, char	**envp, t_proccess	**proc)
{
	dup2((*proc)->fds[1], STDOUT_FILENO);
	close((*proc)->fds[0]);
	close((*proc)->fds[1]);
	execve(cmds->cmd_path, cmds->lst->cmd, envp);
	exit(EXIT_FAILURE);
}

static void	parents(t_proccess	**proc)
{
	dup2((*proc)->fds[0], STDIN_FILENO);
	close((*proc)->fds[1]);
	close((*proc)->fds[0]);
}

static void	pipex(t_cmd	*cmds, char	**envp, t_proccess	*proc)
{
	pipe(proc->fds);
	proc->parent = fork();
	if (!proc->parent)
		child(cmds, envp, &proc);
	else
		parents(&proc);
}

void	run(t_cmd	*cmds, char	**envp, t_proccess	*proc, t_list	*lst)
{
	t_list	*tmp;

	tmp = lst;
	init_env(envp, cmds);
	while (lst->next)
	{
		cmds->lst = lst;
		init_cmd_path(&cmds);
		if (!cmds->cmd_path)
			return ;
		pipex(cmds, envp, proc);
		free(cmds->cmd_path);
		lst = lst->next;
	}
	cmds->lst = lst;
	init_cmd_path(&cmds);
	if (!cmds->cmd_path)
		return ;
	execve(cmds->cmd_path, cmds->lst->cmd, envp);
	while (tmp->next)
	{
		waitpid(0, NULL, 0);
		tmp = tmp->next;
	}
}