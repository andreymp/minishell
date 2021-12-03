/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:04:40 by jobject           #+#    #+#             */
/*   Updated: 2021/12/03 21:02:43 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*free_fd(char	*str, char *filename, int j, int i)
{
	char	*res;
	char	*tmp;
	
	res = ft_substr(str, 0, i);
	tmp = ft_strdup(str + ft_strlen(filename) + j);
	res = ft_strjoin(res, tmp);
	free (tmp);
	free (filename);
	free (str);
	return(res);
}

char	*get_filename(char	*str, int i, int *j)
{
	while (*(str + i) && *(str + i) == ' ' )
		i++;
	if (!*(str + i))
		return (NULL);
	*j = i;
	while (*(str + i) && *(str + i) != ' ')
		i++;
	return (ft_substr(str, *j, i - *j));	
}

bool	ft_iskey(char c)
{
	return (c == '_' || (bool) ft_isalnum((int) c));
}

char	*multi_join(char	*str, int i, int j)
{
	char	*tmp1;
	char	*tmp2;
	char	*res;

	res = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, i - j - 1);
	tmp2 = ft_strdup(str + i + 1);
	free(str);
	res = ft_strjoin(res, tmp1);
	free(tmp1);
	res = ft_strjoin(res, tmp2);
	free(tmp2);
	return (res);
}

char	*multi_join2(char	*s1, char	*s2, int i, int j)
{
	char	*res;
	char	*tmp;

	res = ft_substr(s1, 0, j);
	tmp = ft_strdup(s1 + i);
	free(s1);
	res = ft_strjoin(res, s2);
	i = ft_strlen(res);
	res = ft_strjoin(res, tmp);
	free(s2);
	free(tmp);
	return (res);
}
