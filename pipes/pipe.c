/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:36:45 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 20:29:14 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	check_pipes(char	*str)
{
	int		i;
	t_pre	pip;

	i = -1;
	pip.pipes = 0;
	while (*(str + ++i))
	{
		if (*(str + i) == '|')
			pip.pipes++;
	}
	if (pip.pipes != get_size_pipes(str, '|') - 1 && pip.pipes != 0)
		return (false);
	return (true);
}

static void	child(t_cmd	*cmds, char	**envp, t_proccess	**proc)
{
	dup2((*proc)->fds[1], STDOUT_FILENO);
	close((*proc)->fds[0]);
	close((*proc)->fds[1]);
	execve(cmds->cmd_path, cmds->lst->cmd, envp);
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

void	run(t_cmd	*cmds, t_lst	*list, t_proccess	*proc, t_list	*lst, char	**envp)
{
	int	size;

	size = ft_lstsize(lst);
	if (!init_env(list, cmds))
		return ;
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
	proc->parent = fork();
	if (!proc->parent)
		execve(cmds->cmd_path, cmds->lst->cmd, envp);
	else
		while (size--)
	 		waitpid(proc->parent, &g_exit, 0);
	g_exit = WEXITSTATUS(g_exit);
}