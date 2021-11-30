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

int	main(int argc, char *argv[], char *envp[])
{
	char	*str[10000];
	int		i;
	t_list	*list;

	
	(void)argc;
	(void)argv;
	i = 0;
	list = envp_copy(envp);
	while (1)
	{
		write(1, "minishell> ", 11);
		str[i] = readline(NULL);			// readline не ставит '\0' на конец строки поэтому ft_putstr_fd поменял немного)
		add_history(str[i]);
		mini_env(list);
		mini_export(&list, str[i]);
		write(1, "\n\n\n", 3);
		mini_env(list);
		i++;
	}
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	return (0);
}