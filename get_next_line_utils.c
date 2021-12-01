/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:56:06 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 13:17:28 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(const char	*str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	*ft_memcpygnl(void	*dest, const void	*src, size_t	num)
{
	char	*to;
	char	*from;

	to = (char *) dest;
	from = (char *) src;
	if (!to || !from)
		return (0);
	while (num--)
		*to++ = *from++;
	*to = '\0';
	return (dest);
}

void	*ft_memmovegnl(void	*dest, const void	*src, size_t	num)
{
	char	*to;
	char	*from;

	from = (char *) src;
	to = (char *) dest;
	if (!to && !from)
		return (0);
	if (to < from)
		ft_memcpygnl(dest, src, num);
	else
	{
		while (num--)
			*(to + num) = *(from + num);
	}
	return (dest);
}

char	*ft_strjoingnl(char	*s1, char const	*s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char));
		*s1 = '\0';
	}
	len1 = ft_strlengnl(s1);
	len2 = ft_strlengnl(s2);
	str = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (str)
	{
		ft_memcpygnl(str, s1, len1);
		ft_memmovegnl(str + len1, s2, len2);
		*(str + len1 + len2) = '\0';
	}
	free((char *) s1);
	return (str);
}
