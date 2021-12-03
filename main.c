/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:54 by jobject           #+#    #+#             */
/*   Updated: 2021/12/03 20:28:45 by jobject          ###   ########.fr       */
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

void	actions(int signal_num, siginfo_t *info, void *old_info)
{
	(void)old_info;
	(void)info;
	if (signal_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
        rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal_num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}	
}

int main(int argc, char	**argv, char	**envp)
{
	(void) argc;
	(void) argv;
	t_list	*lst;
	t_lst	*list;
	t_list	*tmp;
	t_list	*history;
	t_cmd	cmds;
	int		in;
	int		out;
	t_proccess	proc;
	int			i;
	int			j;
	char		*strs[10000];
	struct sigaction	sig;
	bool		flag;
	int			status;
	
	i = 0;
	list = envp_copy(envp);
	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	sig.sa_sigaction = actions;
	sig.sa_flags = SA_SIGINFO;
	while (1)
	{
		j = 0;
		flag = false;
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		sigaction(SIGQUIT, &sig, NULL);
		sigaction(SIGINT, &sig, NULL);
		strs[i] = readline("\033[1;36mminishell $> ");
		if (!strs[i])
		{
			write(2, "exit\n", 5);
			exit(0);
		}
		while (strs[i][j] && strs[i][j] == ' ')
			j++;
		if (!strs[i][j])
			continue ;
		if (ft_strcmp(strs[i], "history"))
			history = make_history(strs[i], history);
		add_history(strs[i]);
		strs[i] = parser(strs[i], envp);
		if (!strs[i])
			continue ;
		j = 0;
		lst = do_split(strs[i]);
		i++;
		tmp = lst;
		while (tmp)
		{
			// tmp->content = parser(tmp->content, envp);
			tmp->cmd = ft_split(tmp->content, ' ');
			tmp = tmp->next;
		}
		tmp = lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->cmd[0], "pwd"))
			{
				mini_pwd();
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "cd"))
			{
				mini_cd(tmp->cmd[1], &list);
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "echo"))
			{
				mini_echo(tmp->cmd);
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "export"))
			{
				mini_export(&list, tmp->cmd);
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "unset"))
			{
				mini_unset(&list, tmp->cmd);
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "env"))
			{
				mini_env(list);
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "exit"))
			{
				mini_exit(lst->cmd[0]);
				flag = true;
			}
			else if (!ft_strcmp(tmp->cmd[0], "history"))
			{
				mini_history(history);
				flag = true;
			}
			if (flag)
				status = WEXITSTATUS(status);
			tmp = tmp->next;
		}
		if (!flag)
			run(&cmds, envp, &proc, lst);
		ft_lstclear(&lst, free);
	}
	// ft_lstclear_rem(&list, del);
	return (0);
}
