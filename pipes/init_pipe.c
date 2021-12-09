/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:20:27 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 15:44:24 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*double_join(char	*s1, char	*s2)
{
	char	*temp1;
	char	*res;

	temp1 = ft_strjoin(s1, "/");
	res = ft_strjoin(temp1, s2);
	return (res);
}

void	init_cmd_path(t_cmd	**cmds)
{
	int		i;

	i = 0;
	if (!access((*cmds)->lst->cmd[0], F_OK))
	{
		(*cmds)->cmd_path = ft_strdup((*cmds)->lst->cmd[0]);
		return ;
	}
	while ((*cmds)->mypaths[i])
	{
		(*cmds)->cmd_path = double_join((*cmds)->mypaths[i], (*cmds)->lst->cmd[0]);
		if (!access((*cmds)->cmd_path, F_OK))
			break ;
		free((*cmds)->cmd_path);
		(*cmds)->cmd_path = NULL;
		i++;
	}
	if (!(*cmds)->mypaths[i])
	{
		ft_putstr_fd(ERROR"minishell: command not found: "TEXT, 2);
		ft_putendl_fd((*cmds)->lst->cmd[0], 2);
		g_exit = 127;
	}
}

bool	init_env(t_lst	*list, t_cmd	*cmds)
{
	int		i;

	i = 0;
	while (list && ft_strncmp("PATH", list->var, ft_strlen("PATH")))
		list = list->next;
	if (list)
		cmds->mypaths = ft_split(list->var + 5, ':');
	else
	{
		ft_putendl_fd(ERROR"minishell: PATH not found"TEXT, 2);
		g_exit = 127;
		return (false);
	}
	return (true);
}
