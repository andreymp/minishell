/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:24:18 by jobject           #+#    #+#             */
/*   Updated: 2021/11/30 20:11:44 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*do_gap(char	*str, int	*i)
{
	int	j;

	j = *i;
	(*i)++;
	while (*(str + *i) && *(str + *i) != '\'')
		(*i)++;
	return (multi_join(str, *i, j));
}

char	*do_backslash(char	*str, int *i)
{
	char	*res;
	char	*tmp;

	res = ft_substr(str, 0 ,*i);
	tmp = ft_strdup(str + *i + 1);
	res = ft_strjoin(res, tmp);
	free(tmp);
	free(str);
	return (res);
}

char	*do_dollar(char	*str, int	*i, char	**envp)
{
	char	*res;
	char	*tmp;
	int		j;
	int		c;

	j = *i;
	(*i)++;
	res = NULL;
	while (*(str + *i) && ft_iskey(*(str + *i)))
		(*i)++;
	if (*i == j + 1 || ft_isdigit((int) *(str + j + 1)))
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
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
	return (str);
}

char	*do_gap2(char	*str, int *i, char	**envp)
{
	int	j;

	j = *i;
	(*i)++;
	while (*(str + *i) && *(str + *i) != '\"')
	{
		if (*(str + *i) == '\\' && (*(str + *i + 1) == '\"'
			|| *(str + *i + 1) == '$'))
			str = do_backslash(str, i);
		else if (*(str + *i) == '$')
			do_dollar(str, i, envp);
		(*i)++;
	}
	return (multi_join(str, *i, j));
}
