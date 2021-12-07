/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:00:36 by remelia           #+#    #+#             */
/*   Updated: 2021/12/07 20:46:37 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

static char	*insert_inside_gap2(t_inside_gap_2	change, char	*str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
	{
		if (*(str + i) == change.pipe)
			*(str + i) = '|';
		else if (*(str + i) == change.red_in)
			*(str + i) = '<';
		else if (*(str + i) == change.red_out)
			*(str + i) = '>';
		else if (*(str + i) == change.point_coma)
			*(str + i) = ';';
		else if (*(str + i) == change.tilda)
			*(str + i) = '~';
		else if (*(str + i) == change.gap)
			*(str + i) = '\'';
	}
	return (str);
}

void	minishell(t_mini	*mini, char	**envp, char	*strs[])
{
	int	i;

	i = -1;
	while (1)
	{
		dup2(mini->cmds.in, STDIN_FILENO);
		dup2(mini->cmds.out, STDOUT_FILENO);
		sigaction(SIGQUIT, &mini->sig, NULL);
		sigaction(SIGINT, &mini->sig, NULL);
		strs[++i] = readline(MINISHELL"minishell $> "TEXT);
		if (!result_line(&strs[i], &mini->history, mini->list, mini->change))
			continue ;
		strs[i] = insert_inside_gap2(mini->change, strs[i]);
		mini->lst = do_split(strs[i]);
		make_split(&mini->lst);
		if (!exec(mini->lst, mini->list, mini->change, mini->history, envp))
			run(&mini->cmds, mini->list, &mini->proc, mini->lst, envp);
		ft_lstclear(&mini->lst, free);
	}
}