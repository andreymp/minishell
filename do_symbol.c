/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:24:18 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 21:34:55 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*do_gap(char	*str, int	i)
{
	int	j;

	j = i;
	i++;
	while (*(str + i) && *(str + i) != '\'')
		i++;
	return (multi_join(str, i, j));
}

char	*do_dollar(char	*str, int	i, char	**envp)
{
	char	*res;
	char	*tmp;
	int		j;
	int		c;

	j = i;
	i++;
	res = NULL;
	while (*(str + i) && ft_iskey(*(str + i)))
		i++;
	if (i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, i - j - 1);
	c = -1;
	while (envp[++c])
	{
		if (!ft_strncmp(envp[c], tmp, ft_strlen(tmp))
			&& *(envp[c] + ft_strlen(tmp)) == '=')
			break ;
	}
	if (envp[c])
	{
		res = ft_strdup(envp[c] + ft_strlen(tmp) + 1);
		free(tmp);
		return (multi_join2(str, res, i, j));
	}
	free(tmp);
	res = ft_substr(str, 0, j);
	tmp  = ft_strdup(str + i);
	res = ft_strjoin(res, tmp);
	free(tmp);
	free(str);
	return (res);
}

char	*do_gap2(char	*str, int i, char	**envp, t_inside_gap_2 change)
{
	int	j;

	j = i;
	i++;
	while (*(str + i) && *(str + i) != '\"')
	{
		if (*(str + i) == '$')
			str = do_dollar(str, i, envp);
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
		i++;
	}
	return (multi_join(str, i, j));
}
