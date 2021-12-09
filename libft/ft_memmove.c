/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:22 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:03:23 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t	num)
{
	char	*to;
	char	*from;

	from = (char *) src;
	to = (char *) dest;
	if (!to && !from)
		return (0);
	if (to < from)
		ft_memcpy(dest, src, num);
	else
	{
		while (num--)
			*(to + num) = *(from + num);
	}
	return (dest);
}
