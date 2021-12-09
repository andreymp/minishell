/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:24:18 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 21:34:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*do_gap(char	*str, int i)
{
	int	j;

	j = i;
	i++;
	while (*(str + i))
		i++;
	return (multi_join(str, i, j));
}

char	*do_dollar(char	*str, int i, t_lst	*list)
{
	char	*res;
	char	*tmp;
	int		j;
	int		c;

	j = i++;
	res = NULL;
	if (!dollar_valid(str, &i, j))
		return (str);
	tmp = ft_substr(str, j + 1, i - j - 1);
	c = -1;
	while (list)
	{
		if (!ft_strncmp(list->var, tmp, ft_strlen(tmp))
			&& *(list->var + ft_strlen(tmp)) == '=')
			break ;
		list = list->next;
	}
	if (list)
	{
		res = ft_strdup(list->var + ft_strlen(tmp) + 1);
		free(tmp);
		return (multi_join2(str, res, i, j));
	}
	return (dollar_join(tmp, str, i, j));
}

bool	was_heredoc(char	*str)
{
	int	i;

	i = 0;
	while (*(str + i + 1))
	{
		if ((*(str + i) == '<' && *(str + i + 1) == '<')
			|| (*(str + i) == 1 && *(str + i + 1) == 1))
			break ;
		i++;
	}
	if (*(str + i + 1))
	{
		i += 2;
		while (*(str + i) && *(str + i) != '$'
			&& (*(str + i) == ' ' || *(str + i) == '\"'))
			i++;
		if (*(str + i) && *(str + i) == '$')
			return (true);
	}
	return (false);
}

char	*do_gap2(char	*str, int i, t_lst	*list, t_inside_gap_2 change)
{
	int	j;

	j = i;
	i++;
	while (*(str + i) && *(str + i) != '\"')
	{
		if (*(str + i) == '$' && !was_heredoc(str))
			str = do_dollar(str, i, list);
		if (*(str + i) == '|')
			*(str + i) = change.pipe;
		if (*(str + i) == '<')
			*(str + i) = change.red_in;
		if (*(str + i) == '>')
			*(str + i) = change.red_out;
		if (*(str + i) == ';')
			*(str + i) = change.point_coma;
		if (*(str + i) == '~')
			*(str + i) = change.tilda;
		if (*(str + i) == '\'')
			*(str + i) = change.gap;
		i++;
	}
	return (multi_join(str, i, j));
}
