/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:00:36 by remelia           #+#    #+#             */
/*   Updated: 2021/11/17 14:00:39 by remelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*envp_copy(char *envp[])
{
	t_list	*list = NULL;
	int		i;

	i = 0;
	while(envp[i] != '\0')
	{
		ft_lstadd_back(&list, ft_lstnew(envp[i]));
		i++;
	}
	return (list);
}

void	actions(int signal_num, siginfo_t *info, void *old_info)
{
	int	i;
	
	i = 0;
	(void)old_info;
	(void)info;
	if (signal_num == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
        rl_redisplay();
	}
	else if (signal_num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}	
}

int	main(int argc, char *argv[], char *envp[])
{
	char				*str[10000];
	int					i;
	t_list				*list;
	int					ex_code;
	struct sigaction	sig;
	
	char	*test[3];
	test[2] = NULL;
	(void)argc;
	(void)argv;
	i = 0;
	ex_code = 130;
	list = envp_copy(envp);
	sig.sa_sigaction = actions;
	sig.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGINT, &sig, NULL);
		sigaction(SIGQUIT, &sig, NULL);
		sigaction(EOF, &sig, NULL);
		str[i] = readline("minishell> ");
		if (str[i] == NULL)					// ctrl-D fix
		{
			write(2, "exit\n", 5);
			exit(0);
		}
		add_history(str[i]);
		dollar(str[i], ex_code);
		//ex_code = mini_echo(str[i], 0, ex_code);
		i++;
	}
	return (0);
}