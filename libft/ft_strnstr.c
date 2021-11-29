/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:21 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:04:21 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char	*little, size_t	len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;
	size_t	j;

	ptr1 = (char *) big;
	ptr2 = (char *) little;
	i = 0;
	if (!(*ptr2))
		return (ptr1 + i);
	while (*(ptr1 + i) && i < len)
	{
		if (*(ptr1 + i) == *ptr2)
		{
			j = 0;
			while (*(ptr1 + i + j) == *(ptr2 + j) && i + j < len)
				j++;
			if (*(ptr2 + j) == '\0')
				return (ptr1 + i);
		}
		i++;
	}
	return (0);
}
