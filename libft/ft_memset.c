/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:27 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 15:27:12 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*source, int code, size_t	length)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *) source;
	while (i < length)
	{
		*(str + i) = (unsigned char) code;
		i++;
	}
	return (source);
}
