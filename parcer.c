/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 21:32:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

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
	// free(str);
	while (strs[i])
	{
		if (!lst)
			lst = ft_lstnew(strs[i]);
		else
			ft_lstadd_back(&lst, ft_lstnew(strs[i]));
		i++;
	}
	// free (strs);
	return (lst);
}

static bool	preparser(char	*str)
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

char	*parser(char	*str, char	**envp, t_inside_gap_2 change)
{
	int	i;
	
	i = -1;
	if (!preparser(str))
	{
		ft_putendl_fd("Parsing error", 2);
		return (NULL);
	}
	if (!ft_strncmp(str, "\"\"", 2) || !ft_strncmp(str, "\'\'", 2))
		return (NULL);
	while (*(str + ++i) && str)
	{
		if (*(str + i) == '\'')
			str = do_gap(str, i);
		else if (*(str + i) == '\"')
			str = do_gap2(str, i, envp, change);
		else if (*(str + i) == '$')
			str = do_dollar(str, i, envp);
		else if (*(str + i) == '\\' || *(str + i) == ';')
		{
			free(str);
			ft_putendl_fd(ERROR"Parsing error"TEXT, 2);
			return (NULL);
		}
	}
	if (!str)
		return (NULL);
	str = redirect(str);
	return (str);
}

bool	result_line(char	**str, t_list	**history, char	**envp, t_inside_gap_2 change)
{
	int	i;

	if (!*str)
	{
		rl_replace_line("exit", 0);
		rl_redisplay();
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (*str[i] && (*str[i] == ' ' || *str[i] == '\t'))
		i++;
	if (!*str[i])
		return (false);
	if (ft_strcmp(*str, "history"))
		*history = make_history(*str, *history);
	add_history(*str);
	*str = parser(*str, envp, change);
	if (!*str)
		return (false);
	i = 0;
	while (*str[i] && *str[i] == ' ')
		i++;
	if (!*str[i])
		return (false);
	return (true);
}
