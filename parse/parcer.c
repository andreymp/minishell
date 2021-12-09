/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 20:20:55 by jobject          ###   ########.fr       */
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

char	*parser(char	*str, t_lst	*list, t_inside_gap_2 change)
{
	int	i;
	int	flag;
	
	i = 0;
	flag = 0;
	if (!preparser(str))
	{
		ft_putendl_fd(ERROR"Parsing error (open gaps)"TEXT, 2);
		return (NULL);
	}
	if (!ft_strncmp(str, "\"\"", 2) || !ft_strncmp(str, "\'\'", 2))
		return (NULL);
	while (*(str + i))
	{
		if (*(str + i) == '\'')
			while (*(str + i) == '\'')
			{
				flag++;
				str = do_gap(str, i);
			}
		else if (*(str + i) == '\"' && flag % 2 == 0)
			while (*(str + i) == '\"')
				str = do_gap2(str, i, list, change);
		else if (*(str + i) == '$' && ft_strncmp("$?", str + i, 2) && ft_strcmp(str + i, "$") && flag % 2 == 0)
			while (*(str + i) == '$')
				str = do_dollar(str, i, list);
		else if (*(str + i) == '\\' || *(str + i) == ';')
		{
			free(str);
			ft_putendl_fd(ERROR"Parsing error (undefined symbol)"TEXT, 2);
			return (NULL);
		}
		else
			i++;
	}
	if (!check_pipes(str))
	{
		free(str);
		ft_putendl_fd(ERROR"Parsing error (pipes)"TEXT, 2);
		return (NULL);
	}
	if (!str)
		return (NULL);
	str = redirect(str);
	return (str);
}

bool	result_line(char	**str, t_list	**history, t_lst	*list, t_inside_gap_2 change)
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
	*str = parser(*str, list, change);
	if (!*str)
		return (false);
	i = 0;
	while (str[0][i] && str[0][i] == ' ')
		i++;
	if (!str[0][i])
		return (false);
	return (true);
}
