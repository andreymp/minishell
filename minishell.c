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
	else if (signal_num == EOF)
	{
		write(2, "exit", 4);
		exit(0);
	}
		
}

int	main(int argc, char *argv[], char *envp[])
{
	char				*str[10000];
	int					i;
	t_list				*list;
	int					ex_code;
	struct sigaction	sig;
	
	char	*test[5];
	test[4] = NULL;
	(void)argc;
	(void)argv;
	i = 0;
	ex_code = 0;
	list = envp_copy(envp);
	sig.sa_sigaction = actions;
	sig.sa_flags = SA_SIGINFO;
	while (1)
	{
		//str[i] = readline("minishell> ");
		sigaction(SIGINT, &sig, NULL);
		sigaction(SIGQUIT, &sig, NULL);
		sigaction(EOF, &sig, NULL);
		str[i] = readline("minishell> ");
		add_history(str[i]);
		test[i] = str[i];
		if (i > 2)
		//{
		//	mini_env(list);
		//	write(1, "\n\n", 2);
		//	mini_export(&list, test);
		//	mini_env(list);
		//	write(1, "\n\n", 2);
		//	mini_unset(&list, test);
		//	mini_env(list);
		//}
		//ex_code = mini_echo(str[i], 0, ex_code);
		i++;
	}
	return (0);
}