/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:19 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:03:20 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	num)
{
	char	*to;
	char	*from;

	to = (char *) dest;
	from = (char *) src;
	if (!to && !from)
		return (0);
	while (num--)
		*to++ = *from++;
	return (dest);
}
