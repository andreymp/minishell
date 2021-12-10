/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:00:36 by remelia           #+#    #+#             */
/*   Updated: 2021/12/10 15:55:47 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	wait_func(t_mini	*mini, int size)
{
	close(mini->proc.fdout);
	close(mini->proc.fdin);
	while (size--)
		waitpid(-1, &g_sig.ex_code, 0);
}

t_lst	*envp_copy(char *envp[])
{
	t_lst	*list;
	int		i;

	i = 0;
	list = NULL;
	while (envp[i])
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

static void	special_free(t_mini	*mini)
{
	t_list	*tmp;

	tmp = mini->lst;
	while (tmp)
	{
		free_mem(tmp->cmd);
		tmp = tmp->next;
	}
	ft_lstclear(&mini->lst, free);
}

void	minishell(t_mini	*mini, char	**envp, char	*strs[])
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (1)
	{
		dup2(mini->cmds.in, STDIN_FILENO);
		dup2(mini->cmds.out, STDOUT_FILENO);
		sigaction(SIGQUIT, &mini->sig, NULL);
		sigaction(SIGINT, &mini->sig, NULL);
		strs[++i] = readline(MINISHELL"minishell $> "TEXT);
		if (!result_line(&strs[i], &mini->history, mini))
			continue ;
		mini->lst = do_split(strs[i]);
		free(strs[i]);
		tmp = mini->lst;
		while (tmp)
		{
			tmp->content = insert_inside_gap2(mini->change, tmp->content);
			tmp = tmp->next;
		}
		make_split(&mini->lst);
		exec(mini, envp);
		special_free(mini);
	}
}
