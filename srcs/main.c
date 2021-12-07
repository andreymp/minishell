/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:54 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 18:11:01 by jobject          ###   ########.fr       */
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

void	actions(int signal_num, siginfo_t __unused *info, void __unused *old_info)
{
	// (void)old_info;
	// (void)info;
	if (signal_num == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
        rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal_num == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
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
	return (mini);
}

int main(int __unused argc, char	__unused **argv, char	**envp)
{
	t_mini		*mini;
	char		*strs[10000];
	
	// (void) argc;
	// (void) argv;
	g_exit = 0;
	mini = zero_init(envp);
	if (!mini)
		return (1);
	minishell(mini, envp, strs);
	ft_lstclear_rem(&mini->list, del);
	free(mini);
	return (0);
}
