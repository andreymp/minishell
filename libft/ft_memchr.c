/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:14 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:09:29 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*str, int code, size_t	n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) str;
	while (i < n)
	{
		if (*(ptr + i) == (char) code)
			return (ptr + i);
		i++;
	}
	return (0);
}
