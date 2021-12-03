/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:00:36 by remelia           #+#    #+#             */
/*   Updated: 2021/12/03 17:16:20 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*envp_copy(char *envp[])
{
	t_lst	*list = NULL;
	int		i;

	i = 0;
	while(envp[i])
	{
		ft_lstadd_back_rem(&list, ft_lstnew_rem(envp[i]));
		i++;
	}
	return (list);
}

// void	actions(int signal_num, siginfo_t *info, void *old_info)
// {
// 	int	i;

// 	i = 0;
// 	(void)old_info;
// 	(void)info;
// 	if (signal_num == SIGINT)
// 		write(1, "\nminishell> ", 13);
// 	else if (signal_num == SIGQUIT)
// 		return ;
// }
//
//void	sig_create(struct sigaction *sig)
//{
//	sig->sa_sigaction = actions;
//	sig->sa_flags = SA_SIGINFO;
//}
//
//int	sig_def(struct sigaction sig)
//{
//	sigaction(SIGKILL, &sig, NULL);
//	sigaction(SIGHUP, &sig, NULL);
//	sigaction(SIGINT, &sig, NULL);
//	return (0);
//}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char				*str[10000];
// 	int					i;
// 	t_list				*list;
// 	int					ex_code;
// 	struct sigaction	sig;
	
// 	(void)argc;
// 	(void)argv;
// 	i = 0;
// 	ex_code = 0;
// 	list = envp_copy(envp);
// 	//while (1)
// 	//{
// 	//	write(1, "minishell> ", 11);
// 	//	str[i] = readline(NULL);			// readline не ставит '\0' на конец строки поэтому ft_putstr_fd поменял немного)
// 	//	sig_def(sig);
// 	//	add_history(str[i]);
// 	//	ex_code = mini_echo(str[i], 0, ex_code);
// 	//	i++;
// 	//}
// 	sig.sa_sigaction = actions;
// 	sig.sa_flags = SA_SIGINFO;
// 	while (1)
// 	{
// 		write(1, "minishell> ", 11);
// 		sigaction(SIGINT, &sig, NULL);
// 		sigaction(SIGQUIT, &sig, NULL);
// 		str[i] = readline(NULL);
// 		add_history(str[i]);
// 		if (ft_strncmp(str[i], "exit", 4) == 0)
// 			mini_exit(str[i]);
// 		//ex_code = mini_echo(str[i], 0, ex_code);
// 		i++;
// 	}
// 	return (0);
// }