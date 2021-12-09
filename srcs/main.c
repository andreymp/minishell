/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:54 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 20:32:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_mem(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	actions(int signal_num, siginfo_t __unused *info,
	void __unused *old_info)
{
	int	i;

	i = -1;
	if (signal_num == SIGINT)
	{
		g_sig.ex_code = 130;
		ft_putstr_fd("\b\b\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		if (!g_sig.pid)
			rl_redisplay();
	}
	else if (signal_num == SIGQUIT)
	{
		ft_putstr_fd("\b\b", 1);
		rl_on_new_line();
		if (!g_sig.pid)
			rl_redisplay();
		else
		{
			ft_putendl_fd("Quit: 3", 1);
			g_sig.ex_code = 131;
		}
	}
}

t_mini	*zero_init(char	**envp)
{
	t_mini	*mini;

	mini = (t_mini *) malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->change.red_in = 1;
	mini->change.red_out = 2;
	mini->change.pipe = 3;
	mini->change.point_coma = 4;
	mini->change.tilda = 5;
	mini->change.gap = 6;
	mini->list = envp_copy(envp);
	mini->cmds.in = dup(STDIN_FILENO);
	mini->cmds.out = dup(STDOUT_FILENO);
	mini->sig.sa_sigaction = actions;
	mini->sig.sa_flags = SA_SIGINFO;
	mini->history = NULL;
	mini->lst = NULL;
	mini->shlvl = 1;
	return (mini);
}

int	main(int __unused argc, char __unused **argv, char	**envp)
{
	t_mini		*mini;
	char		*strs[10000];

	g_sig.ex_code = 0;
	mini = zero_init(envp);
	if (!mini)
		return (1);
	minishell(mini, envp, strs);
	ft_lstclear_rem(&mini->list, del);
	free(mini);
	return (0);
}
