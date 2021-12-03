/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:24:18 by jobject           #+#    #+#             */
/*   Updated: 2021/12/03 21:19:14 by jobject          ###   ########.fr       */
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
	if (i == j + 1 || ft_isdigit((int) *(str + j + 1)))
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
	return (str);
}

char	*do_gap2(char	*str, int i, char	**envp)
{
	int	j;

	j = i;
	i++;
	while (*(str + i) && *(str + i) != '\"')
	{
		if (*(str + i) == '$')
			str = do_dollar(str, i, envp);
		i++;
	}
	return (multi_join(str, i, j));
}
