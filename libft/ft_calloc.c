/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:49:27 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 13:49:45 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	void	*res;

	res = (void *) malloc(nmemb * size);
	if (res)
	{
		ft_bzero(res, nmemb * size);
		return (res);
	}
	return (0);
}
