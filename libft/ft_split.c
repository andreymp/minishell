/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:53 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 15:54:54 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_size(char const	*s, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			size++;
		while (*(s + i) != c && *(s + i))
			i++;
		if (*(s + i))
			i++;
	}
	size++;
	return (size);
}

char	**filler(const char	*s, char c, char	**strs)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	while (*(s + i))
	{
		len = 0;
		while (*(s + i) && *(s + i) == c)
			i++;
		while (*(s + i) && *(s + i) != c)
		{
			len++;
			i++;
		}
		if (len > 0)
			strs[j++] = ft_substr(s, i - len, len);
		if (*(s + i))
			i++;
	}
	return (strs);
}

char	**ft_split(char const	*s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = (char **) ft_calloc(get_size(s, c), sizeof(char *));
	if (!strs)
		return (0);
	filler(s, c, strs);
	return (strs);
}
