/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:54 by jobject           #+#    #+#             */
/*   Updated: 2021/12/02 19:21:01 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "pipe.h"

void	free_mem(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int main(int argc, char	**argv, char	**envp)
{
	(void) argc;
	(void) argv;
	t_list	*lst;
	t_lst	*list;
	t_list	*tmp;
	t_cmd	cmds;
	t_proccess	proc;
	int			i;
	int			j;
	char		*strs[10000];
	bool		flag;
	
	i = 0;
	list = envp_copy(envp);
	while (1)
	{
		flag = false;
		strs[i] = readline("minishell $> ");
		j = 0;
		while (strs[i][j] == ' ')
			j++;
		if (!strs[i][j])
			continue ;
		if (!ft_strncmp(strs[i], "exit", 4))
			mini_exit(strs[i]);
		lst = do_split(strs[i]);
		tmp = lst;
		while (tmp)
		{
			tmp->content = parser(tmp->content, envp);
			tmp->cmd = ft_split(tmp->content, ' ');
			tmp = tmp->next;
		}
		tmp = lst;
		while (tmp)
		{
			if (!ft_strncmp(tmp->cmd[0], "pwd", 3))
			{
				mini_pwd();
				flag = true;
			}
			else if (!ft_strncmp(tmp->cmd[0], "cd", 2))
			{
				mini_cd(tmp->cmd[1], &list);
				flag = true;
			}
			else if (!ft_strncmp(tmp->cmd[0], "echo", 4))
			{
				mini_echo(tmp->cmd);
				flag = true;
			}
			else if (!ft_strncmp(tmp->cmd[0], "export", 6))
			{
				mini_export(&list, tmp->cmd[1]);
				flag = true;
			}
			else if (!ft_strncmp(tmp->cmd[0], "unset", 5))
			{
				mini_unset(&list, tmp->cmd[1]);
				flag = true;
			}
			else if (!ft_strncmp(tmp->cmd[0], "env", 3))
			{
				mini_env(list);
				flag = true;
			}
			tmp = tmp->next;
		}
		if (!flag)
			run(&cmds, envp, &proc, lst);
		// add_history(strs[i]);
		ft_lstclear(&lst, free);
		i++;
	}
	return (0);
}
