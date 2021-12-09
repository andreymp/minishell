/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 21:29:26 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	make_split(t_list	**lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp->cmd = ft_split(tmp->content, ' ');
		tmp = tmp->next;
	}
}

t_list	*do_split(char	*str)
{
	t_list	*lst;
	char	**strs;
	int		i;

	i = 0;
	lst = NULL;
	strs = ft_split(str, '|');
	while (strs[i])
	{
		if (!lst)
			lst = ft_lstnew(strs[i]);
		else
			ft_lstadd_back(&lst, ft_lstnew(strs[i]));
		i++;
	}
	return (lst);
}

bool	preparser(char	*str)
{
	int		i;
	t_pre	gaps;

	gaps.gap2 = 0;
	gaps.gap = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '\'')
			gaps.gap++;
		if (*(str + i) == '\"')
			gaps.gap2++;
		i++;
	}
	if (gaps.gap % 2 || gaps.gap2 % 2)
		return (false);
	return (true);
}

char	*parser(char	*str, t_mini	*mini, int i, int flag)
{
	if (!pre_check(str))
		return (NULL);
	while (*(str + i))
	{
		if (*(str + i) == '\'')
		{
			while (*(str + i) == '\'')
			{
				flag++;
				str = do_gap(str, i);
			}
		}
		else if (*(str + i) == '\"' && flag % 2 == 0)
			while (*(str + i) == '\"')
				str = do_gap2(str, i, mini->list, mini->change);
		else if (*(str + i) == '$' && ft_strncmp("$?", str + i, 2)
			&& ft_strcmp(str + i, "$") && !was_heredoc(str) && flag % 2 == 0)
			while (*(str + i) == '$')
				str = do_dollar(str, i, mini->list);
		else if (*(str + i) == '\\' || *(str + i) == ';')
			return (return_message(str));
		else
			i++;
	}
	return (after_check(str));
}

bool	result_line(char	**str, t_list	**history, t_mini	*mini)
{
	int	i;

	if (!*str)
	{
		ft_putstr_fd("exit\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (**str != '\0' && (**str == ' ' || **str == '\t'))
		(*str)++;
	if (!*str[i])
		return (false);
	*history = make_history(*str, *history);
	add_history(*str);
	*str = parser(*str, mini, 0, 0);
	if (!*str)
		return (false);
	i = 0;
	while (str[0][i] && str[0][i] == ' ')
		i++;
	if (!str[0][i])
		return (false);
	return (true);
}
